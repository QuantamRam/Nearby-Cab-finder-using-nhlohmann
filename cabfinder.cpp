#include <bits/stdc++.h>
using namespace std;

#define lat1d 12.9611159
#define lon1d 77.6362214

#define pi 3.14159265358979323846
#define earth_radius 6371.0

ifstream customer_list("customers.json");
ofstream out("answers.json");

// Function to convert degrees to radians
double degtorad(double deg) {
    return (deg * pi / 180);
}

// Function to calculate distance using Great Circle Distance Formula
double distanceEarth(double lat2d, double lon2d) {
    double lat1, lon1, lat2, lon2, delta_lon, central_ang;

    lat1 = degtorad(lat1d);
    lon1 = degtorad(lon1d);
    lat2 = degtorad(lat2d);
    lon2 = degtorad(lon2d);

    delta_lon = lon2 - lon1;

    // Great Circle Distance formula
    central_ang = acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(delta_lon));
    return (earth_radius * central_ang);
}

// Structure to access and process data from customers.json file
struct json {
    long long int length, i, j, x, y, m, n, f, fi, id[100000];
    char latitude_as_string[1000], longitude_as_string[1000], id_as_string[1000], name[1000];
    double lat2d, lon2d;
    string line;

    // Function to check if distance is less than 50km
    void distance_calculator() {
        if (distanceEarth(lat2d, lon2d) <= 50.0000) {
            id[i] = atoll(id_as_string);
            i++;
            out << "{\"user_id\": " << id[i - 1] << ", \"name\": " << name << "}" << endl;
        }
    }

    // Function to parse the JSON file
    void json_parser() {
        if (customer_list.is_open()) {
            while (getline(customer_list, line)) {
                f = 0; x = 0; y = 0; fi = 0; m = 0; n = 0;
                length = line.size();

                for (j = 0; j < length; j++) {
                    if (line[j] == '"')
                        f++;

                    else if (line[j] == ':')
                        fi++;

                    // To get latitude of the location
                    if (f == 3) {
                        j++;
                        while (line[j] != '"') {
                            latitude_as_string[x] = line[j];
                            x++; j++;
                        }
                        j--; latitude_as_string[x] = '\0';
                    }

                    // To get longitude of the location
                    else if (f == 13) {
                        j++;
                        while (line[j] != '"') {
                            longitude_as_string[y] = line[j];
                            y++; j++;
                        }
                        j--; longitude_as_string[y] = '\0';
                    }

                    // To get id of the cab
                    if (fi == 2) {
                        j += 2;
                        while (line[j] != ',') {
                            id_as_string[m] = line[j];
                            m++; j++;
                        }
                        j--; id_as_string[m] = '\0';
                        fi++;
                    }

                    // To get name of the cab
                    else if (fi == 4) {
                        j += 2;
                        while (line[j] != ',') {
                            name[n] = line[j];
                            n++; j++;
                        }
                        j--; name[n] = '\0';
                        fi++; f += 2;
                    }
                }

                // Convert latitude and longitude from string to double
                lat2d = atof(latitude_as_string);
                lon2d = atof(longitude_as_string);
                distance_calculator();
            }
        }

        // Close the file streams
        customer_list.close();
        out.close();
    }
};

int main() {
    json obj;
    obj.json_parser();
    return 0;
}

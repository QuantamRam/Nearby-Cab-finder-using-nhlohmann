# 🚕 **Cab Finder: Because Who Doesn’t Want a Cab Nearby?** 🚕 

## 📜 **Overview**

Welcome to the **Cab Finder** project, where we combine advanced C++ programming with a sprinkle of sarcasm to locate cabs within a 50 km radius of your current location. 🎯 If you ever wondered how to find cabs without actually calling them (because, you know, that’s just so last century), you’re in the right place! 😎

## 🛠️ **How It Works**

1. **Get Your Coordinates**: 🧭 The project assumes you’re located at a magical latitude of 12.9611159 and longitude of 77.6362214. Because apparently, you live in the tech haven of Bangalore! 🌍

2. **JSON File**: 📄 Provide a `customers.json` file with the coordinates of every cab in the city. Format should be JSON because we like to keep things modern and clean (no XML dinosaurs here!). 🦖

3. **Distance Calculation**: 🌐 Using the Great Circle Distance formula (because simple math is for amateurs), it calculates the distance between you and every cab. If a cab is within 50 km, it gets a spot in the VIP list. 🎉

4. **Output**: 📦 The result is saved in `answer.json` – a fancy file with the user IDs and names of all those cab drivers you might want to call. No more scouring the city for a ride!

## 📋 **How to Run**

1. **Save the Code**: 📜 Save the C++ code as `cabfinder.cpp`. Because who doesn't love saving files? 

2. **Compile**: 🛠️ Open your terminal and run:
   ```sh
   g++ cabfinder.cpp -o cabfinder

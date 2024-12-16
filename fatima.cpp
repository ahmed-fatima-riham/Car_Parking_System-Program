#include <iostream>
#include <string>
using namespace std;
//Variables used in this program
const int TotalC_Slots = 20;
const int TotalB_Slots = 10;
const int TotalT_Slots = 5;
float Car_Price = 10.0, Bike_Price = 5.0, Truck_Price = 15.0;
//Arrays for all vehicle type
int Car_Slots[TotalC_Slots] = {0};
int Bike_Slots[TotalB_Slots] = {0};
int Truck_Slots[TotalT_Slots] = {0};
void display_slots(int slots[], int size, string type){
    cout << endl << type << " Slots:" << endl;
    // loops through the array
    for(int i = 0; i < size; i++){
        cout << "Slot " << (i + 1) << (slots[i] ? ": Occupied" : ": Available") << endl;
    }
}
// displays the free parking slots for all vehicle type
void Display_Availability(){
    display_slots( Car_Slots, TotalC_Slots, "Car");
    display_slots( Bike_Slots, TotalB_Slots, "Bike");
    display_slots(Truck_Slots, TotalT_Slots, "Truck");
}
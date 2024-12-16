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
// function to book a parking slot
void Book_Slot(int slots[], int size, string type, string owner, string plate, float duration, bool valet){
    for(int i = 0; i < size; i++) {
        if(!slots[i]) {
            slots[i] =1;
            cout << endl << type << " slot " << (i + 1) << " has been booked" << endl;
            cout << "Owner: " << owner <<endl << "License Plate: " << plate << endl;
            float rate =(type == "Car" ? Car_Price : type == "Bike" ? Bike_Price : Truck_Price);
            cout << "Duration: " << duration << " hours" << endl << "Total Price: $" << (rate * duration) << endl;
            if(valet) cout << "Valet service activated." << endl;
            return;
        }
    }
    cout << "No available slots for " << type << endl;
}
//function to release a parking slot
void Release_Slot(int slots[], int size, int slotNum, string type) {
    if(slotNum < 1 || slotNum > size || !slots[slotNum - 1]) {
        cout << "Invalid or already available slot in " << type << " section" << endl;
    } else{
        slots[slotNum - 1] = 0;
        cout << "Slot " << slotNum << " in " << type << " section released successfully" << endl;
    }
}
int main() {
    int Choice;
    // loops until the user decides to exit the menu
    do {
        cout << endl << "Parking Management System:" << endl;
        cout << "1. Display All Slots" << endl << "2. Book a Parking Slot" << endl <<"3. Release a Parking Slot" << endl <<"4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> Choice;
        switch(Choice) {
        case 1:
            Display_Availability();
            break;
        case 2: {
            string type, owner, plate;
            float duration;
            int valet;
            cout << "Enter vehicle type (Car/Bike/Truck): ";
            cin >> type;
            cout << "Enter owner name: ";
            cin >> owner;
            cout << "Enter license plate: ";
            cin >> plate;
            cout << "Enter parking duration (hours): ";
            cin >> duration;
            cout << "Do you need Valet Service? (1 for Yes, 0 for No): ";
            cin >> valet;
            if (type == "Car") Book_Slot(Car_Slots, TotalC_Slots, type, owner, plate, duration, valet);
            else if (type == "Bike") Book_Slot(Bike_Slots, TotalB_Slots, type, owner, plate, duration, valet);
            else if (type == "Truck") Book_Slot(Truck_Slots, TotalT_Slots, type, owner, plate, duration, valet);
            else cout << "Invalid vehicle type!" << endl;
            break;
        }
            
        case 3:{
            string type;
            int slotNum;
            cout << "Enter vehicle type (Car/Bike/Truck): ";
            cin >> type;
            cout << "Enter slot number: ";
            cin >> slotNum;
            if (type == "Car") Release_Slot(Car_Slots, TotalC_Slots, slotNum, type);
            else if (type == "Bike") Release_Slot(Bike_Slots, TotalB_Slots, slotNum, type);
            else if (type == "Truck") Release_Slot(Truck_Slots, TotalT_Slots, slotNum, type);
            else cout << "Invalid vehicle type!" << endl;
            break;
        }
            
        case 4:
            cout << "Exiting system. Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
        
    } while (Choice != 4);
    return 0;
}

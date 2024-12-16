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

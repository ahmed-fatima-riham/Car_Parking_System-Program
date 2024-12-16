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
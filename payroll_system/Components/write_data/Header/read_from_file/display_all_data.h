#ifndef DISPLAY_ALL_DATA_H
#define DISPLAY_ALL_DATA_H

#include <iostream>

#include "../structure.h"

void display_all_data(Employee * e){
    Attendance_record * ar = e->head;
    while(ar != nullptr){
        cout<< "ID: " << ar->ID << " "
            << "Name: " << ar->name << " "
            << "Gender: " << ar->gender << " "
            << endl;

            ar = ar->next;
    }
}

#endif 

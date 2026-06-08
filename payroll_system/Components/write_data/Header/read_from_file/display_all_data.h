#ifndef DISPLAY_ALL_DATA_H
#define DISPLAY_ALL_DATA_H

#include <iostream>
#include <iomanip>

#include "../structure.h"

void display_all_data(Employee * e){
    Attendance_record * ar = e->head;
    cout<< left << setw(10) << "ID"
        << setw(20) << "Name"
        << setw(10) << "Gender"
        << setw(12) << "Work Hour" 
        << setw(12) << "Overtime"
        << setw(12) << "Attendacne"
        << setw(12) << "Total Cost"
        << endl;
    cout << string(88,'-') << endl;
    while(ar != nullptr){
        cout << left 
            << setw(10) << ar->ID
             << setw(20) << ar->name
             << setw(10) << ar->gender
             << setw(12) << ar->work_hour 
             << setw(12) << ar->overtime
             << setw(12) << ar->attendance_count
             << setw(4) << ar->total_cost << "$"
             << setw(12) << endl;

            ar = ar->next;
    }
}

#endif 

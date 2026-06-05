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
        << setw(12) << "Overtime"
        << setw(12) << "Attendacne"
        << setw(12) << "Full Hour"
        << setw(12) << "Work Hour" 
        << endl;
    cout << string(88,'-') << endl;
    while(ar != nullptr){
        cout << left 
            << setw(10) << ar->ID
             << setw(20) << ar->name
             << setw(10) << ar->gender
             << setw(12) << ar->overtime
             << setw(12) << ar->attendance_count
             << setw(12) << ar->full_hour
             << setw(12) << ar->work_hour 
             << setw(12) << endl;

            ar = ar->next;
    }
}

#endif 

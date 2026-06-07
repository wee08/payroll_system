#ifndef CALCULATE_ATTENDANCE_H
#define CALCULATE_ATTENDANCE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "../write_data/Header/structure.h"

using namespace std;

void calculate_attendance(Employee * e,string file_name){ 

    int attendance_count = 0;

    Attendance_record * ar = e->head;
    
    cout << left
        << setw(12) << "ID"
        << setw(12) << "Attendance" << endl;
    cout << string(80,'-') << endl;
    while(ar != nullptr){
        attendance_count = stoi(ar->attendance_count);
        cout<< left << setw(12) << ar->ID
            << setw(12) << attendance_count
            << endl;
        ar = ar->next;
    }
}
// id ? check_in check_out < 8 || >= 8 , overtime, 
#endif
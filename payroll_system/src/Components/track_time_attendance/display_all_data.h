#ifndef DISPLAY_ALL_DATA_H
#define DISPLAY_ALL_DATA_H

#include <iostream>
#include <iomanip>
#include <fstream>

#include "../../Model/structure.h"

void display_all_data(Employee * e,string file_name){

    const int default_space = 8;
    const int S_space = 12;
    const int M_space = 18;
    const int L_space = 30;

    Attendance_record * ar = e->head;

    string employee_file = "./payroll_system/Data/employee_list.csv";
    string attendance_file = "./payroll_system/Data/attendance.csv";

    // ifstream file(file_name);

    // string header;
    // getline(file,header);
    // stringstream ss(header);
    // string table_head;
    // while (getline(ss, table_head, ',')) {
    //     cout << left << setw(S_space) << table_head;
    // }
    // cout << endl;




    cout<< left << setw(default_space) << "ID"
        << setw(M_space) << "Name"
        << setw(default_space) << "Gender"
        << setw(M_space) << "Department"
        << setw(L_space) << "Position"
        << setw(default_space) << "Salary"
        << setw(M_space) << "Hourly Paid"
        << setw(M_space) << "Phone";

    if(file_name != attendance_file) cout << endl;

    if(file_name == attendance_file){
        cout << setw(S_space) << "Work Hour"
        << setw(S_space) << "Overtime"
        << setw(S_space) << "Attandance"
        << setw(S_space) << "Total Cost"
        << endl;
    }

    cout << string(180,'-') << endl;

    while(ar != nullptr){

        cout << left             
             << setw(default_space) << ar->ID
             << setw(M_space) << ar->name
             << setw(default_space) << ar->gender
             << setw(M_space) << ar->department
             << setw(L_space) << ar->position
             << setw(default_space) << ar->salary
             << setw(M_space) << ar->hourly_paid
             << setw(M_space) << ar->phone

             << setw(S_space) << ar->work_hour 
             << setw(S_space) << ar->overtime 
             << setw(S_space) << ar->attendance_count
             << setw(S_space) << ar->total_cost << "$"
             << setw(S_space) << endl;

            ar = ar->next;
    }
}

#endif 

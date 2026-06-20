#ifndef DISPLAY_ALL_DATA_H
#define DISPLAY_ALL_DATA_H

#include <iostream>
#include <iomanip>
#include <fstream>

#include "../Model/structure.h"

void display_all_data(Employee * e,string file_name){

    const int default_space = 8;
    const int S_space = 12;
    const int M_space = 18;
    const int L_space = 30;

    Attendance_record * ar = e->head;

    string employee_file = "./payroll_system/Data/employee_list.csv";
    string attendance_file = "./payroll_system/Data/attendance.csv";

    if(file_name == employee_file){
        cout<< left << setw(4) << "ID"
            << setw(M_space) << "Name"
            << setw(8) << "Gender"
            << setw(12) << "Department"
            << setw(L_space) << "Position"
            << setw(default_space) << "Salary"
            << setw(S_space) << "Hourly Paid"
            << setw(default_space) << "Phone" << endl;
            cout << string(120,'-') << endl;
    }else if(file_name == attendance_file){
            cout<< left << setw(4) << "ID"
            << setw(M_space) << "Name"
            << setw(8) << "Gender"
            << setw(12) << "Department"
            << setw(L_space) << "Position"
            << setw(default_space) << "Salary"
            << setw(S_space) << "Hourly Paid"
            << setw(M_space) << "Phone" 

            << setw(S_space) << "Work Hour"
            << setw(10) << "Overtime"
            << setw(S_space) << "Attandance"
            << "Total Cost"
            << endl;
            cout << string(173,'-') << endl;
    }

    while(ar != nullptr){
        if(file_name == employee_file){
            cout << left             
             << setw(4) << ar->ID
             << setw(M_space) << ar->name
             << setw(8) << ar->gender
             << setw(12) << ar->department
             << setw(L_space) << ar->position
             << setw(default_space) << ar->salary
             << setw(S_space) << ar->hourly_paid
             << setw(M_space) << ar->phone << endl;
        }else if(file_name == attendance_file){
            cout << left             
             << setw(4) << ar->ID
             << setw(M_space) << ar->name
             << setw(8) << ar->gender
             << setw(12) << ar->department
             << setw(L_space) << ar->position
             << setw(default_space) << ar->salary
             << setw(S_space) << ar->hourly_paid
             << setw(M_space) << ar->phone
             
             << setw(S_space) << ar->work_hour 
             << setw(10) << ar->overtime 
             << setw(S_space) << ar->attendance_count
             << fixed << setprecision(2) << stoi(ar->total_cost) << "\t$"
             << endl;
        }
        ar = ar->next;
    }
    cout << endl;
}

#endif 

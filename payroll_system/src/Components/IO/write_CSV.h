#ifndef WRITE_CSV_H
#define WRITE_CSV_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

#include "../../Model/structure.h"

using namespace std;

void write_CSV(Employee * e,string file_name,string ID, int overtime,int attendance_count,int work_hour,float overtime_paid,int total_cost){

    Attendance_record * ar = e->head;
    
    ofstream file;


    ifstream check(file_name);

    if(!check.is_open()){
        cout << "file not open!" << endl;
        return;
    }

    bool isEmpty = (check.peek()) == EOF;
    check.close();

    file.open(file_name, ios::app);

    if(isEmpty){
        file << "ID,Name,Gender,Departmen,Position,Monthly Salary,Hourly Paid,Phone,Overtime,Attendance,Work Hour,Overtime Paid,Total Cost" << endl;
    }
    
    while(ar != nullptr){
        if(ar->ID == ID){
            ar->overtime = to_string(overtime);
            ar->attendance_count = to_string(attendance_count);
            ar->work_hour = to_string(work_hour);
            ar->total_cost = to_string(total_cost);
            ar->overtime_paid = to_string(overtime_paid);

            file<< ar->ID << ","
                << ar->name << ","
                << ar->gender << ","
                << ar->department << ","
                << ar->position << ","
                << ar->salary << ","
                << ar->hourly_paid << ","
                << ar->phone << ","
                
                << ar->overtime << ","
                << ar->attendance_count << ","
                << ar->work_hour << ","
                << ar->overtime_paid << ","
                << fixed << setprecision(2) << ar->total_cost << "," << endl;
        }
        ar = ar->next;
    }

    file.close();
}


#endif
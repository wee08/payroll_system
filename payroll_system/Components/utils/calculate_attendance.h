#ifndef CALCULATE_ATTENDANCE_H
#define CALCULATE_ATTENDANCE_H

#include <iostream>
#include <fstream>

#include "../write_data/Header/structure.h"

using namespace std;

void calculate_attendance(Employee * e,string file_name){

    Attendance_record * ar = e->head;
    double total_attendacne = 0;
    string ID = "H2";
    ofstream file(file_name,ios::app);
    string line;
    int test;
    while(ar != nullptr){
        if(ID == ar->ID){
           test = stoi(ar->attendance_count);
        }
        ar = ar->next;
    }
    cout << "Attendacne:  "<< test << endl;
}

#endif
#ifndef WRITE_CSV_H
#define WRITE_CSV_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../structure.h"

using namespace std;

void write_CSV(Employee * e,string file_name,string ID, int overtime,int attendance_count,int work_hour,int total_cost){

    Attendance_record * ar = e->head;
    
    ofstream file;
    string temp_file = "../../Data/temp.csv";

    ifstream check(temp_file);
    bool isEmpty = (check.peek()) == EOF;
    check.close();

    file.open(temp_file, ios::app);

    if(isEmpty){
        file << "ID,Name,Gender,Overtime,Attendance,Work Hour,Total Cost" << endl;
    }
    ar->overtime = to_string(overtime);
    ar->attendance_count = to_string(attendance_count);
    ar->work_hour = to_string(work_hour);
    ar->total_cost = to_string(total_cost);


        file<< ar->ID << ","
            << ar->name << ","
            << ar->gender << ","
            << ar->overtime << ","
            << ar->attendance_count << ","
            << ar->work_hour << ","
            << ar->total_cost << "," << endl;

    file.close();
}


#endif
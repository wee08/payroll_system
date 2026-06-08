#ifndef WRITE_CSV_H
#define WRITE_CSV_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../structure.h"

using namespace std;

void write_CSV(Employee * e,string file_name, int attendance_count,string ID){

    Attendance_record * ar = e->head;
    
    ofstream file;
    string temp_file = "../../Data/temp.csv";

    ifstream check(temp_file);
    bool isEmpty = (check.peek()) == EOF;
    check.close();

    file.open(temp_file, ios::app);

    if(isEmpty){
        file << "ID,Name,Gender,Work Hour,Overtime,Attendance,Total Cost" << endl;
    }

        file<< ar->ID << ","
            << ar->name << ","
            << ar->gender << ","
            << ar->work_hour << ","
            << ar->overtime << ","
            << ar->attendance_count << ","
            << ar->total_cost << "," << endl;

    file.close();
}


#endif
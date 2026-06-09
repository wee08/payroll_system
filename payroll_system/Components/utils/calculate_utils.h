#ifndef CALCULATE_UTILS_H
#define CALCULATE_UTILS_H

#include <iostream>

#include "../write_data/Header/structure.h"
#include "../write_data/Header/write_to_file/write_CSV.h"
using namespace std;


void calculate_utils(Employee * e,string ID,int attendance_cout,int work_hour){

    string file_path = "../../Data/attendance.csv";

    const int full_hour = 160;

    int overtime = full_hour - work_hour;
    if(overtime < 0) overtime*=(-1);

    int total_cost  = attendance_cout * 8;

    write_CSV(e,file_path,ID,overtime,attendance_cout,work_hour,total_cost);


}


#endif
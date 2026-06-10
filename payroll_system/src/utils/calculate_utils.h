#ifndef CALCULATE_UTILS_H
#define CALCULATE_UTILS_H

#include <iostream>

#include "../Model/structure.h"
#include "../Components/IO/write_CSV.h"
using namespace std;


void calculate_utils(Employee * e,string file_name,string ID,int attendance_cout,int work_hour,float hourly_paid){

    const int full_hour = 160;
    
    // int overtime = work_hour - full_hour;
    // int reduction;
    // if(overtime < 0) reduction = overtime * hourly_paid * (-1);
    
    // float overtime_paid = ((1.5 * hourly_paid) * overtime);
    // int total_cost  = attendance_cout * 8;

    // write_CSV(e,file_name,ID,overtime,attendance_cout,work_hour,overtime_paid,total_cost);

}


#endif
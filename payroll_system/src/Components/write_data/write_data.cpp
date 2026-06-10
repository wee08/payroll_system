#include "../IO/write_CSV.h"
#include "../../Model/structure.h"
#include "../track_time_attendance/attendance_record.h"
#include "../track_time_attendance/display_all_data.h"
int main(){
    string file_name = "../../../Data/employee_list.csv";
    string temp_file = "../../../Data/attendance.csv";
    // write_CSV(file_name);
    // write_CSV("../../Data/attendance.csv");
    // Employee * e = read_CSV("../../Data/attendance.csv");
    // struct employee = read_CSV function to be able to get the data from linked listñ
    Employee * e = read_CSV(file_name);
    
    // attendance_record(e,file_name,"F1",2,172);
    display_all_data(e);
}
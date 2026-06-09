#include "./Header/read_from_file/read_CSV.h"
#include "./Header/structure.h"
#include "./Header/write_to_file/attendance_record.h"
int main(){
    string file_name = "../../Data/employee_list.csv";
    string temp_file = "../Data/temp.csv";
    // write_CSV(file_name);
    // write_CSV("../../Data/attendance.csv");
    // Employee * e = read_CSV("../../Data/attendance.csv");
    // struct employee = read_CSV function to be able to get the data from linked list
    Employee * e = read_CSV(file_name);
    display_all_data(e);

    attendance_record(e,file_name,"F1",2,172);
}
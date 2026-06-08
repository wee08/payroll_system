#include "./Header/read_from_file/read_CSV.h"
#include "./Header/structure.h"
#include "../utils/calculate_attendance.h"

#include "./Header/write_to_file/attendance_record.h"
int main(){
    string file_path = "../../Data/attendance.csv";
    string temp_file = "../Data/temp.csv";
    // write_CSV(file_path);
    // write_CSV("../../Data/attendance.csv");
    // Employee * e = read_CSV("../../Data/attendance.csv");
    // display_all_data(e);
    // struct employee = read_CSV function to be able to get the data from linked list
    Employee * e = read_CSV(file_path);
    // calculate_attendance(e,file_path);

    attendance_record(e,file_path,10,"F1");
}
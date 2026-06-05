#include "./Header/read_from_file/read_CSV.h"
#include "./Header/write_to_file/write_to_file.h"
#include "./Header/structure.h"
#include "../utils/calculate_attendance.h"

int main(){
    string file_path = "../../Data/attendance.csv";
    // write_CSV(file_path);
    // write_CSV("../../Data/attendance.csv");
    // Employee * e = read_CSV("../../Data/attendance.csv");
    Employee * e = read_CSV(file_path);
    calculate_attendance(e,file_path);
}
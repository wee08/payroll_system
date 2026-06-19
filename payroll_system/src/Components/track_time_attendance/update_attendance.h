#ifndef UPDATE_ATTENDANCE_H 
#define UPDATE_ATTENDANCE_H

#include <iostream>

#include "../IO/read_CSV.h"
#include "./attendance_record.h"
using namespace std;

void update_attendance(string file_name,string target_ID, string content){
    ofstream file(file_name);
    file << content;
    file.close();
}   

#endif
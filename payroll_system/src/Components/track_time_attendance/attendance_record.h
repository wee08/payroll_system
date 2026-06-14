#ifndef ATTENDANCE_RECORD_H
#define ATTENDANCE_RECORD_H
#include <ostream>
#include <fstream>

#include "../../Model/structure.h"
#include "../IO/read_CSV.h"
#include "../IO/write_CSV.h"
#include "../../utils/calculate_utils.h"
#include "./update_attendance.h"
using namespace std;

void attendance_record(Employee *e,string file_name,string target_ID,int attendance_count,int work_hour){
    Attendance_record * ar = e->head;

    ifstream find_ID(file_name);
    if(!find_ID.is_open()){
        cout << "File not open!" << endl;
        return;
     }

    string content = "";
    string line;
    float hourly_paid;

     while(getline(find_ID,line)){
        string ID = line.substr(0,line.find(','));
        if(ID == target_ID){
            calculate_utils(e,file_name,target_ID,attendance_count,work_hour,hourly_paid);
        }else{
            content += line + "\n";
            update_attendance(file_name,target_ID,content);
        }
     }
    find_ID.close();

    while(ar!=nullptr){
            hourly_paid = stoi(ar->hourly_paid);
        ar = ar->next;
    }

    calculate_utils(e,file_name,target_ID,attendance_count,work_hour,hourly_paid);


}
#endif
#ifndef ATTENDANCE_RECORD_H
#define ATTENDANCE_RECORD_H
#include <ostream>
#include <fstream>

#include "../../Model/structure.h"
#include "../../utils/calculate_utils.h"
#include "./update_attendance.h"
#include "../convert_ID.h"

using namespace std;

void attendance_record(Employee *e,string attendance_file,string target_ID,int attendance_count,int work_hour){
    Attendance_record * ar = e->head;

    ofstream find_ID(attendance_file,ios::app);
    if(!find_ID.is_open()){
        cout << "File not open!" << endl;
        return;
     }

    string content = "";
    string line;
    float hourly_paid;
    
    string new_record;

    // getline(find_ID,line);

    // string ID = line.substr(0,line.find(','));
     while(ar != nullptr){
        target_ID = convert_ID(target_ID);
        if(ar->ID == target_ID){
            ar->attendance_count = to_string(attendance_count);
            ar->work_hour = to_string(work_hour);
        }else{
            content += line + "\n";
        }
        ar = ar->next;
    }
    find_ID.close();
    
    while(ar!=nullptr){
        hourly_paid = stof(ar->hourly_paid);
        ar = ar->next;
    }
    
    update_attendance(attendance_file,target_ID,content);
    calculate_utils(e,attendance_file,target_ID,attendance_count,work_hour,hourly_paid);


}
#endif
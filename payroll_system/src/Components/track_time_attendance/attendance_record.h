#ifndef ATTENDANCE_RECORD_H
#define ATTENDANCE_RECORD_H
#include <ostream>

#include "../../Model/structure.h"
#include "../IO/read_CSV.h"
#include "../IO/write_CSV.h"
#include "../../utils/calculate_utils.h"
using namespace std;

void attendance_record(Employee *e,string file_name,string ID,int attendance_count,int work_hour){
    Attendance_record * ar = e->head;

    float hourly_paid;
    bool isFound = false;

    while(ar!=nullptr){
        if(ar->ID == ID){
            hourly_paid = stoi(ar->hourly_paid);
            isFound = true;
        }
        
        ar = ar->next;
    }

    if(!isFound){
        cout << "ID doesn't exist!" << endl;
        return;
    }

    calculate_utils(e,file_name,ID,attendance_count,work_hour,hourly_paid);

}
#endif
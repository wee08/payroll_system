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

    while(ar!=nullptr){
            hourly_paid = stoi(ar->hourly_paid);
        
        ar = ar->next;
    }

    calculate_utils(e,file_name,ID,attendance_count,work_hour,hourly_paid);

}
#endif
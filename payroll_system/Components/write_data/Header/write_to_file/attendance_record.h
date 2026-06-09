#ifndef ATTENDANCE_RECORD_H
#define ATTENDANCE_RECORD_H
#include <ostream>

#include "../structure.h"
#include "../read_from_file/read_CSV.h"
#include "./write_CSV.h"
#include "../../../utils/calculate_utils.h"
using namespace std;

void attendance_record(Employee *e, string file_name,string ID,int attendance_count,int work_hour){
    Attendance_record * ar = e->head;

    while(ar!=nullptr){
        if(ar->ID != ID)break;
        ar = ar->next;
    }

    if(ar==nullptr){
        cout << "ID doesn't exist!" << endl;
        return;
    }

    calculate_utils(e,ID,attendance_count,work_hour);

}
#endif
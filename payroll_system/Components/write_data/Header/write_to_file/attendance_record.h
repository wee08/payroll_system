#ifndef ATTENDANCE_RECORD_H
#define ATTENDANCE_RECORD_H
#include <ostream>

#include "../structure.h"
#include "../read_from_file/read_CSV.h"
#include "./write_CSV.h"
using namespace std;

void attendance_record(Employee *e, string file_name,string ID, int overtime,int attendance_count,int work_hour,int total_cost){
    Attendance_record * ar = e->head;

    while(ar!=nullptr){
        if(ar->ID != ID)break;
        ar = ar->next;
    }

    if(ar==nullptr){
        cout << "ID doesn't exist!" << endl;
        return;
    }

    write_CSV(e,file_name,ID,overtime,attendance_count,work_hour,total_cost);
}
#endif
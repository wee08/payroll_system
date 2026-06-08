#ifndef ATTENDANCE_RECORD_H
#define ATTENDANCE_RECORD_H
#include <ostream>

#include "../structure.h"
#include "../read_from_file/read_CSV.h"
#include "./write_CSV.h"
using namespace std;

void attendance_record(Employee*e, string file_name, int attendance_count,string ID){
        
    Attendance_record * ar = e->head;

    while(ar!=nullptr){
        if(ar->ID != ID)break;
        ar = ar->next;
    }

    if(ar==nullptr){
        cout << "ID doesn't exist!" << endl;
        return;
    }

    ar->attendance_count = to_string(attendance_count);
    ar->total_cost = to_string(333);

    write_CSV(e,file_name,attendance_count,ID);
}
#endif
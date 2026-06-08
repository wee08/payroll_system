#ifndef ATTENDANCE_RECORD_H
#define ATTENDANCE_RECORD_H
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../structure.h"
#include "../read_from_file/read_CSV.h"
using namespace std;

void attendance_record(string file_name, int attendance_count,string ID){
    
    Employee * e = read_CSV(file_name);
    Attendance_record * ar = e->head;
    ofstream file;
    file.open(file_name, ios::trunc);
    file << "ID,Name,Gender,Work Hour,Overtime,Attendance,Total Cost\n";
    while(ar!=nullptr){
         if(ID != ar->ID){
            cout << "ID doesn't exist!"<< endl;
            return;
         }

         if(ID == ar->ID){
            ar->attendance_count = to_string(attendance_count);
            ar->total_cost = to_string(333);
            file<< ar->ID << ","
                << ar->name << ","
                << ar->gender << ","
                << ar->work_hour << ","
                << ar->overtime << ","
                << ar->attendance_count << ","
                << ar->total_cost << ",";
            return;
         }

         ar = ar->next;
    }

    file.close();

}
#endif
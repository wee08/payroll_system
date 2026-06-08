#ifndef ATTENDANCE_RECORD_H
#define ATTENDANCE_RECORD_H
#include <ostream>
#include <fstream>

#include "../structure.h"
#include "../read_from_file/read_CSV.h"
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
    ofstream file;
    string temp_file = "../../Data/temp.csv";

    ifstream check(temp_file);
    bool isEmpty = (check.peek()) == EOF;
    check.close();

    file.open(temp_file, ios::app);

    if(isEmpty){
        file << "ID,Name,Gender,Work Hour,Overtime,Attendance,Total Cost" << endl;
    }
    ar->attendance_count = to_string(attendance_count);
    ar->total_cost = to_string(333);
        file<< ar->ID << ","
            << ar->name << ","
            << ar->gender << ","
            << ar->work_hour << ","
            << ar->overtime << ","
            << ar->attendance_count << ","
            << ar->total_cost << "," << endl;

    file.close();

}
#endif
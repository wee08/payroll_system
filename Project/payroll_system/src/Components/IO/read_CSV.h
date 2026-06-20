#ifndef READ_CSV_H
#define READ_CSV_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "../../Model/structure.h"
#include "../../Model/create_new_employee.h"
#include "../../Model/create_new_employee.h"

using namespace std;

Employee * read_CSV(string file_name){
    Employee * e  = create_new_employee();

    ifstream file;
    file.open(file_name);

    string line;
    getline(file,line);

    while(getline(file,line)){
        Attendance_record * ar = new  Attendance_record();
        ar->next = nullptr;
        ar->prev = e->tail;     
        
        if(e->tail != nullptr){
            e->tail->next = ar;
        }else{
            e->head = ar;
        }   

        stringstream ss(line);
                
        getline(ss,ar->ID,',');
        getline(ss,ar->name,',');
        getline(ss,ar->gender,',');
        getline(ss,ar->department,',');
        getline(ss,ar->position,',');
        getline(ss,ar->salary,',');
        getline(ss,ar->hourly_paid,',');
        getline(ss,ar->phone,',');

        getline(ss,ar->overtime,',');
        getline(ss,ar->attendance_count,',');
        getline(ss,ar->work_hour,',');
        getline(ss,ar->overtime_paid,',');
        getline(ss,ar->total_cost,',');

        
        e->tail = ar;
        e->size++;
    }
    file.close();
    return e;
}


#endif
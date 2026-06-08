#ifndef WRITE_TO_FILE_H
#define WRITE_TO_FILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../structure.h"

using namespace std;

void write_CSV(string file_name, int attendance_count,string ID){
    Employee * e;
    Attendance_record * ar = e->head;
    ofstream file(file_name,ios::app);
    
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
                << ar->total_cost << "," << endl;
         }

         ar = ar->next;
    }

    file.close();

}


#endif
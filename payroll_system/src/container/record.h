#ifndef RECORD_H
#define RECORD_H

#include <iostream>

#include "../Components/track_time_attendance/attendance_record.h"
#include "../Model/structure.h"
using namespace std;

void record(Employee * e, string file_name){

    Attendance_record * ar = e->head;

    string ID;
    int attendance_count;
    int work_hour;
    int choice;

    bool isFound = false;


    while(true){
        if(e->size == 0){
            cout << "Employee doesn't enter their attendance yet!" << endl;
            return;
        }
        cout << endl;
        cout << "1 -> Enter your work result in month." << endl;
        cout << "0 -> Exit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        if(choice == 1){
            cout << "Enter your ID: ";
            cin >> ID;
            while(ar != nullptr){
                if(ar->ID == ID){
                    isFound = true;
                    break;
                }
                ar = ar->next;
            }
            if(!isFound){
                cout << "your ID doesn't exist!!!" << endl;
                break;
            }
            cout << "Enter your attendance: ";
            cin >> attendance_count;
            cout << "Enter your work hour: ";
            cin >> work_hour;
            cout << endl;
            attendance_record(e,file_name,ID,attendance_count,work_hour);
        }else if(choice == 0){
            break;
        }else{
            cout << "Invalid choice!!!" << endl;
        }

    }

}

#endif
#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <cctype>
#include <algorithm>

#include "../Components/convert_ID.h"
#include "../Components/track_time_attendance/attendance_record.h"
#include "../Model/structure.h"
using namespace std;

void record(Employee * e, string attendance_file){

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

            ID = convert_ID(ID);

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
            if(attendance_count > 20){
                cout << "INVALID ATTENDANCE INPUT" << endl;
                cout << "Work only 20 days / month" << endl;
                return;
            }
            cout << "Enter your work hour: ";
            cin >> work_hour;
            cout << endl;
            attendance_record(e,attendance_file,ID,attendance_count,work_hour);
        }else if(choice == 0){
            break;
        }else{
            cout << "Invalid choice!!!" << endl;
            continue;
        }

    }

}

#endif
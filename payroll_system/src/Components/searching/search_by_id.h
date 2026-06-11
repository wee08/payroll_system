#ifndef SEARCH_BY_ID_H
#define SEARCH_BY_ID_H

#include <iostream>
#include "../sorting/swap.h"
#include "../../Model/structure.h"
using namespace std;

void search_by_id(Employee * e,string ID){

    const int default_space = 8;
    const int S_space = 12;
    const int M_space = 18;
    const int L_space = 30;

    Attendance_record * ar = e->head;

    bool isFound = false;
    while(ar != nullptr){

        if(ar->ID == ID){
            cout<< left << setw(4) << "ID"
            << setw(M_space) << "Name"
            << setw(8) << "Gender"
            << setw(12) << "Department"
            << setw(L_space) << "Position"
            << setw(default_space) << "Salary"
            << setw(S_space) << "Hourly Paid"
            << setw(M_space) << "Phone" 
            << setw(S_space) << "Work Hour"
            << setw(10) << "Overtime"
            << setw(S_space) << "Attandance"
            << "Total Cost"
            << endl;
            cout << string(173,'-') << endl;

            cout << left             
             << setw(4) << ar->ID
             << setw(M_space) << ar->name
             << setw(8) << ar->gender
             << setw(12) << ar->department
             << setw(L_space) << ar->position
             << setw(default_space) << ar->salary
             << setw(S_space) << ar->hourly_paid
             << setw(M_space) << ar->phone
             << setw(S_space) << ar->work_hour 
             << setw(10) << ar->overtime 
             << setw(S_space) << ar->attendance_count
             << ar->total_cost << "\t$"
             << endl;
            isFound = true;
            break;
        }
        ar = ar->next;
    } 
    if(!isFound) cout << "ID doesn't exist!" << endl;
}

#endif
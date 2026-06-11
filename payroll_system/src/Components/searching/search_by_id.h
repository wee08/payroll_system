#ifndef SEARCH_BY_ID_H
#define SEARCH_BY_ID_H

#include <iostream>
#include "../sorting/swap.h"
#include "../../Model/structure.h"
using namespace std;

void search_by_id(Employee * e, string ID){
    Attendance_record * ar = e->head;
    while(ar != nullptr){

        if(ar->ID == ID){
            cout << ID << " is found!" << endl;   
        }

        ar = ar->next;
    }    
}

#endif
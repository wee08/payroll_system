
#ifndef SORT_BY_LEAST_ATTENDANCE_H
#define SORT_BY_LEAST_ATTENDANCE_H

#include <iostream>
#include <string>

#include "../../Model/structure.h"
#include "./swap.h"

using namespace std;

void sortBubble(Employee* e, int size) {

    if(e->head == nullptr || e->head->next == nullptr)return;

    bool state = false;

    for(int i = 0; i < size - 1; i++) {
        state = false;

        Attendance_record * ar_1 = e->head;
        Attendance_record * ar_2 = e->head->next;

        for(int j = 0; j < size - i - 1; j++) {
            if((ar_1->attendance_count) > (ar_2->attendance_count)) {
                int att_1 = stoi(ar_1->attendance_count);
                int att_2 = stoi(ar_1->attendance_count);
                swap(&att_1, &att_2);
                state = true;
            }

            ar_1 = ar_1->next;
            ar_2 = ar_2->next;
        }

        if(!state) break;
    }
}

#endif
#ifndef SORT_BY_MOST_ATTENDANCE_H
#define SORT_BY_MOST_ATTENDANCE_H

#include <iostream>

#include "../../Model/structure.h"
#include "./swap.h"

void sort_by_most_attendance(Employee* e, int size) {

    if(e->head == nullptr || e->head->next == nullptr)return;

    bool state = false;

    for(int i = 0; i < size - 1; i++) {
        state = false;

        Attendance_record * ar_1 = e->head;
        Attendance_record * ar_2 = e->head->next;

        for(int j = 0; j < size - i - 1; j++) {
            int attendance_1 = 0;
            int attendance_2 = 0;
            if(!ar_1->attendance_count.empty()) attendance_1 = stoi(ar_1->attendance_count);
            if(!ar_2->attendance_count.empty()) attendance_2 = stoi(ar_2->attendance_count);
            if(attendance_1  < attendance_2) {
                swap(ar_1->ID, ar_2->ID);
                swap(ar_1->name, ar_2->name);
                swap(ar_1->gender, ar_2->gender);
                swap(ar_1->department, ar_2->department);
                swap(ar_1->position, ar_2->position);
                swap(ar_1->salary, ar_2->salary);
                swap(ar_1->hourly_paid, ar_2->hourly_paid);
                swap(ar_1->phone, ar_2->phone);
                swap(ar_1->work_hour, ar_2->work_hour);
                swap(ar_1->overtime, ar_2->overtime);
                swap(ar_1->attendance_count, ar_2->attendance_count);
                swap(ar_1->overtime_paid, ar_2->overtime_paid);
                swap(ar_1->total_cost, ar_2->total_cost);
                state = true;
            }

            ar_1 = ar_1->next;
            ar_2 = ar_2->next;
        }

        if(!state) break;
    }
}

#endif
#ifndef CALCULATE_UTILS_H
#define CALCULATE_UTILS_H

#include <iostream>
#include "../Model/structure.h"
using namespace std;

CalcResult calculate_utils(int attendance_count, int work_hour, float hourly_paid){
    const int full_hour       = 160;
    const int full_attendance = 20;

    CalcResult result;
    result.overtime      = max(0, work_hour - full_hour);
    result.overtime_paid = 1.5f * hourly_paid * result.overtime;
    result.total_cost    = (full_attendance - attendance_count) * 8 * hourly_paid;

    return result;
}

#endif
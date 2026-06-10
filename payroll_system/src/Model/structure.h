#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <iostream>
using namespace std;
struct Attendance_record{
    string ID;
    string name;
    string gender;
    string department;
    string position;
    string salary;
    string hourly_paid;
    string phone;
    
    string overtime;
    string attendance_count;
    string work_hour;
    string overtime_paid;
    string total_cost;

    Attendance_record * next;
    Attendance_record * prev;

};

struct Employee{
    int size;

    Attendance_record * head;
    Attendance_record * tail;
};
#endif

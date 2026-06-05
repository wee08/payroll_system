#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <iostream>
using namespace std;
struct Attendance_record{
    string ID;
    string name;
    string gender;
    string overtime;
    string attendance_count;
    string full_hour;
    string work_hour;

    Attendance_record * next;
    Attendance_record * prev;

};

struct Employee{
    int size;

    Attendance_record * head;
    Attendance_record * tail;
};
#endif
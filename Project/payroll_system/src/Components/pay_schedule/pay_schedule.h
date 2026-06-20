#ifndef PAY_SCHEDULE_H
#define PAY_SCHEDULE_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>

#include "../IO/read_CSV.h"
#include "../../Model/structure.h"
using namespace std;


void pay_schedule(Node* head,string attendance_file,string final_salary_file) {
    Employee * att_l = read_CSV(attendance_file);

    const char* months[] = {
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"};

    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int month_idx = now->tm_mon + 1;

    double total = 0;
    double salary;
    Node* temp = head;
    Attendance_record * ar = att_l->head;
    cout << endl << 
        left << setw(20) << "Name" 
        << setw(12) << "Payment" 
        << "Pay Date" << endl
        << string(47,'-') << endl;
    
    ifstream file_out;
    file_out.open(final_salary_file);
    if(!file_out.is_open()){
        cout << "File is not open!" << endl;
        return;
    }
    string line;
    stringstream ss;
    string tax_;
    int location = 0;

    getline(file_out,line);

    while(ar != nullptr) {

        if(!getline(file_out,line)){
            salary = 0;
            return;
        }
        location = line.find(",");
        tax_ = line.substr(0,location);
        line = line.substr(location + 1, line.length());
        salary = stod(line);
        total += salary;
        // cout <<"[" << (salary) << "]" << endl;
        cout<< left 
            << setw(20) <<ar->name
            << setw(12) << salary
            << "[ 20-"<< months[month_idx] <<"-2026 ]" << endl;

        ar = ar->next;
    }
    cout << endl;
    cout << "Total = $" << total << endl;
}



#endif
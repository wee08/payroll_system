#ifndef PAY_SCHEDULE_H
#define PAY_SCHEDULE_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "../../Model/structure.h"
#include "../IO/read_CSV.h"
#include "../../Model/structure.h"
using namespace std;

string file_path = "../../../Data/attendance.csv";
string final_salary_file = "../../../Data/final_salary.csv";
Employee * att_l = read_CSV(file_path);

void swapPayday(Payday& a, Payday& b) {
    Payday temp = a;
    a = b;
    b = temp;
}

void display(Node* head) {
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
        cout << "not open" << endl;
        return;
    }
    string line;
    stringstream ss;
    while(getline(file_out,line)) {
        salary = stod(line);
        total += salary;
        

        cout<< left 
            << setw(20) <<ar->name
            << setw(12) << salary
            << "[ 12-Jun-2026 ]" << endl;

        ar = ar->next;
    }
    cout << endl;
    cout << "Total = $" << total << endl;
}



#endif
#ifndef PAY_SCHEDULE_H
#define PAY_SCHEDULE_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "../IO/read_CSV.h"
#include "../../Model/structure.h"
using namespace std;


void pay_schedule(Node* head,string attendance_file,string final_salary_file) {
    Employee * att_l = read_CSV(attendance_file);

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

    getline(file_out,line);

    while(ar != nullptr) {

        if(!getline(file_out,line)){
            salary = 0;
            return;
        }
        salary = stod(line);
        total += salary;

        cout<< left 
            << setw(20) <<ar->name
            << setw(12) << ar->salary
            << "[ 20-Jun-2026 ]" << endl;

        ar = ar->next;
    }
    cout << endl;
    cout << "Total = $" << total << endl;
}



#endif
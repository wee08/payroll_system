#include "./payroll_system/src/Components/IO/write_CSV.h"
#include "./payroll_system/src/Components/IO/write_CSV.h"
#include "./payroll_system/src/Model/structure.h"
#include "./payroll_system/src/Components/track_time_attendance/attendance_record.h"
#include "./payroll_system/src/Components/display_all_data.h"
#include "./payroll_system/src/Components/tax_and_reduction/calculate_reduction.h"
#include "./payroll_system/src/Components/tax_and_reduction/tax_information.h"

#include "./payroll_system/src/container/sort.h"
#include "./payroll_system/src/container/search.h"
#include "./payroll_system/src/container/record.h"
int main(){
    string employee_file = "./payroll_system/Data/employee_list.csv";
    string attendance_file = "./payroll_system/Data/attendance.csv";
    string tax_information_file = "./payroll_system/Data/tax_information.csv";
    // write_CSV(employee_file);
    // write_CSV("../../Data/attendance.csv");
    // Employee * e = read_CSV("../../Data/attendance.csv");
    // struct employee = read_CSV function to be able to get the data from linked list
    Employee * emp_l = read_CSV(employee_file);
    Employee * att_l = read_CSV(attendance_file);
    // display_all_data(e,employee_file);
    
    // display_all_data(e,employee_file);
    // search_by_id(e,"F1");
    // attendance_record(emp_l,attendance_file,"F1",2,190);
    
    // sort_by_most_attendance(a,a->size);
    // display_all_data(a,attendance_file);
    // sort_by_least_attendance(a,a->size);
    // Employee * a = read_CSV(attendance_file);
    // display_all_data(a,attendance_file);

    // Monthly_Salary(attendance_file);
    // tax_information(tax_information_file);

    // search_by_id(a,"F00");
    // calculate_reductoin(attendance_file);
    int choice;
    while(true){
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        if(choice == 1){
            record(emp_l,attendance_file);
        }else{
            cout << "Invalid choice!!!"<< endl;
        }
    }
}
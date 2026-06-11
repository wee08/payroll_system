#include "./payroll_system/src/Components/IO/write_CSV.h"
#include "./payroll_system/src/Components/IO/write_CSV.h"
#include "./payroll_system/src/Model/structure.h"
#include "./payroll_system/src/Components/track_time_attendance/attendance_record.h"
#include "./payroll_system/src/Components/track_time_attendance/display_all_data.h"
#include "./payroll_system/src/Components/sorting/sort_by_least_attendance.h"
#include "./payroll_system/src/Components/sorting/sort_by_most_attendance.h"
#include "./payroll_system/src/Components/searching/search_by_id.h"
#include "./payroll_system/src/Components/tax/calculate_reduction.h"
#include "./payroll_system/src/Components/tax/tax_information.h"
int main(){
    string employee_file = "./payroll_system/Data/employee_list.csv";
    string attendance_file = "./payroll_system/Data/attendance.csv";
    string tax_information_file = "./payroll_system/Data/tax_information.csv";
    // write_CSV(employee_file);
    // write_CSV("../../Data/attendance.csv");
    // Employee * e = read_CSV("../../Data/attendance.csv");
    // struct employee = read_CSV function to be able to get the data from linked list
    // Employee * e = read_CSV(employee_file);
    // display_all_data(e,employee_file);
    
    // display_all_data(e,employee_file);
    // attendance_record(e,employee_file,"F1",2,172);
    // search_by_id(e,"F1");

    // sort_by_most_attendance(a,a->size);
    // display_all_data(a,attendance_file);
    // sort_by_least_attendance(a,a->size);
    Employee * a = read_CSV(attendance_file);
    display_all_data(a,attendance_file);

    // Monthly_Salary(attendance_file);
    // tax_information(tax_information_file);

    search_by_id(a,"F1");
}
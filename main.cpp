
#include "./payroll_system/src/container/sort.h"
#include "./payroll_system/src/container/search.h"
#include "./payroll_system/src/container/record.h"
#include "./payroll_system/src/container/salary.h"
#include "./payroll_system/src/container/submit.h"

int main(){
    
    string employee_file = "./payroll_system/Data/employee_list.csv";
    string attendance_file = "./payroll_system/Data/attendance.csv";
    string tax_information_file = "./payroll_system/Data/tax_information.csv";
    string final_salary_file = "./payroll_system/Data/final_salary.csv";
    string payroll_file = "./payroll_system/Data/payroll_report.csv";
    string tax_filling_history_file = "./payroll_system/Data/tax_report.csv";

    Employee * emp_l = read_CSV(employee_file);
    Employee * att_l = read_CSV(attendance_file);

    int choice;
        cout << endl;
        // record(emp_l,attendance_file);
        // salary(attendance_file,final_salary_file);
    submit(payroll_file, tax_filling_history_file);
}
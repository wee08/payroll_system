
#include "./payroll_system/src/container/sort.h"
#include "./payroll_system/src/container/search.h"
#include "./payroll_system/src/container/record.h"
#include "./payroll_system/src/container/salary.h"
int main(){
    string employee_file = "./payroll_system/Data/employee_list.csv";
    string attendance_file = "./payroll_system/Data/attendance.csv";
    string tax_information_file = "./payroll_system/Data/tax_information.csv";

    Employee * emp_l = read_CSV(employee_file);
    Employee * att_l = read_CSV(attendance_file);

    int choice;
    while(true){
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        if(choice == 1){
            // salary(attendance_file);
            record(emp_l,attendance_file);
        }else{
            cout << "Invalid choice!!!"<< endl;
        }
    }
}

#include "./payroll_system/src/container/sort.h"
#include "./payroll_system/src/container/search.h"
#include "./payroll_system/src/container/record.h"
#include "./payroll_system/src/container/salary.h"
#include "./payroll_system/src/container/submit.h"
#include "./payroll_system/src/Components/display_menu.h"
#include "./payroll_system/src/container/tax.h"
#include "./payroll_system/src/container/payment.h"

int main(){
    
    string employee_file = "./payroll_system/Data/employee_list.csv";
    string attendance_file = "./payroll_system/Data/attendance.csv";
    string tax_information_file = "./payroll_system/Data/tax_information.csv";
    string final_salary_file = "./payroll_system/Data/final_salary.csv";
    string payroll_file = "./payroll_system/Data/payroll_report.csv";
    string tax_filling_history_file = "./payroll_system/Data/tax_report.csv";
    string tax_report_file = "./payroll_system/Data/tax_report.csv";

    Employee * emp_l = read_CSV(employee_file);
    Employee * att_l = read_CSV(attendance_file);

    int choice;
    while(true){
        displayMenu();
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        if(choice == 1){
            record(emp_l,attendance_file);
        }else if(choice==2){
            search(att_l);
        }else if(choice==3){
            tax(tax_information_file);
        }else if(choice==4){
            salary(attendance_file,final_salary_file);
        }else if(choice==5){
            sort(att_l,attendance_file);
        }else if(choice==6){
            payment(attendance_file,final_salary_file);
        }else if(choice==7){
            submit(payroll_file,tax_report_file,final_salary_file);
        }else if(choice==0){
            cout<<"Program Closed."<<endl;
            cout<<endl;
            break;
        }else{
            cout<<"Invalid option. Try again"<<endl;
        }
    }
    return 0;
}
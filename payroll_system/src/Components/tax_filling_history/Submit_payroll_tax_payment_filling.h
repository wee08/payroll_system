#ifndef SUBMIT_PAYROLL_PAYMENT_H
#define SUBMIT_PAYROLL_PAYMENT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <ctime>

#include "../../Model/Linked_list.h"
#include "./load_payroll_from_csv.h"
#include "./get_opened_data.h"
#include "./get_submission_date.h"
#include "../IO/read_CSV.h"

using namespace std;

void submitPayrollTaxPaymentAndFiling(string Tax_report,string final_salary_file, Box* head) {

    ofstream file(Tax_report);
    if (!file.is_open()) {
        cerr << "[Error] Could not create the report file!" << endl;
        return;
    }

    string openedDate = getOpenedDate();
    string submissionDate = getSubmissionDate();

    file << "ID,Name,Base Salary,Tax Amount,Social Security,Total Deduction,Main Salary,Opened_salary Date,Submitted Date\n";

    Box* temp = head;
    double Total_tax = 0.0;
    double Total_netpay = 0.0;

    while (temp != nullptr) {
        temp->data.Salaryopendate = openedDate;
        temp->data.payrollsubmitdate = submissionDate;

        file << temp->data.ID << ","
             << temp->data.Name << ","
             << temp->data.Baseslary << ","
             << temp->data.Tax_Amount << ","
             << temp->data.Socialsociety << ","
             << temp->data.Total_deduction << ","
             << temp->data.Main_salary << ","
             << temp->data.Salaryopendate << ","
             << temp->data.payrollsubmitdate << "\n";

        temp = temp->next;
    }
            
    file.close();
    
    ifstream salary_file(final_salary_file);
    string line = "";
    string final_salary;
    string tax;
    getline(salary_file,line);
    while(getline(salary_file,line)){
        stringstream ss(line);
        getline(ss, tax,',');
        getline(ss, final_salary,',');

        Total_tax += stod(tax);
        Total_netpay += stod(final_salary);

        // cout <<"[" << stod(final_salary) << "]" << endl;
    }
    

    cout << "\n" << string(70,'=') << endl;
    cout << "[Success] Payroll report generated successfully!" << endl;
    cout << "  -> Salary Opened Date  : " << openedDate << endl;
    cout << "  -> Tax Submission Date : " << submissionDate << " (Every day 28)" << endl;
    cout << "  -> Total tax amount    : $" << fixed << setprecision(2) << Total_tax << endl;
    cout << "  -> Total net payout    : $" << fixed << setprecision(2) << Total_netpay << endl;
    cout << string(70,'=') << endl;
}
#endif
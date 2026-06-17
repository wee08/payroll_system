#ifndef SUBMIT_H
#define SUBMIT_H

#include <iostream>
#include "../Components/tax_filling_history/Submit_payroll_tax_payment_filling.h" // Your header file
#include "../Model/Linked_list.h"

using namespace std;

void submit(string payroll_file,string tax_report_file) {

    cout << "Processing payroll report generation..." << endl;
    
    Box* head = loadPayrollFromCSV(payroll_file);
    if (head != nullptr) {
        submitPayrollTaxPaymentAndFiling(tax_report_file, head);
        cout << "Task completed! Please check the 'Tax_report.csv' file." << endl;
    } else {
        cout << "Error: No payroll data found to generate report." << endl;
    }
    
    while (head != nullptr) {
        Box* temp = head;
        head = head->next;
        delete temp;
    }

}

#endif
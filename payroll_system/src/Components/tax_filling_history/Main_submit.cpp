#include <iostream>
#include "../Salary_after_reduction/Linked_list.h"
#include "Submit_payroll_tax_payment_filling.h" // Your header file

using namespace std;

int main() {
    cout << "Processing payroll report generation..." << endl;
    
    Node* head = loadPayrollFromCSV("Payroll_report.csv");
    
    if (head != nullptr) {
        submitPayrollTaxPaymentAndFiling("Tax_report.csv", head);
        cout << "Task completed! Please check the 'Tax_report.csv' file." << endl;
    } else {
        cout << "Error: No payroll data found to generate report." << endl;
    }
    
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
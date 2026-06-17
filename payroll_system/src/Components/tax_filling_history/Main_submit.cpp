#include <iostream>
#include "Submit_payroll_tax_payment_filling.h" // Your header file
#include "../../Model/Linked_list.h"

using namespace std;

int main() {

    string payroll_report_file = "../../../Data/payroll_report.csv";
    string tax_report_file = "../../../Data/tax_report.csv";

    cout << "Processing payroll report generation..." << endl;
    
    Node* head = loadPayrollFromCSV(payroll_report_file);
    
    if (head != nullptr) {
        submitPayrollTaxPaymentAndFiling(tax_report_file, head);
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
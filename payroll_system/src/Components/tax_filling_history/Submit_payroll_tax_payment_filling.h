#ifndef SUBMIT_PAYROLL_PAYMENT_H
#define SUBMIT_PAYROLL_PAYMENT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <ctime>

#include "../../Model/Linked_list.h"
using namespace std;

string getOpenedDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    stringstream ss;
    ss << (ltm->tm_year + 1900) << "-" 
       << setfill('0') << setw(2) << (ltm->tm_mon + 1) << "-20";
    return ss.str();
}

string getSubmissionDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    stringstream ss;
    ss << (ltm->tm_year + 1900) << "-" 
       << setfill('0') << setw(2) << (ltm->tm_mon + 1) << "-28";
    return ss.str();
}

void submitPayrollTaxPaymentAndFiling(string Tax_report, Box* head) {
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

        Total_tax += temp->data.Tax_Amount;
        Total_netpay += temp->data.Main_salary;
        temp = temp->next;
    }
    
    file.close();

    cout << "\n====================================================================" << endl;
    cout << "[Success] Payroll report generated successfully!" << endl;
    cout << "  -> Salary Opened Date  : " << openedDate << endl;
    cout << "  -> Tax Submission Date : " << submissionDate << " (Every day 28)" << endl;
    cout << "  -> Total tax amount    : $" << fixed << setprecision(2) << Total_tax << endl;
    cout << "  -> Total net payout    : $" << fixed << setprecision(2) << Total_netpay << endl;
    cout << "====================================================================" << endl;
}
Box* loadPayrollFromCSV(string file_name) {
    // string file_name = "../../Data/payroll_report.csv";
    
    ifstream file(file_name);
    if (!file.is_open()) return nullptr;

    Box* head = nullptr;
    Box* tail = nullptr;
    string line;

    if (!getline(file, line)) return nullptr; // រំលង Header

    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, baseSal, otPay, absDed, nssf, taxAmt, taxRate, netSal;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, baseSal, ',');
        getline(ss, otPay, ',');
        getline(ss, absDed, ',');
        getline(ss, nssf, ',');
        getline(ss, taxAmt, ',');
        getline(ss, taxRate, ',');
        getline(ss, netSal, ',');

        Box* newNode = new Box();
        newNode->data.ID = id;
        newNode->data.Name = name;
        newNode->data.Baseslary = stod(baseSal);
        newNode->data.Tax_Amount = stod(taxAmt);
        newNode->data.Socialsociety = stod(nssf);
        newNode->data.Total_deduction = stod(absDed) + stod(nssf); 
        newNode->data.Main_salary = stod(netSal);
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    file.close();
    return head;
}
#endif
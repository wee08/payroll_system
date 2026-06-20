#ifndef LOEAD_PAYROLL_FROM_CSV_H
#define LOEAD_PAYROLL_FROM_CSV_H

#include <iostream>
#include <fstream>
#include "../../Model/Linked_list.h"

Box* loadPayrollFromCSV(string file_name) {
    // string file_name = "../../Data/payroll_report.csv";
    
    ifstream file(file_name);
    if (!file.is_open()){
        cout << "File not open!" << endl;
        return nullptr;
    } 
        

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

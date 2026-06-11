#ifndef HEADER_FILE_H
#define HEADER_FILE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

struct Employee {
    string ID;
    string Name;
    float Baseslary;        
    float Tax_salary;       
    float Tax_Bracket;      
    float Tax_Amount;       
    float Socialsociety;    
    float Overtime_Hours;    
    float Overtime_Amount;   
    float Absence_Count;     
    float Absence_Deduction; 
    float Total_deduction;  
    float Main_salary;      
};

struct Node {
    Employee data;          
    Node* next;
};

void Process_salary_reduction(Employee* emp) {
    if (emp == nullptr) return;

    // 1. Find salary per hour (based on standard 160h/month)
    float hourly_rate = emp->Baseslary / 160.0f;

    // 2. Calculate Overtime Amount (OT rate is multiplier of 1.5x of hourly rate)
    emp->Overtime_Amount = emp->Overtime_Hours * (hourly_rate * 1.5f);

    // 3. Calculate Absence Deduction (1 missed day equals 8 working hours missed)
    emp->Absence_Deduction = emp->Absence_Count * (hourly_rate * 8.0f);

    // 4. Calculate Taxable Salary (Gross Base Salary + OT - Absence Deductions)
    emp->Tax_salary = emp->Baseslary + emp->Overtime_Amount - emp->Absence_Deduction;
    if (emp->Tax_salary < 0) emp->Tax_salary = 0;

    // 5. Calculate Tax Amount
    emp->Tax_Amount = emp->Tax_salary * (emp->Tax_Bracket / 100.0f);
    
    // 6. Calculate Total Deductions (Tax + NSSF Social Society + Absence Cut)
    emp->Total_deduction = emp->Tax_Amount + emp->Socialsociety + emp->Absence_Deduction;
    
    // 7. Calculate Final Net Salary
    emp->Main_salary = (emp->Baseslary + emp->Overtime_Amount) - emp->Total_deduction;
}

class EmployeeQueue {
private:
    Node* front = nullptr;
    Node* rear = nullptr;

public:
    void enqueue(Employee* emp) {
        Node* newNode = new Node();
        newNode->data = *emp;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }else{
            rear->next = newNode;
            rear = newNode;
        }
        
        delete emp;
    }

    // Displays headers for the console table
    void printTableHeader() {
        cout << setfill('=') << setw(115) << "" << endl;
        cout << setfill(' ');
        cout << left  << setw(6)  << "ID" 
             << left  << setw(22) << "Name" 
             << right << setw(13) << "Base Sal." 
             << right << setw(13) << "OT Pay" 
             << right << setw(13) << "Abs. Cut" 
             << right << setw(11) << "NSSF" 
             << right << setw(14) << "Tax (Rate)" 
             << right << setw(15) << "Net Salary" << endl;
        cout << setfill('-') << setw(115) << "" << endl;
        cout << setfill(' ');
    }

    void dequeueAndCalculateAll() {
        if (front == nullptr) {
            cout << "No data available in the queue." << endl;
            return;
        }

        // Create/Open the output CSV file
        ofstream outFile("Payroll_Report.csv");
        if (!outFile.is_open()) {
            cout << "Error: Could not create Payroll_Report.csv!" << endl;
            return;
        }

        // Write Header row to CSV file
        outFile << "ID,Name,Base Salary,Overtime Pay,Absence Deduction,NSSF,Tax Amount,Tax Rate,Net Salary\n";

        printTableHeader();

        // Standard decimal precision for console currency ($0.00)
        cout << fixed << setprecision(2);
        outFile << fixed << setprecision(2);

        while (front != nullptr) {
            Node* temp = front;
            Process_salary_reduction(&(temp->data));

            // Format tax bracket indicator string for console e.g., "$15.00 (10%)"
            string tax_info = "$" + to_string((int)temp->data.Tax_Amount) + " (" + to_string((int)temp->data.Tax_Bracket) + "%)";

            // 1. Print row to the console table
            cout << left  << setw(6)  << temp->data.ID 
                 << left  << setw(22) << temp->data.Name 
                 << right << setw(13) << ("$" + to_string((int)temp->data.Baseslary))
                 << right << setw(13) << ("$" + to_string((int)temp->data.Overtime_Amount))
                 << right << setw(13) << ("$" + to_string((int)temp->data.Absence_Deduction))
                 << right << setw(11) << ("$" + to_string((int)temp->data.Socialsociety))
                 << right << setw(14) << tax_info
                 << right << setw(15) << ("$" + to_string((int)temp->data.Main_salary)) 
                 << endl;

            // 2. Write the exact same row data separated by commas into the CSV file
            outFile << temp->data.ID << ","
                    << temp->data.Name << ","
                    << temp->data.Baseslary << ","
                    << temp->data.Overtime_Amount << ","
                    << temp->data.Absence_Deduction << ","
                    << temp->data.Socialsociety << ","
                    << temp->data.Tax_Amount << ","
                    << temp->data.Tax_Bracket << "%,"
                    << temp->data.Main_salary << "\n";

            front = front->next;
            delete temp; 
        }
        rear = nullptr;
        
        outFile.close(); // Close the file stream when finished
        cout << setfill('=') << setw(115) << "" << endl;
        cout << "\n[Success] All processed data has been exported to 'Payroll_Report.csv'." << endl;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

void Load_and_display_all() {
    EmployeeQueue queue;

    string employee_file = "../../../Data/employee_list.csv";
    string attendance_file = "../../../Data/attendance.csv";
    // 1. Open all three CSV files
    ifstream fileFull(employee_file);
    ifstream fileAtt(attendance_file);

    // Check if files are opened successfully
    if (!fileFull.is_open() || !fileAtt.is_open()) {
        cout << "Error: Cannot open CSV files!" << endl;
        return;
    }

    string lineFull, lineHourly, lineAtt;

    // Skip the header row in each file
    getline(fileFull, lineFull);
    getline(fileAtt, lineAtt);

    // 2. Read Full-Time Employee records first
    // The order must match the corresponding records in Attendance.csv
    while (getline(fileFull, lineFull) && getline(fileAtt, lineAtt)) {
        if (lineFull.empty() || lineAtt.empty()) continue;

        // Read employee information from Fulltime_Employee.csv
        stringstream ssEmp(lineFull);
        string id, name, gender, dept, pos, salaryStr;

        getline(ssEmp, id, ',');
        getline(ssEmp, name, ',');
        getline(ssEmp, gender, ',');
        getline(ssEmp, dept, ',');
        getline(ssEmp, pos, ',');
        getline(ssEmp, salaryStr, ',');

        // Read attendance information
        stringstream ssAtt(lineAtt);
        string attId, attName, attGender, otStr, absStr;

        getline(ssAtt, attId, ',');
        getline(ssAtt, attName, ',');
        getline(ssAtt, attGender, ',');
        getline(ssAtt, otStr, ',');   // Overtime hours
        getline(ssAtt, absStr, ',');  // Absence count

        Employee* emp = new Employee;

        emp->ID = id;
        emp->Name = name;
        emp->Baseslary = stoi(salaryStr);
        emp->Overtime_Hours = stoi(otStr);
        emp->Absence_Count = stoi(absStr);

        // Calculate NSSF contribution (2% with maximum salary cap of $300)
        float contribution_wage = emp->Baseslary;
        if (contribution_wage > 300.0f)
            contribution_wage = 300.0f;

        emp->Socialsociety = contribution_wage * 0.02f;

        // Determine tax bracket based on base salary
        if (emp->Baseslary <= 375)
            emp->Tax_Bracket = 0;
        else if (emp->Baseslary <= 500)
            emp->Tax_Bracket = 5;
        else if (emp->Baseslary <= 2125)
            emp->Tax_Bracket = 10;
        else if (emp->Baseslary <= 3125)
            emp->Tax_Bracket = 15;
        else
            emp->Tax_Bracket = 20;

        // Add employee to queue
        queue.enqueue(emp);
    }

    // 3. Read Hourly Employee records
    // Continue reading attendance records after full-time employees
    while (getline(fileAtt, lineAtt)) {
        if (lineHourly.empty() || lineAtt.empty()) continue;

        // Read employee information from Hourly_Employee.csv
        stringstream ssEmp(lineHourly);
        string id, name, gender, dept, pos;
        string hourlyPaidStr, phone, dependence, hourlyRateStr;

        getline(ssEmp, id, ',');
        getline(ssEmp, name, ',');
        getline(ssEmp, gender, ',');
        getline(ssEmp, dept, ',');
        getline(ssEmp, pos, ',');
        getline(ssEmp, hourlyPaidStr, ',');
        getline(ssEmp, phone, ',');
        getline(ssEmp, dependence, ',');
        getline(ssEmp, hourlyRateStr, ','); // Hourly rate

        // Read attendance information
        stringstream ssAtt(lineAtt);
        string attId, attName, attGender;
        string otStr, absStr, fullHr, workHr;

        getline(ssAtt, attId, ',');
        getline(ssAtt, attName, ',');
        getline(ssAtt, attGender, ',');
        getline(ssAtt, otStr, ',');
        getline(ssAtt, absStr, ',');
        getline(ssAtt, fullHr, ',');
        getline(ssAtt, workHr, ','); // Actual worked hours

        Employee* emp = new Employee;

        emp->ID = id;
        emp->Name = name;

        // Calculate base salary:
        // Actual worked hours × hourly rate
        float rate = stof(hourlyRateStr);
        float hoursWorked = stof(workHr);

        emp->Baseslary = hoursWorked * rate;
        
        emp->Overtime_Hours = stof(otStr);
        emp->Absence_Count = stof(absStr);

        // Hourly employees do not have NSSF deduction
        emp->Socialsociety = 0;

        // Determine tax bracket based on earned salary
        if (emp->Baseslary <= 375)
            emp->Tax_Bracket = 0;
        else if (emp->Baseslary <= 500)
            emp->Tax_Bracket = 5;
        else if (emp->Baseslary <= 2125)
            emp->Tax_Bracket = 10;
        else if (emp->Baseslary <= 3125)
            emp->Tax_Bracket = 15;
        else
            emp->Tax_Bracket = 20;

        // Add employee to queue
        queue.enqueue(emp);
    }

    // Close all files
    fileFull.close();
    fileAtt.close();

    // Display payroll report title
    cout << "\n" << setw(65) << right
         << "PAYROLL REPORT SUMMARY" << endl;

    // Calculate salary, tax, deductions, and display report
    queue.dequeueAndCalculateAll();
}


#endif
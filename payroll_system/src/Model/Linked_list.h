#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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

    string Salaryopendate;
    string payrollsubmitdate;
};

struct Node {
    Employee data;          
    Node* next;
};

#endif 
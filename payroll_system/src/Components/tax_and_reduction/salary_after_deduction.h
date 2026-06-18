#ifndef SALARY_AFTER_DEDUCTION_H
#define SALARY_AFTER_DEDUCTION_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "./calcuate_total_salary.h"
using namespace std;

string file_name = "../../../Data/final_saraly.csv";

void salary_after_deduction(double salary,double ot,double attendance, double hourlyPaid, string final_salary_file){
    const int default_space = 8;
    const int S_space = 12;
    const int M_space = 18;
    const int L_space = 24;
    double final_salary, tax;
    const int full_attendance = 20;
    if(salary<375){
        tax=(salary*0);
        final_salary=salary-tax-((full_attendance - attendance)*8*hourlyPaid)+(1.5*hourlyPaid*ot);
    }else if(salary<500){
        tax=(salary*0.05);
        final_salary=salary-tax-((full_attendance - attendance)*8*hourlyPaid)+(1.5*hourlyPaid*ot);
    }else if(salary<2125){
        tax=(salary*0.1);
        final_salary=salary-tax-((full_attendance - attendance)*8*hourlyPaid)+(1.5*hourlyPaid*ot);
    }else if(salary<=3125){
        tax=(salary*0.15);
        final_salary=salary-tax-((full_attendance - attendance)*8*hourlyPaid)+(1.5*hourlyPaid*ot);
    }else if(salary>3125){
        tax=(salary*0.2);
        final_salary=salary-tax-((full_attendance - attendance)*8*hourlyPaid)+(1.5*hourlyPaid*ot);
    }
    cout << left
        << setw(S_space) << tax
        << setw(default_space) << final_salary << endl;

    ifstream check_file(final_salary_file);
    bool isEmpty = (check_file.peek()) == EOF;
    check_file.close();

    
    ofstream file(final_salary_file,ios::app);

    if(!file.is_open()){
        cout << "not open"<< endl;
        return;
    }
    file << final_salary << "," << endl;
    file.close();

}


#endif
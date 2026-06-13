#ifndef SALARY_AFTER_DEDUCTION_H
#define SALARY_AFTER_DEDUCTION_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void salary_after_deduction(double salary,double ot,double attendance, double hourlyPaid, string final_salary_file){
    const int default_space = 8;
    const int S_space = 12;
    const int M_space = 18;
    const int L_space = 24;
    double final_salary, tax;
    if(salary<375){
        tax=(salary*0);
        final_salary=salary-tax-(attendance*8*hourlyPaid)+(1.5*hourlyPaid*ot);
    }else if(salary<500){
        tax=(salary*0.05);
        final_salary=salary-tax-(attendance*8*hourlyPaid)+(1.5*hourlyPaid*ot);
    }else if(salary<2125){
        tax=(salary*0.1);
        final_salary=salary-tax-(attendance*8*hourlyPaid)+(1.5*hourlyPaid*ot);
    }else if(salary<=3125){
        tax=(salary*0.15);
        final_salary=salary-tax-(attendance*8*hourlyPaid)+(1.5*hourlyPaid*ot);
    }else if(salary>3125){
        tax=(salary*0.2);
        final_salary=salary-tax-(attendance*8*hourlyPaid)+(1.5*hourlyPaid*ot);
    }
    double temp = final_salary;
    cout<<left
        <<setw(S_space)<<tax
        <<setw(default_space)<<final_salary<<endl;

    double total_salary = 0;
    total_salary += temp;
    cout << "temp: " << temp<<endl ;
    cout << "total: " << total_salary<<endl ;

    ofstream file(final_salary_file, ios::trunc);
    if(!file.is_open()){
        cout << "File not open!" << endl;
        return;
    }

    file << total_salary;


    file.close();
}
#endif
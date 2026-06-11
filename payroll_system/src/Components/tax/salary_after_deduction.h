#ifndef SALARY_AFTER_DEDUCTION_H
#define SALARY_AFTER_DEDUCTION_H
#include <iostream>
#include <iomanip>
using namespace std;
void salary_after_deduction(double salary,double ot,double attendance, double hourlyPaid){
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
    cout<<left
        <<setw(S_space)<<tax
        <<setw(default_space)<<final_salary<<endl;
}
#endif
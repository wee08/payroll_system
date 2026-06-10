#ifndef CALCULATE_REDUCTION_H
#define CALCULATE_REDUCTION_H
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
void salary_after_deduction(double salary,double ot,double attendance, double hourlyPaid){
    double final_salary, tax;
    if(salary<375){
        tax=(salary*0);
        cout<<"Tax = "<<tax<<endl;
        final_salary=salary-tax-(attendance*8*hourlyPaid)+(1.5*hourlyPaid*ot);
    }else if(salary>=375 && salary<500){
        tax=(salary*0.05);
        cout<<"Tax = "<<tax<<endl;
        final_salary=salary-tax-(attendance*8*hourlyPaid)+(1.5*hourlyPaid*ot);
    }else if(salary>=500 && salary<2125){
        tax=(salary*0.1);
        cout<<"Tax = "<<tax<<endl;
        final_salary=salary-tax-(attendance*8*hourlyPaid)+(1.5*hourlyPaid*ot);
    }else if(salary>=2125 && salary<=3125){
        tax=(salary*0.15);
        cout<<"Tax = "<<tax<<endl;
        final_salary=salary-tax-(attendance*8*hourlyPaid)+(1.5*hourlyPaid*ot);
    }else if(salary>3125){
        tax=(salary*0.2);
        cout<<"Tax = "<<tax<<endl;
        final_salary=salary-tax-(attendance*8*hourlyPaid)+(1.5*hourlyPaid*ot);
    }
    cout<<"Salary for the month(After Tax): "<<final_salary<<endl;
    cout<<endl;
}
void Monthly_Salary(){
    string line, first="",monthly_salary="",last="",hourly_paid="",overtime="",attendance="",mid="";
    int location=0; 
    double salary,hour_paid,OT,absence;
    ifstream monthlySalary;
    monthlySalary.open("attendance.csv");
    getline(monthlySalary,line);
    while(getline(monthlySalary, line)){
        for(int i=0;i<5;i++){
            location=line.find(",");
            first=line.substr(0,location);
            line=line.substr(location+1,line.length());
            if(i==1){
                cout<<"Name: "<<first<<endl;
            }
        }

        location=line.find(",");
        monthly_salary=line.substr(0,location);
        line=line.substr(location+1,line.length());
        location=line.find(",");
        hourly_paid=line.substr(0,location);
        line=line.substr(location+1,line.length());
        location=line.find(",");
        mid=line.substr(0, location);
        line=line.substr(location+1,line.length());
        location=line.find(",");
        overtime=line.substr(0,location);
        line=line.substr(location+1,line.length());
        location=line.find(",");
        attendance=line.substr(0,location);
        last=line.substr(location+1,line.length());
        
        cout<<"Monthly Salary: "<<monthly_salary<<endl;
        cout<<"Hourly Paid: "<<hourly_paid<<endl;
        cout<<"Overtime: "<<overtime<<endl;
        cout<<"Attendance: "<<attendance<<endl;
        
        salary=stod(monthly_salary);
        hour_paid=stod(hourly_paid);
        OT=stod(overtime);
        absence=stod(attendance);    
        
        salary_after_deduction(salary,OT,absence,hour_paid);
    }

    monthlySalary.close();
}
#endif
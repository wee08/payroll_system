#ifndef CALCULATE_REDUCTION_H
#define CALCULATE_REDUCTION_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "./salary_after_deduction.h"
#include "../IO/write_CSV.h"
using namespace std;

void calculate_reductoin(string filename,string final_salary_file){
    const int default_space = 8;
    const int S_space = 12;
    const int M_space = 18;
    const int L_space = 24;
    string line, first="",monthly_salary="",last="",hourly_paid="",overtime="",attendance="",mid="";
    int location=0; 
    double salary,hour_paid,OT,absence;
    ifstream monthlySalary;
    monthlySalary.open(filename);

    //skip first row of csv file
    getline(monthlySalary,line);

    //display first row
    cout<<left
        <<setw(L_space)<<"Name"
        <<setw(L_space)<<"Monthly Salary($)"
        <<setw(M_space)<<"Hourly Paid($)"
        <<setw(S_space)<<"Overtime"
        <<setw(M_space)<<"Attendance"
        <<setw(S_space)<<"Tax($)"
        <<setw(default_space)<<"Salary for the month(After Tax)($)"<<endl;
    cout<< string(143,'-')<<endl;

    while(getline(monthlySalary, line)){
        for(int i=0;i<5;i++){
            location=line.find(",");
            first=line.substr(0,location);
            line=line.substr(location+1,line.length());
            if(i==1){
                cout<<left
                    <<setw(L_space)<<first;
            }
        }

        //take data from monthly salary column
        location=line.find(",");
        monthly_salary=line.substr(0,location);
        line=line.substr(location+1,line.length());

        //take data from hourly paid column
        location=line.find(",");
        hourly_paid=line.substr(0,location);
        line=line.substr(location+1,line.length());

        //skip data from phone column
        location=line.find(",");
        mid=line.substr(0, location);
        line=line.substr(location+1,line.length());

        //take data from overtime column
        location=line.find(",");
        overtime=line.substr(0,location);
        line=line.substr(location+1,line.length());

        //take data from attendance column
        location=line.find(",");
        attendance=line.substr(0,location);
        last=line.substr(location+1,line.length());
        
        salary=stod(monthly_salary);
        hour_paid=stod(hourly_paid);
        OT=stod(overtime);
        absence=stod(attendance);    
        
        cout<<left
            <<setw(L_space)<<salary
            <<setw(M_space)<<hour_paid
            <<setw(S_space)<<OT
            <<setw(M_space)<<absence;

        salary_after_deduction(salary,OT,absence,hour_paid,final_salary_file);
    }
    calcuate_total_salary(final_salary_file);


    monthlySalary.close();    
}
#endif
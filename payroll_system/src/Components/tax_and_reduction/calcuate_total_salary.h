#ifndef CALCULATE_TOTAL_SALARY_H
#define CALCULATE_TOTAL_SALARY_H
#include <iostream>
#include <fstream>
using namespace std;

void calcuate_total_salary(string final_salary_file){
    string line="";
    double final_salary;
    ifstream final_salary_str;
    final_salary_str.open(final_salary_file);
    while(getline(final_salary_str, line)){
        final_salary=stod(line);
    }
}

#endif
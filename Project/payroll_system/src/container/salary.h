#ifndef SALARY_H 
#define SALARY_H

#include <iostream>

#include "../Components/tax_and_reduction/calculate_reduction.h"
using namespace std;

void salary(string file_name,string final_salary_file){
    calculate_reduction(file_name,final_salary_file);
    
}

#endif
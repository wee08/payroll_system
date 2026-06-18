#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include "../Components/pay_schedule/pay_schedule.h"
#include "../Model/Linked_list.h"
using namespace std;
void payment(string attendance_file,string final_salary_file){
    Node * head = NULL;
    pay_schedule(head, attendance_file, final_salary_file);
}

#endif
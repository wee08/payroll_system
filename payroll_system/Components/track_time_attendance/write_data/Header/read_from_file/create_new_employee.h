#ifndef CREATE_NEW_EMPLOYEE_H
#define CREATE_NEW_EMPLOYEE_H

#include <iostream>
// Internal
#include "../structure.h"

using namespace std;

Employee * create_new_employee(){
    Employee * e = new Employee();

    e->head = nullptr;
    e->tail = nullptr;
    e->size = 0;

    return e;
} 

#endif

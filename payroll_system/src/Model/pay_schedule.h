#ifndef PAY_SCHEDULE_H
#define PAY_SCHEDULE_H

#include <iostream>
#include <string>
#include <fstream>

#include "./structure.h"
#include "../Components/IO/read_CSV.h"

using namespace std;

struct Employee {
    int workingDay;
    string names;
    double pay;
};

struct Node {
    Employee data;
    Node* next;
};

void addEmployee(Node *& head, int workingDay, string names, double pay) {
    Node * newNode = new Node();
    newNode->data.workingDay = workingDay;
    newNode->data.names = names;
    newNode->data.pay = pay;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void swapEmployee(Employee& a, Employee& b) {
    Employee temp = a;
    a = b;
    b = temp;
}

void SortBubble(Node* head) {
    if(head == NULL)
        return;

    bool state;

    do {
        state = false;
        Node* current = head;

        while(current->next != NULL) {
            if(current->data.workingDay > current->next->data.workingDay) {
                swapEmployee(current->data, current->next->data);
                state = true;
            }
            current = current->next;
        }
    } while(state);
}

void function(){
    string file_name = "../../Data/employee_list.csv";
    Employee * emp = read_CSV(file_name);
    ifstream files(file_name);
    string names;
    int id;
    double salary;
    while (files >> ar->name >> ar->ID >> ar->salary){
        cout << "Name:" << names;
        cout << "ID" << id;
        cout << "Salary: $" << salary<< endl;
    }
    files.close();
}
#endif
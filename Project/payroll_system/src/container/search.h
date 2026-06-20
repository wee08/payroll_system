#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>

#include "../Components/searching/search_by_id.h"
#include "../Model/structure.h"
using namespace std;

void search(string attendance_file){
    Employee * e = read_CSV(attendance_file);
    int choice;
    string ID;

    while(true){
        if(e->size == 0){
            cout << "Employee doesn't enter their attendance yet!" << endl;
            return;
        }
        cout << endl;
        cout << "1 -> search by id." << endl;
        cout << "0 -> Exit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        if(choice == 1){
            cout << "Enter ID: ";
            cin >> ID;
            cout << endl;
            search_by_id(attendance_file,ID);
        }else if(choice == 0){
            break;
        }else{
            cout << "Invalid choice!!!" << endl;
        }
    }
}

#endif
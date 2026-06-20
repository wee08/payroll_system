#ifndef CONVERT_ID_H
#define CONVERT_ID_H

#include <iostream>
#include <string>
using namespace std;

string convert_ID(string ID){
    for(char& c : ID){
        c = toupper(c);
    }

    return ID;
}

#endif
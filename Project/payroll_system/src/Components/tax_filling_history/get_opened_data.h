#ifndef GET_OPENED_DATA_H
#define GET_OPENED_DATA_H

#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

string getOpenedDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    stringstream ss;
    ss << (ltm->tm_year + 1900) << "-" 
       << setfill('0') << setw(2) << (ltm->tm_mon + 1) << "-20";
    return ss.str();
}

#endif
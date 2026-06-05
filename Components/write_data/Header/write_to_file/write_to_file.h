#ifndef WRITE_TO_FILE_H
#define WRITE_TO_FILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../structure.h"

using namespace std;

void write_CSV(string file_name){
    Employee * e;
    Attendance_record * ar = e->head;
    ofstream file(file_name);
    
    string line;
    int locatoin = 0;
    stringstream ss(line);

    

    file.close();

}


#endif
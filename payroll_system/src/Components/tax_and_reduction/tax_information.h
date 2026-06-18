#ifndef TAX_INFORMATION_H
#define TAX_INFORMATION_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;
void tax_information(string file_name){ 
    const int default_space = 8;
    const int S_space = 12;
    const int M_space = 18;
    const int L_space = 24;
    string line="";
    string salary="", tax="";
    int location=0;
    ifstream tax_info;
    
    tax_info.open(file_name);
    cout<<string(50,'=')<<endl;
    while(getline(tax_info, line)){
        location=line.find(",");
        salary=line.substr(0,location);
        tax=line.substr(location+1,line.length());
        cout<<left
        <<setw(L_space)<<salary
        <<tax<<endl;
    }
    cout<<string(50,'=')<<endl;
    tax_info.close();
};
#endif 
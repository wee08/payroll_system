
#include <iostream>
#include <string>
using namespace std;

string convert_ID(string ID){
    for(char& c : ID){
        c = toupper(c);
    }

    return ID;
}

int main(){
    string id = convert_ID("f1");
    cout << id;
    
}
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream file;

    file.open("data.csv");

    file << "Dara,12" ;

    file.close();
}
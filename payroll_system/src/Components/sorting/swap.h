#ifndef SWAP_H
#define SWAP_H

#include <string>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}



#endif
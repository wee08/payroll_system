#include <iostream>
#include <ctime>
using namespace std;
int main() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    int month = now->tm_mon + 1;  // tm_mon is 0-indexed (0 = January)
    cout << "Current month: " << month << "\n";

    return 0;
}
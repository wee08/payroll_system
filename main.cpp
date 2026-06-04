#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream file("data.csv");

    // Header
    file << "id,name,monthly_salary\n";

    // Data rows
    file << "1,Alice,5000\n";
    file << "2,Bob,6000\n";
    file << "3,Charlie,5500\n";

    file.close();

    cout << "CSV file created successfully!" << endl;

    return 0;
}
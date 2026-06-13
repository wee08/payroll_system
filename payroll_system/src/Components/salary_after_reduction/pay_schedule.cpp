#include <iostream>
#include <string>

#include "../../Model/structure.h"
#include "../IO/read_CSV.h"
#include "../../Model/structure.h"
using namespace std;

string file_path = "../../../Data/attendance.csv";
Employee * att_l = read_CSV(file_path);

void swapPayday(Payday& a, Payday& b) {
    Payday temp = a;
    a = b;
    b = temp;
}

void display(Node* head) {
    double total = 0;
    Node* temp = head;
    Attendance_record * ar = att_l->head;
    cout << "Name, Days, Pay\n";

    while(ar != nullptr) {
        double salary = temp->data.workingDay * temp->data.pay;

        cout << temp->data.name << "\t"
             << temp->data.workingDay << "\t"
             << salary << endl;

        total += salary;

        ar = ar->next;
    }

    cout << "Total = $" << total << endl;
}


int main() {
    Node* head = NULL;

    display(head);

    return 0;
}

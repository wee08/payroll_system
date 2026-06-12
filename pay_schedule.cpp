#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int workingDay;
    string name;
    double pay;
};

struct Node {
    Employee data;
    Node* next;
};

void addEmployee(Node*& head, int workingDay, string name, double pay) {
    Node* newNode = new Node;
    newNode->data.workingDay = workingDay;
    newNode->data.name = name;
    newNode->data.pay = pay;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void swapEmployee(Employee& a, Employee& b) {
    Employee temp = a;
    a = b;
    b = temp;
}

void SortBubble(Node* head) {
    if(head == NULL)
        return;

    bool state;

    do {
        state = false;
        Node* current = head;

        while(current->next != NULL) {
            if(current->data.workingDay > current->next->data.workingDay) {
                swapEmployee(current->data, current->next->data);
                state = true;
            }
            current = current->next;
        }
    } while(state);
}

void display(Node* head) {
    double total = 0;
    Node* temp = head;
    cout << "Name, Days, Pay\n";

    while(temp != NULL) {
        double salary = temp->data.workingDay * temp->data.pay;

        cout << temp->data.name << "\t"
             << temp->data.workingDay << "\t"
             << salary << endl;

        total += salary;
        temp = temp->next;
    }

    cout << "Total = $" << total << endl;
}

int main() {
    Node* head = NULL;

    addEmployee(head, 22, "Sovan", 20);
    addEmployee(head, 20, "Dara", 20);
    addEmployee(head, 18, "Rith", 20);
    addEmployee(head, 21, "Vannak", 20);
    addEmployee(head, 19, "Nita", 20);

    SortBubble(head);

    display(head);

    return 0;
}

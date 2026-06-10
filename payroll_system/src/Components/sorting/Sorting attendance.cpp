#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int attendance;
    string name;
    double salary;
};

struct Node {
    Employee data;
    Node* next;
};

void addEmployee(Node*& head, int attendance, string name, double salary) {
    Node* newNode = new Node;
    newNode->data.attendance = attendance;
    newNode->data.name = name;
    newNode->data.salary = salary;
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

void SortBubble(Node* head, int choice) {
    if(head == NULL)
        return;

    bool state;

    do {
        state = false;
        Node* current = head;

        while(current->next != NULL) {

            // Small to Big
            if(choice == 1 &&
               current->data.attendance > current->next->data.attendance) {
                swapEmployee(current->data, current->next->data);
                state = true;
            }

            // Big to Small
            if(choice == 2 &&
               current->data.attendance < current->next->data.attendance) {
                swapEmployee(current->data, current->next->data);
                state = true;
            }

            current = current->next;
        }
    } while(state);
}

void display(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << "Attendance: " << temp->data.attendance;
        cout << ", Name: " << temp->data.name;
        cout << ", Salary: " << temp->data.salary;
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    int choice;

    addEmployee(head, 11, "Sean Manutnithya", 100);
    addEmployee(head, 3, "Sean Manutnithya", 200);
    addEmployee(head, 4, "Sean Manutnithya", 300);
    addEmployee(head, 5, "Sean Manutnithya", 400);

    cout << "1. Small to Big\n";
    cout << "2. Big to Small\n";
    cout << "Enter your choice: ";
    cin >> choice;

    SortBubble(head, choice);

    cout << "\nEmployee Attendance:\n";
    display(head);

    return 0;
}

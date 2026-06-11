#include <iostream>
using namespace std;

struct Employee {
    int id;
    Employee* next;
};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void addEmployee(Employee*& head, int id) {
    Employee* newNode = new Employee;
    newNode->id = id;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        Employee* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void SortBubble(Employee* head, int size) {
    if(head == NULL)
        return;

    bool state;

    do {
        state = false;
        Employee* current = head;

        while(current->next != NULL) {
            if(current->id > current->next->id) {
                swap(&current->id, &current->next->id);
                state = true;
            }

            current = current->next;
        }

    } while(state);
}

int main() {
    Employee* head = NULL;

    addEmployee(head, 7);
    addEmployee(head, 8);
    addEmployee(head, 4);
    addEmployee(head, 3);

    SortBubble(head, 4);

    Employee* temp = head;
    while(temp != NULL) {
        cout << temp->id << " ";
        temp = temp->next;
    }

    cout << endl;
    // Search by ID
    int searchID;
    cout << "Enter ID to search: ";
    cin >> searchID;

    temp = head;
    while(temp != NULL) {
        if(temp->id == searchID) {
            cout << "Employee ID found!" << endl;
            return 0;
        }
        temp = temp->next;
    }

    cout << "Employee ID not found!" << endl;

    return 0;
}

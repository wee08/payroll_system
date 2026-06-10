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

void SortBubble(Employee* head, int size) {
    bool state;
    Employee *p1, *p2;

    for(int i = 0; i < size - 1; i++) {
        state = false;

        p1 = head;
        p2 = head->next;

        for(int j = 0; j < size - i - 1; j++) {
            if(p1->id > p2->id) {
                swap(&p1->id, &p2->id);
                state = true;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        if(state == false) {
            break;
        }
    }
}

int main() {
    Employee* head = new Employee{7, NULL};
    head->next = new Employee{8, NULL};
    head->next->next = new Employee{4, NULL};
    head->next->next->next = new Employee{3, NULL};

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

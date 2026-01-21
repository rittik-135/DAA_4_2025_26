#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

Node* head = NULL;

void insert(int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

void displayForward() {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void displayBackward() {
    if (head == NULL) return;

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    while (current != NULL) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

void deleteNode(int val) {
    if (head == NULL) return;

    Node* current = head;

    if (current->data == val) {
        head = current->next;
        if (head != NULL)
            head->prev = NULL;
        delete current;
        return;
    }

    while (current != NULL && current->data != val) {
        current = current->next;
    }

    if (current == NULL) return;

    if (current->next != NULL)
        current->next->prev = current->prev;

    current->prev->next = current->next;
    delete current;
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    displayForward();
    displayBackward();

    deleteNode(20);
    displayForward();

    return 0;
}
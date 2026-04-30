#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* topNode = NULL;

void push(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = topNode;
    topNode = temp;
}

void pop() {
    if (topNode == NULL) {
        cout << "Stack Underflow\n";
        return;
    }
    Node* temp = topNode;
    topNode = topNode->next;
    delete temp;
}

void peek() {
    if (topNode == NULL) {
        cout << "Stack is Empty\n";
        return;
    }
    cout << topNode->data << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    pop();
    peek();
    return 0;
}
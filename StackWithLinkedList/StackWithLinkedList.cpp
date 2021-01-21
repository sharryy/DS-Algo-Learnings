#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Stack {
private:
    Node *top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int x);

    int pop();

    void display();

    int stackTop();

    int isEmpty();

    int peek(int index);

    int length();
};

void Stack::push(int x) {
    Node *n = new Node;
    n->data = x;
    n->next = top;
    top = n;
}

int Stack::pop() {
    int x = -1;
    if (isEmpty()) {
        cout << "Stack Is Empty.";
    } else {
        x = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
    }
    return x;
}

void Stack::display() {
    Node *temp = top;
    while (temp) {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}

int Stack::stackTop() {
    if (isEmpty()) {
        cout << "Stack is Empty!" << endl;
        return -1;
    } else {
        return top->data;
    }
}

int Stack::isEmpty() {
    if (top == nullptr)
        return 1;
    else
        return 0;
}

int Stack::peek(int index) {
    Node *temp = top;
    int x = -1;

    if (index > length()) {
        cout << "Invalid Number" << endl;
    } else {
        for (int i = 0; temp != nullptr && i < index - 1; i++) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            x = temp->data;
        }
    }
    return x;
}

int Stack::length() {
    Node *temp;
    int count = 0;

    if (top != nullptr) {
        temp = top;
        while (temp) {
            count++;
            temp = temp->next;
        }
    }
    return count;
}

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70);

    stack.display();
    
    return 0;
}

#include <iostream>

using namespace std;

template<class T>
class Stack {
    T *st;
    int size{};
    int top;

public:
    Stack() {
        size = 10;
        top = -1;
        st = new T[size];
    }

    explicit Stack(int size) {
        this->size = size;
        top = -1;
        st = new T[size];
    }

    void push(T x);

    T pop();

    T peek(int index);

    int stackTop();

    int isEmpty();

    int isFull();

    void Display();

};

template<class T>
void Stack<T>::push(T x) {
    if (isFull()) {
        cout << "Stack Overflow Error!" << endl;
    } else {
        top++;
        st[top] = x;
    }
}

template<class T>
T Stack<T>::pop() {
    T x = -1;
    if (isEmpty()) {
        cout << "Stack UnderFlow Error!" << endl;
    } else {
        x = st[top];
        top--;
    }
    return x;
}

template<class T>
T Stack<T>::peek(int index) {
    T x = -1;
    if (top - index + 1 < 0) {
        cout << "Invalid Number!" << endl;
    } else {
        x = st[top - index + 1];
    }
    return x;
}

template<class T>
int Stack<T>::stackTop() {
    if (isEmpty())
        return -1;
    else
        return st[top];
}

template<class T>
int Stack<T>::isEmpty() {
    return top == -1;
}

template<class T>
int Stack<T>::isFull() {
    return top == size - 1;
}

template<class T>
void Stack<T>::Display() {
    for (int i = top; i >= 0; --i) {
        cout << st[i] << endl;
    }
}

int main() {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);

    stack.Display();

}

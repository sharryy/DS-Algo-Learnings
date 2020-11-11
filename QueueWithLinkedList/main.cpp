#include <iostream>

using namespace std;

template<class T>
class QueueLL {
    struct Node {
        T data;
        Node *next;
    } *front = nullptr, *rear = nullptr;

public:
    void enqueue(int x);

    T dequeue();

    void display();
};

template<class T>
void QueueLL<T>::enqueue(int x) {
    struct Node *p;
    p = new Node;
    if (p == nullptr) {
        cout << "Queue Is Full" << endl;
    } else {
        p->data = x;
        p->next = nullptr;
        if (front == nullptr)
            front = rear = p;
        else {
            rear->next = p;
            rear = p;
        }
    }
}

template<class T>
T QueueLL<T>::dequeue() {
    T x = -1;
    struct Node *t;

    if (front == nullptr)
        cout << "Queue Is Empty\n" << endl;
    else {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

template<class T>
void QueueLL<T>::display() {
    struct Node *p = front;
    while (p) {
        cout << p->data << endl;
        p = p->next;
    }
    cout << endl;
}

int main() {
    QueueLL<int> queueLl;

    queueLl.enqueue(10);
    queueLl.enqueue(20);
    queueLl.enqueue(30);
    queueLl.enqueue(40);
    queueLl.enqueue(50);

    queueLl.display();


}

#include <iostream>

using namespace std;

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;

    Queue() {
        front = rear = 0;
        size = 10;
        Q = new int[size];
    }

    explicit Queue(int size) {
        front = rear = 0;
        this->size = size;
        Q = new int[size];
    }

    void enqueue(int x);

    int dequeue();

    void display() const;
};

void Queue::enqueue(int x) {
    if ((rear + 1) % size == front) {
        cout << "Queue Is Full." << endl;
    } else {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}

int Queue::dequeue() {
    int x = -1;
    if (front == rear) {
        cout << "Queue is Empty" << endl;
    } else {
        front = (front + 1) % size;
        x = Q[front + 1];
    }
    return x;
}

void Queue::display() const {
    int i = front + 1;

    do {
        cout << Q[i] << endl;
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
}

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.dequeue();

    q.enqueue(90);

    q.display();

}
#include <iostream>

using namespace std;

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;

    Queue() {
        front = rear = -1;
        size = 10;
        Q = new int[size];
    }

    explicit Queue(int size) {
        front = rear = -1;
        this->size = size;
        Q = new int[size];
    }

    void enqueue(int x);

    int dequeue();

    void display() const;
};

void Queue::enqueue(int x) {
    if (rear == size - 1) {
        cout << "Queue Is Full." << endl;
    } else {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue() {
    int x = -1;
    if (front == rear) {
        cout << "Queue is Empty" << endl;
    } else {
        x = Q[front + 1];
        front++;
    }
    return x;
}

void Queue::display() const {
    for (int i = front + 1; i <= rear; ++i) {
        cout << Q[i] << endl;
    }
}

int main() {
    Queue queue(10);

    queue.enqueue(76);
    queue.enqueue(123);
    queue.enqueue(69);

    queue.display();
}

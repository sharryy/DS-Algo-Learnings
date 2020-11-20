#include "iostream"
#include "algorithm"

using namespace std;

struct Process {
    int arrivingTime;
    int ProcessLength;
    int processID;
};

class LinkedList {
public:
    class ProcessNode;

    LinkedList() {
        head = tail = nullptr;
    }

    ~LinkedList() = default;

    ProcessNode *head;
    ProcessNode *tail;

    void addToTail(ProcessNode processNode);

    void removeFromHead();

    void display() const;

    int length();
};

class LinkedList::ProcessNode {
public:
    Process process;
    ProcessNode *next;
};

void LinkedList::addToTail(LinkedList::ProcessNode processNode) {
    struct ProcessNode *process;

    process = new ProcessNode;
    process->process.ProcessLength = processNode.process.ProcessLength;
    process->process.processID = processNode.process.processID;
    process->process.arrivingTime = processNode.process.arrivingTime;
    process->next = nullptr;

    if (!head) {
        head = process;
        tail = process;
        process->next = process;
    } else {
        tail->next = process;
        tail = tail->next;
        tail->next = head;
    }

}

void LinkedList::display() const {
    struct ProcessNode *pointer;
    pointer = head;

    do {
        if (pointer) {
            cout << pointer->process.processID << " " << pointer->process.ProcessLength << " "
                 << pointer->process.arrivingTime
                 << endl;
            pointer = pointer->next;
        }
    } while (pointer != head);
}

void LinkedList::removeFromHead() {
    struct ProcessNode *temp;
    temp = head;

    head = head->next;
    tail->next = head;
    delete temp;
}

int LinkedList::length() {
    struct ProcessNode *ptr;
    int count = 0;

    ptr = head;
    do {
        if (ptr) {
            ptr = ptr->next;
            count++;
        }
    } while (ptr != nullptr && ptr != head);

    return count;

}

int GLOBAL_TIME_QUANTUM = 5;

void startScheduling(LinkedList list) {
    while (list.head != nullptr) {
        if (list.head->process.ProcessLength > 0) {
            list.head->process.ProcessLength = list.head->process.ProcessLength - GLOBAL_TIME_QUANTUM;
            cout << "1 Time Quantum Passed" << endl;
            if (list.head->process.ProcessLength <= 0) {
                cout << "Process " << list.head->process.processID << " finished" << endl;
                list.removeFromHead();
            } else {
                int processID = list.head->process.processID;
                int processLength = list.head->process.ProcessLength;
                int arrivingTime = list.head->process.arrivingTime;
                cout << "Process " << processID << " Added in Queue Again" << endl;
                list.removeFromHead();
                LinkedList::ProcessNode processNode = {arrivingTime, processLength, processID};
                list.addToTail(processNode);
            }
        } else {
            break;
        }
    }
}

int main() {
    LinkedList list;

    LinkedList::ProcessNode processNode1
            = {0, 7, 1};

    LinkedList::ProcessNode processNode2
            = {5, 10, 2};

    LinkedList::ProcessNode processNode3
            = {10, 25, 3};

    LinkedList::ProcessNode processNode4
            = {15, 15, 4};

    LinkedList::ProcessNode processNode5
            = {20, 13, 5};

    list.addToTail(processNode1);
    list.addToTail(processNode2);
    list.addToTail(processNode3);
    list.addToTail(processNode4);
    list.addToTail(processNode5);

    cout << "<-----Scheduling " << list.length() << " Process" << "----->" << endl << endl;

    startScheduling(list);
};
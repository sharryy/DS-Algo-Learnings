#include <iostream>

using namespace std;

class FloatList {
public:
    struct ListNode {
        float value;
        struct ListNode *next;
    };

    ListNode *head;

public:
    FloatList() {
        head = nullptr;
    }

    ~FloatList() = default;

    void appendNode(float num);

    void displayList() const;

    void deleteNode(float num);

    void RecursiveDisplay(ListNode *p);

    int length() const;

    int recursiveLength(ListNode *p);

    double sumOfElements() const;

    float max() const;

    float min() const;

    float searchNumber(float num) const;

    bool isSorted() const;
};

void FloatList::appendNode(float num) {
    ListNode *newNode, *nodePtr;

    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    } else {
        nodePtr = head;
        while (nodePtr->next) {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}

void FloatList::deleteNode(float num) {
    ListNode *nodePtr, *previousNode;

    if (!head) {
        return;
    }
    if (head->value == num) {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    } else {
        nodePtr = head;
        while (nodePtr != nullptr && nodePtr->value != num) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        previousNode->next = nodePtr->next;
        delete nodePtr;
    }
}

void FloatList::displayList() const {
    ListNode *nodePtr;
    nodePtr = head;
    while (nodePtr) {
        cout << nodePtr->value << endl;
        nodePtr = nodePtr->next;
    }
}

void FloatList::RecursiveDisplay(FloatList::ListNode *p) {
    if (p != nullptr) {
        RecursiveDisplay(p->next);
        cout << p->value << endl;
    }
}

int FloatList::length() const {
    ListNode *ptr;
    int count = 0;
    ptr = head;
    while (ptr) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

int FloatList::recursiveLength(FloatList::ListNode *p) {
    if (p)
        return recursiveLength(p->next) + 1;
    else
        return 0;
}

double FloatList::sumOfElements() const {
    ListNode *ptr;
    ptr = head;
    double sum = 0;

    while (ptr) {
        sum = sum + ptr->value;
        ptr = ptr->next;
    }
    return sum;
}

float FloatList::max() const {
    float max = INT16_MIN;
    ListNode *ptr;
    ptr = head;

    while (ptr) {
        if (ptr->value > max) {
            max = ptr->value;
        }
        ptr = ptr->next;
    }

    return max;
}

float FloatList::min() const {
    float min = INT16_MAX;
    ListNode *ptr;
    ptr = head;

    while (ptr) {
        if (ptr->value < min) {
            min = ptr->value;
        }
        ptr = ptr->next;
    }
    return min;
}

float FloatList::searchNumber(float num) const {
    ListNode *ptr;
    ptr = head;
    float number = 0;
    int count = 0;
    bool check = false;

    while (ptr) {
        if (ptr->value == num) {
            count++;
            check = true;
            number = num;
            break;
        } else {
            count++;
        }
        ptr = ptr->next;
    }
    if (check) {
        cout << "Element Found at Node: " << count << endl;
    } else {
        cout << "Nothing Found." << endl;
    }
    return number;
}

bool FloatList::isSorted() const {
    ListNode *ptr;
    float x;
    ptr = head;

    while (ptr) {
        if (ptr->value < x) {
            return false;
        }
        x = ptr->value;
        ptr = ptr->next;
    }
    return true;
}


int main() {
    FloatList list;

    list.appendNode(10);
    list.appendNode(20);
    list.appendNode(30);
    list.appendNode(40);
    list.appendNode(50);
    list.appendNode(80);
    list.appendNode(90);

    if (list.isSorted()) {
        cout << "List IS Sorted" << endl;
    } else {
        cout << "List Is Not-Sorted" << endl;
    }

}

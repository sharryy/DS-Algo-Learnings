//Importing Required Header Files
#include <iostream>
#include <climits>
#include <cmath>

//Using standard namespace
using namespace std;

class BinaryHeap {
    //Defining Attributes
public:
    int *heapArray; //Pointer To Array
    int capacity;   //Total Capacity of Array
    int heap_size;  //Occupied Memory Out of Total Memory

    //Defining Headers of Required Methods
public:
    explicit BinaryHeap(int capacity);

    void minHeapify(int);

    static int parent(int i) { return (i - 1) / 2; }

    static int left(int i) { return (2 * i + 1); }

    static int right(int i) { return (2 * i + 2); }

    int extractMin();

    void decreasePriority(int i, int value) const;

    [[nodiscard]] int top() const {
        if (heapArray[0] < 50000) return heapArray[0]; //Considering >50000 values as Garbage
        else return -1;
    }

    void pop();

    void push(int k);

    [[nodiscard]] bool isEmpty() const { return heap_size == 0; }

    void buildHeap(int array[], int size);

    void printHeap() const;

    [[nodiscard]] int height() const;

    void heapify(int *arr, int size, int i);
};

/*
 * Initializing Constructor Outside Class
 */
BinaryHeap::BinaryHeap(int cap) {
    heap_size = 0;
    capacity = cap;
    heapArray = new int[cap];
}

/*
 * Pushing an Element in Heap
 */
void BinaryHeap::push(int k) {
    if (heap_size == capacity) {
        cout << "\nOverflow: Could not push\n";
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    heapArray[i] = k;

    while (i != 0 && heapArray[parent(i)] > heapArray[i]) {
        swap(heapArray[i], heapArray[parent(i)]);
        i = parent(i);
    }
}

/*
 * Helper Function While Popping out Element from Heap
 */
void BinaryHeap::decreasePriority(int i, int value) const {
    heapArray[i] = value;
    while (i != 0 && heapArray[parent(i)] > heapArray[i]) {
        swap(heapArray[i], heapArray[parent(i)]);
        i = parent(i);
    }
}

/*
 * Helper Function While Removing
 */
int BinaryHeap::extractMin() {
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1) {
        heap_size--;
        return heapArray[0];
    }

    int root = heapArray[0];
    heapArray[0] = heapArray[heap_size - 1];
    heap_size--;
    minHeapify(0);

    return root;
}

/*
 * Popping element from Heap
 */
void BinaryHeap::pop() {
    decreasePriority(0, INT_MIN);
    extractMin();
}

/*
 * Business Logic of Min Heapify
 */
void BinaryHeap::minHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && heapArray[l] < heapArray[i])
        smallest = l;
    if (r < heap_size && heapArray[r] < heapArray[smallest])
        smallest = r;
    if (smallest != i) {
        swap(heapArray[i], heapArray[smallest]);
        minHeapify(smallest);
    }
}

/*
 * Converting an array of Numbers into Heap
 */
void BinaryHeap::buildHeap(int *array, int size) {
    int startIndex = (size / 2) - 1;

    for (int i = startIndex; i >= 0; --i) {
        heapify(array, size, i);
    }
}

/*
 * Printing Heap to Console
 */
void BinaryHeap::printHeap() const {
    cout << "Minimum Heap : " << endl;

    for (int i = 0; i < heap_size; ++i) {
        cout << heapArray[i] << " ";
    }
}

/*
 * Printing Height of Heap (Complete Binary Tree)
 */
int BinaryHeap::height() const {
    return ceil(log2(heap_size + 1) - 1);
}

/*
 * Converting Array of Numbers to Heap
 */
void BinaryHeap::heapify(int *arr, int size, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[l] < arr[smallest])
        smallest = l;
    if (r < size && arr[r] < arr[smallest])
        smallest = r;

    //Recursively Calling Heapify
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, size, smallest);
    }
}


int main() {
    BinaryHeap binaryHeap(20);
    int option, input;

    /*
     * User MENU
     */
    do {
        cout << endl << "What operation do you want to perform? " <<
             " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Smallest Element of Heap (top)" << endl;
        cout << "2. Remove Element." << endl;
        cout << "3. Add Element." << endl;
        cout << "4. Size of Heap." << endl;
        cout << "5. Height of Heap." << endl;
        cout << "6. Total Capacity of Heap." << endl;
        cout << "7. Print Heap." << endl;
        cout << "8. Clear Screen." << endl;
        cout << "9. Heapify Array of Numbers." << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;

        switch (option) {
            case 0:
                break;
            case 1:
                binaryHeap.top() == -1 ? cout << "Heap is  Empty. Try Adding some values." << endl : cout
                        << "Smallest Element : " << binaryHeap.top() << endl;
                break;
            case 2:
                binaryHeap.heapArray[0] <= 5000 ? cout << binaryHeap.heapArray[0] << " removed" << endl : cout
                        << "Heap Empty." << endl;
                binaryHeap.pop();
                break;
            case 3: {
                cout << "INSERT" << endl;
                cout << "Enter the Number of values you want to Add?" << endl;
                cin >> input;
                cout << "Enter Values as Space Separated." << endl;
                /*
                 * Taking Input as Space Separated Values
                 */
                int arr[input];
                for (int j = 0; j < input; ++j) cin >> arr[j];
                for (int j = 0; j < input; ++j) binaryHeap.push(arr[j]);
                cout << "All Values Added." << endl;
                break;
            }
            case 4:
                cout << "Size of Heap : " << binaryHeap.heap_size << endl;
                break;
            case 5:
                cout << "Height : " << binaryHeap.height() << endl;
                break;
            case 6:
                cout << "Total Capacity : " << binaryHeap.capacity << endl;
                break;
            case 7:
                binaryHeap.printHeap();
                break;
            case 8:
                system("cls");
                break;
            case 9: {
                cout << "Enter the Number of values you want to Add?" << endl;
                cin >> input;
                binaryHeap.heap_size += input;
                cout << "Enter Values as Space Separated." << endl;
                /*
                 * Taking Input as Space Separated Values
                 */
                for (int j = 0; j < input; ++j) cin >> binaryHeap.heapArray[j];
                binaryHeap.buildHeap(binaryHeap.heapArray, input);
                cout << "All Values Added." << endl;
                break;
            }
            default:
                cout << "Enter Proper Option number " << endl;
        }
    } while (option != 0);

    return 0;
} 
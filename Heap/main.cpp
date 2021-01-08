#include <iostream>

using namespace std;

void maxHeapify(int *array, int size, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && array[l] > array[largest])
        largest = l;
    if (r < size && array[r] > array[largest])
        largest = r;

    if (largest != i) {
        swap(array[i], array[largest]);
        maxHeapify(array, size, largest);
    }
}

void minHeapify(int *array, int size, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && array[l] < array[smallest])
        smallest = l;
    if (r < size && array[r] < array[smallest])
        smallest = r;

    if (smallest != i) {
        swap(array[i], array[smallest]);
        maxHeapify(array, size, smallest);
    }
}

void heapSort(int *array, int size) {
    int startIndex = (size / 2) - 1;

    for (int i = startIndex; i >= 0; --i) {
        maxHeapify(array, size, i);
    }

    for (int i = 0; i < size; ++i)
        cout << array[i] << " ";
    cout << endl;

    for (int i = size - 1; i >= 0; --i) {
        swap(array[0], array[i]);
        maxHeapify(array, i, 0);
    }
}

void printHeap(int arr[], int size) {
    cout << "Sorted Array : " << endl;

    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {10, 32, 50, 45, 21, 54, 321, 31, 34, 1, 24, 12, 987, 67};
    int size = sizeof arr / sizeof arr[0];

    heapSort(arr, size);
    printHeap(arr, size);
}

#include <iostream>

using namespace std;

void bubble_sort(int arr[], int length) {
    int temp;
    for (int i = 1; i <= length - 1; i++) {
        for (int j = 0; j <= length - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int length) {
    for (int i = 0; i < length; ++i) {
        int min = i;

        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        if (min != i) {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

void insertion_sort(int arr[], int length) {
    int j = 0;
    int key = 0;

    for (int i = 1; i < length; i++) {
        key = arr[i];
        j = i;

        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = key;

    }
}

void mergeArrays(int array[], int l, int mid, int r, int length) {
    int i = l;
    int j = mid + 1;
    int k = l;

    int temp[length];

    while (i <= mid && j <= r) {
        if (array[i] < array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    for (; i <= mid; i++)
        temp[k++] = array[i++];

    for (; j <= r; j++)
        temp[k++] = array[j++];

    for (int s = l; s <= r; s++)
        array[s] = temp[s];

}

void merge_sort(int arr[], int length, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        merge_sort(arr, length, l, mid);
        merge_sort(arr, length, mid + 1, r);
        mergeArrays(arr, l, mid, r, length);
    }
}

int Partition(int array[], int s, int e) {
    int pivot = array[e];
    int pIndex = s;

    for (int i = s; i < e; i++) {
        if (array[i] < pivot) {
            int temp = array[i];
            array[i] = array[pIndex];
            array[pIndex] = temp;
            pIndex++;
        }
    }
    int swap = array[e];
    array[e] = array[pIndex];
    array[pIndex] = swap;

    return pIndex;
}

void quick_sort(int arr[], int s, int e) {
    if (s < e) {
        int p = Partition(arr, s, e);
        quick_sort(arr, s, p - 1);
        quick_sort(arr, p + 1, e);
    }
}

void countSort(int array[], int size) {

    int output[size];
    int count[10];
    int max = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

int getMax(int arr[], int length) {
    int max = arr[0];
    for (int i = 0; i < length; ++i) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void sort(int arr[], int size, int div) {

    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++)
        count[(arr[i] / div) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / div) % 10] - 1] = arr[i];
        count[(arr[i] / div) % 10]--;
    }

    for (int i = 0; i < size; i++)
        arr[i] = output[i];

}

void radixSort(int arr[], int length) {
    int max = getMax(arr, length);
    for (int div = 1; max / div > 0; div *= 10) {
        sort(arr, length, div);
    }

}

void shellSort(int array[], int n) {
    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i += 1) {
            int temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
}

int main() {
    int A[] = {3, 212, 141, 512, 43, 26, 1247, 124, 9, 8, 739, 38, 023, 01, 3217, 5, 3};
    int length = sizeof(A) / sizeof(A[0]);

    cout << "Unsorted Array : " << endl;
    for (int i = 0; i < length; ++i) {
        cout << A[i] << " ";
    }

    bubble_sort(A, length);
    selection_sort(A, length);
    insertion_sort(A, length);
    merge_sort(A, length, 0, length - 1);
    quick_sort(A, 0, length - 1);
    countSort(A, length);
    radixSort(A, length);
    shellSort(A, length);

    cout << endl;

    cout << "Sorted Array : " << endl;
    for (int i = 0; i < length; ++i) {
        cout << A[i] << " ";
    }
}

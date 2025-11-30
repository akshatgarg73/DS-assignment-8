#include <iostream>
using namespace std;

void heapifyMax(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapifyMax(a, n, largest);
    }
}

void heapifyMin(int a[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] < a[smallest])
        smallest = left;
    if (right < n && a[right] < a[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;
        heapifyMin(a, n, smallest);
    }
}

void heapSortIncreasing(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMax(a, n, i);

    for (int i = n - 1; i >= 1; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapifyMax(a, i, 0);
    }
}

void heapSortDecreasing(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMin(a, n, i);

    for (int i = n - 1; i >= 1; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapifyMin(a, i, 0);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int n;
    int arr[100];

    cout << "Enter number of elements (max 100): ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int choice;
    cout << "1. Heap sort (increasing order)\n";
    cout << "2. Heap sort (decreasing order)\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
        heapSortIncreasing(arr, n);
    else if (choice == 2)
        heapSortDecreasing(arr, n);
    else {
        cout << "Wrong choice\n";
        return 0;
    }

    cout << "Sorted array:\n";
    printArray(arr, n);

    return 0;
}

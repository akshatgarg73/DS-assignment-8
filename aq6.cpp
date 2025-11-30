#include <iostream>
using namespace std;

int heap[100];
int heapSize = 0;

void swapPos(int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void heapifyUp(int child) {
    while (child > 0) {
        int parent = (child - 1) / 2;
        if (heap[parent] >= heap[child]) {
            break;
        }
        swapPos(parent, child);
        child = parent;
    }
}

void heapifyDown(int parent) {
    while (true) {
        int left = 2 * parent + 1;
        int right = 2 * parent + 2;
        int largest = parent;

        if (left < heapSize && heap[left] > heap[largest])
            largest = left;
        if (right < heapSize && heap[right] > heap[largest])
            largest = right;

        if (largest == parent)
            break;

        swapPos(parent, largest);
        parent = largest;
    }
}

void insert(int x) {
    if (heapSize >= 100) {
        cout << "Heap full!\n";
        return;
    }
    heap[heapSize] = x;
    heapSize++;
    heapifyUp(heapSize - 1);
    cout << x << " inserted\n";
}

int extractMax() {
    if (heapSize == 0) {
        cout << "Empty queue!\n";
        return -1;
    }
    int result = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    if (heapSize > 0)
        heapifyDown(0);
    return result;
}

void printHeap() {
    cout << "Heap: ";
    for (int i = 0; i < heapSize; i++)
        cout << heap[i] << " ";
    cout << endl;
}

int main() {
    int option, x;

    while (1) {
        cout << "\n1.Insert 2.Extract 3.Print 4.Exit\noption: ";
        cin >> option;

        if (option == 1) {
            cout << "Value: ";
            cin >> x;
            insert(x);
        } else if (option == 2) {
            x = extractMax();
            if (x != -1)
                cout << "Max: " << x << endl;
        } else if (option == 3) {
            printHeap();
        } else if (option == 4) {
            break;
        } else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}

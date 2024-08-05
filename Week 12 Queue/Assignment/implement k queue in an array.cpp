#include <iostream>
#include <queue>
using namespace std;

class KQueue {
public:
    int n, k, freeSpot;
    int* arr, * front, * rear, * next;

    KQueue(int _n, int _k) : n(_n), k(_k), freeSpot(0) {
        arr = new int[n];
        next = new int[n];
        rear = new int[k];
        front = new int[k];

        for (int i = 0; i < n; ++i)
            front[i] = rear[i] = -1;

        next[n - 1] = -1; // Corrected initialization
        for (int i = 0; i < n - 1; ++i) {
            next[i] = i + 1;
        }
    }

    bool push(int x, int qi) {
        // Overflow
        if (freeSpot == -1) {
            return false;
        }
        // Find first free index
        int index = freeSpot;

        // Update free spot
        freeSpot = next[index];

        // If first element in qi
        if (front[qi] == -1) {
            front[qi] = index;
        }
        else {
            // Link new element to that Q's rearest element
            next[rear[qi]] = index;
        }
        // Update next
        next[index] = -1;

        // Update rear
        rear[qi] = index;
        arr[index] = x;
        return true;
    }

    // Pop element with Queue
    int pop(int qi) {
        // Underflow
        if (front[qi] == -1) {
            return -1;
        }

        // Find index to pop
        int index = front[qi];

        // Front update
        front[qi] = next[index];

        // Update free spots
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
}; // Don't forget the semicolon

int main() {
    cout << "Hello world!" << endl;

    // Usage example
    KQueue kq(10, 3); // Create a KQueue with 10 elements and 3 queues
    kq.push(5, 0); // Push 5 to queue 0
    kq.push(10, 1); // Push 10 to queue 1
    cout << kq.pop(0) << endl; // Pop from queue 0

    return 0;
}

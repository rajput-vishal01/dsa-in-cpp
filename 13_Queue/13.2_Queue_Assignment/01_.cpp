#include <bits/stdc++.h>
using namespace std;

class NQueue {
    int *arr;      // main array to store data
    int *front;    // front index of each queue
    int *rear;     // rear index of each queue
    int *next;     // next free spot or next element in queue
    int n, size;   // n = number of queues, size = total size of array
    int freeSpot;  // beginning index of free list

public:
    // Constructor
    NQueue(int n, int size) {
        this->n = n;
        this->size = size;
        arr = new int[size];
        front = new int[n];
        rear = new int[n];
        next = new int[size];

        // initialize all queues as empty
        for (int i = 0; i < n; i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        // setup free spots (linked list of free indexes)
        for (int i = 0; i < size - 1; i++)
            next[i] = i + 1;
        next[size - 1] = -1;

        freeSpot = 0;
    }

    // Enqueue into queue number 'qn'
    bool enqueue(int data, int qn) {
        if (freeSpot == -1) {
            cout << "Queue Overflow\n";
            return false;
        }

        int index = freeSpot;        // take free spot
        freeSpot = next[index];      // update free list

        if (front[qn] == -1) {
            front[qn] = index;
        } else {
            next[rear[qn]] = index;  // link new element
        }

        next[index] = -1;   // no next element yet
        rear[qn] = index;   // update rear
        arr[index] = data;
        return true;
    }

    // Dequeue from queue number 'qn'
    int dequeue(int qn) {
        if (front[qn] == -1) {
            cout << "Queue Underflow\n";
            return -1;
        }

        int index = front[qn];
        front[qn] = next[index];  // move front ahead

        // free the index
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};

// Example usage
int main() {
    NQueue q(3, 10); // 3 queues, total array size 10

    q.enqueue(10, 0);
    q.enqueue(20, 0);
    q.enqueue(30, 1);
    q.enqueue(40, 2);

    cout << q.dequeue(0) << endl; // 10
    cout << q.dequeue(1) << endl; // 30
    cout << q.dequeue(2) << endl; // 40

    return 0;
}

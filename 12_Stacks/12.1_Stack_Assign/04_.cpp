// n stacks in a single array

#include <iostream>
using namespace std;

class NStack {
    int *arr;       // Main array to store actual elements
    int *top;       // Array to store index of top element of each stack
    int *next;      // Array to store next entry in all stacks and free list
    int n, size;    // n = number of stacks, size = total array size
    int freeSpot;   // Beginning index of free list

public:
    NStack(int nStacks, int arraySize) {
        n = nStacks;
        size = arraySize;
        arr = new int[size];
        top = new int[n];
        next = new int[size];

        // Initialize all stacks as empty
        for (int i = 0; i < n; i++) top[i] = -1;

        // Initialize free list
        for (int i = 0; i < size - 1; i++) next[i] = i + 1;
        next[size - 1] = -1;
        freeSpot = 0;
    }

    bool isFull() { return freeSpot == -1; }

    bool isEmpty(int stackNum) { return top[stackNum] == -1; }

    void push(int stackNum, int value) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        int i = freeSpot;          // Get first free index
        freeSpot = next[i];        // Update freeSpot to next free
        arr[i] = value;            // Store the value
        next[i] = top[stackNum];   // Link new element to previous top
        top[stackNum] = i;         // Update top for this stack
    }

    int pop(int stackNum) {
        if (isEmpty(stackNum)) {
            cout << "Stack Underflow\n";
            return -1;
        }
        int i = top[stackNum];     // Get top index of stack
        top[stackNum] = next[i];   // Update top to previous element
        next[i] = freeSpot;        // Add this index to free list
        freeSpot = i;
        return arr[i];
    }
};

// Example usage
int main() {
    int nStacks = 3, arraySize = 10;
    NStack stacks(nStacks, arraySize);

    stacks.push(0, 10);
    stacks.push(1, 20);
    stacks.push(2, 30);
    stacks.push(0, 40);

    cout << stacks.pop(0) << "\n"; // 40
    cout << stacks.pop(1) << "\n"; // 20
    cout << stacks.pop(2) << "\n"; // 30

    return 0;
}

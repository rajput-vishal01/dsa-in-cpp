#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // -------------------------------
    // Max Heap using STL priority_queue
    // -------------------------------
    // By default, priority_queue in C++ is implemented as a max heap.
    priority_queue<int> maxHeap;

    // -------------------------------
    // Min Heap using STL priority_queue
    // -------------------------------
    // To create a min heap, we use the 'greater' comparator.
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Example elements to insert into both heaps.
    int elements[] = {5, 1, 10, 3, 7};

    // Inserting elements into both heaps.
    for (int x : elements) {
        maxHeap.push(x);
        minHeap.push(x);
    }

    // -------------------------------
    // Operations on Max Heap
    // -------------------------------
    // Important Note: In a max heap, the largest element is always at the top.
    cout << "Max Heap top element: " << maxHeap.top() << endl; // Should print the maximum element (10)

    // Remove the top element.
    maxHeap.pop();
    cout << "Max Heap new top after pop: " << maxHeap.top() << endl; // Next largest element

    // -------------------------------
    // Operations on Min Heap
    // -------------------------------
    // Important Note: In a min heap, the smallest element is always at the top.
    cout << "Min Heap top element: " << minHeap.top() << endl; // Should print the minimum element (1)

    // Remove the top element.
    minHeap.pop();
    cout << "Min Heap new top after pop: " << minHeap.top() << endl; // Next smallest element

    // -------------------------------
    // Additional Heap Operations
    // -------------------------------
    // Check if heaps are empty.
    if (maxHeap.empty())
        cout << "Max Heap is empty." << endl;
    else
        cout << "Max Heap is not empty." << endl;

    if (minHeap.empty())
        cout << "Min Heap is empty." << endl;
    else
        cout << "Min Heap is not empty." << endl;

    // Display the current size of each heap.
    cout << "Current size of Max Heap: " << maxHeap.size() << endl;
    cout << "Current size of Min Heap: " << minHeap.size() << endl;

    return 0;
}

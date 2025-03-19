#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
Kth smallest element of array

Algorithms:
1. Sort the array and return the kth element.
   - Time Complexity: O(n log n)
2. Use a min heap of size n and pop k times.
   - Time Complexity: O(n + k log n), Space Complexity: O(n)
   - Not ideal when we want to optimize space.
3. Use a max heap of size k.
   - Build a max heap with the first k elements.
   - For each subsequent element, if it is smaller than the top (largest in the heap),
     push it into the heap and pop the top to maintain the heap size.
   - At the end, the heap contains the k smallest elements and the top is the kth smallest.
   - Time Complexity: O(n log k), Space Complexity: O(k)
*/

int kthSmallest(const vector<int>& arr, int k) {
    // Create a max heap using priority_queue (by default, it is a max heap)
    priority_queue<int> maxHeap;

    // Traverse the array
    for (int num : arr) {
        // Push the current element into the heap
        maxHeap.push(num);

        // If the heap size exceeds k, remove the largest element
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    // The top of the max heap is the kth smallest element
    return maxHeap.top();
}

int main() {
    vector<int> arr = {7, 1, 4, 3, 20, 15};
    int k = 3; // For example, to find the 3rd smallest element

    int result = kthSmallest(arr, k);
    cout << "The " << k << "rd smallest element is " << result << endl;
    
    return 0;
}
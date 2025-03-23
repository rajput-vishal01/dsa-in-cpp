/*
Hash Map:

A data structure where data is stored as key-value pairs.

Types of maps:
1. Ordered Map --> O(log n)
   - Traversing prints keys in sorted order.
   - Typically implemented using a balanced Binary Search Tree (BST).

2. Unordered Map --> O(1)
   - Traversing prints keys in unsorted order.
   - Implemented using arrays (also known as bucket arrays).
   - Similar to arrays where data is stored at specific indices, unordered maps use hash functions
     to map keys (e.g., string keys) to indices and pair them with their corresponding values.

Hash Function:
A hash function converts a key into an integer (hash code) and then uses a compression function
to transform this integer into a valid index for storage in a hash table.
- Hash Code:
  - Generates a numeric representation of the key (for example, by processing individual characters in a string).
  - Aims to distribute keys uniformly across the hash table to minimize collisions.
- Compression Function:
  - Reduces the hash code to an index within the bounds of the array (often using the modulo operator).
  - Ensures the computed index is a valid position in the underlying bucket array.

Collision Handling:
When two keys hash to the same index, a collision occurs. There are two main strategies to handle collisions:
1. Open Hashing (Separate Chaining):
   - Each bucket in the hash table holds a collection (usually a linked list) of all elements that hash to the same index.
   - This method allows multiple elements to coexist at the same index.
   - It is simple to implement and performs well if the hash function distributes keys evenly.
2. Closed Addressing (Open Addressing):
   - All elements are stored directly in the hash table.
   - When a collision occurs, the algorithm searches for the next available slot using probing techniques:
     - Linear Probing: Sequentially checks the next slot.
     - Quadratic Probing: Uses a quadratic function to calculate the interval between slots.
     - Double Hashing: Uses a second hash function to determine the probing step.
   - This method avoids the extra memory overhead of storing additional data structures at each index.

Load Factor:
- The size of the bucket array directly affects collision frequency: larger bucket arrays reduce collisions, while smaller arrays increase collision chances.
- Load Factor Formula: Load Factor = (Number of elements) / (Size of bucket array)
- A load factor less than 0.7 is generally considered good, indicating that the hash function is performing efficiently with fewer collisions.
*/



#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    // ---------------- Ordered Map Operations ----------------
    map<int, string> orderedMap;
    
    // Insertion:
    orderedMap[3] = "Three";
    orderedMap[1] = "One";
    orderedMap[2] = "Two";
    
    cout << "Ordered Map (Sorted Order):" << endl;
    for (const auto &pair : orderedMap) {
        cout << pair.first << " : " << pair.second << endl;
    }
    
    // Searching for a key
    if (orderedMap.find(3) != orderedMap.end()) {
        cout << "\nKey 3 found with value: " << orderedMap[3] << endl;
    } else {
        cout << "\nKey 3 not found." << endl;
    }
    
    // Deletion:
    orderedMap.erase(2);
    cout << "\nOrdered Map after deleting key 2:" << endl;
    for (const auto &pair : orderedMap) {
        cout << pair.first << " : " << pair.second << endl;
    }
    
    // ---------------- Unordered Map Operations ----------------
    unordered_map<int, string> unorderedMap;
    
    // Insertion:
    unorderedMap[3] = "Three";
    unorderedMap[1] = "One";
    unorderedMap[2] = "Two";
    
    cout << "\nUnordered Map (Unsorted Order):" << endl;
    // Traversing 
    for (const auto &pair : unorderedMap) {
        cout << pair.first << " : " << pair.second << endl;
    }
    
    // Searching for a key
    if (unorderedMap.find(2) != unorderedMap.end()) {
        cout << "\nKey 2 found with value: " << unorderedMap[2] << endl;
    } else {
        cout << "\nKey 2 not found." << endl;
    }
    
    // Deletion:
    unorderedMap.erase(1);
    cout << "\nUnordered Map after deleting key 1:" << endl;
    for (const auto &pair : unorderedMap) {
        cout << pair.first << " : " << pair.second << endl;
    }
    
    return 0;
}

/*

---SOLVED USING CHATGPT --- 

Book allocation problem : GFG 0937

You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. 
You also have an integer k representing the number of students. 
The task is to allocate books to each student such that:
Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
[12] and [34, 67, 90] Maximum Pages = 191
[12, 34] and [67, 90] Maximum Pages = 157
[12, 34, 67] and [90] Maximum Pages = 113.
Therefore, the minimum of these cases is 113, which is selected as the output.

Constraints:
1 <=  arr.size() <= 106
1 <= arr[i] <= 103
1 <= k <= 103

 Approach:
    We solve the problem using **Binary Search** combined with a **Greedy Approach**.
    
    - The **lower bound** for the binary search is the maximum number of pages in a single book (because no student can receive fewer pages than the largest book).
    - The **upper bound** is the total sum of all book pages (as a worst-case scenario where all books are assigned to a single student).
    
    The idea is to use binary search to find the smallest maximum page count that can be assigned to any student while still ensuring that the allocation can be done with no more than 'k' students.
    
    **Binary Search Steps**:
    - Start with the range [max(arr), sum(arr)].
    - For each mid-value between low and high, check if it's possible to allocate books such that no student gets more than 'mid' pages.
    - If it is possible, try to reduce the number of pages (by moving the upper bound).
    - If it's not possible, increase the number of pages (by adjusting the lower bound).
    
    This will find the minimum value of the maximum pages that a student will get.
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Function to check if it's possible to allocate books such that no student gets more than 'maxPages' pages
bool isValidAllocation(const vector<int>& arr, int k, int maxPages) {
    int studentCount = 1;  // Start with the first student
    int currentPages = 0;  // Track the pages assigned to the current student

    for (int i = 0; i < arr.size(); i++) {
        // If adding the current book exceeds the max pages, allocate it to the next student
        if (currentPages + arr[i] > maxPages) {
            studentCount++;  // Increment student count
            currentPages = arr[i];  // Start the next student with the current book
            if (studentCount > k) return false;  // If we have more than 'k' students, return false
        } else {
            currentPages += arr[i];  // Allocate current book to the current student
        }
    }
    return true;
}


int findMinimumPages(const vector<int>& arr, int k) {
    int low = *max_element(arr.begin(), arr.end());  // Maximum single book pages
    int high = accumulate(arr.begin(), arr.end(), 0);  // Total sum of all pages
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Middle point

        // Check if it's possible to allocate books with 'mid' as the maximum pages
        if (isValidAllocation(arr, k, mid)) {
            result = mid;  // If valid, update result
            high = mid - 1;  // Try to minimize the maximum pages by searching lower half
        } else {
            low = mid + 1;  // If invalid, increase the minimum possible pages
        }
    }
    return result;  // Return the minimized maximum pages
}

int main() {
    vector<int> arr = {12, 34, 67, 90};  // Array of book pages
    int k = 2;  // Number of students

    int result = findMinimumPages(arr, k);
    cout << "Minimum pages allocated: " << result << endl;  // Expected output: 113
    return 0;
}

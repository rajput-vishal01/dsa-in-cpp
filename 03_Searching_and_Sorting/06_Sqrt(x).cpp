// Leetcode problem :- 69.🫥🙃  Sqrt(x)

/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 
Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
*/

/*
class Solution {
public:
    int mySqrt(int x) {
       
        int s = 0;
        int e = x;
        int ans = -1; 

        while (s <= e) {
            // Calculate the middle of the search space to avoid overflow
            long long int mid = s + (e - s) / 2;
            
            // Compute the square of the mid value
            long long int product = mid * mid;

            // Check if mid is the exact square root of x
            if (product == x) {
                return mid;
            }

            // If the square is less than x, store mid as a potential answer
            // and search in the right half of the search space
            if (product < x) {
                ans = mid;
                s = mid + 1;
            } else {
                // If the square is greater than x, search in the left half
                e = mid - 1;
            }
        }

        // Return the floor value of the square root if an exact match is not found
        return ans;
    }
};
*/
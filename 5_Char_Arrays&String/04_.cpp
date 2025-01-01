/*
--LEETCODE PROBLEM--

1910. Remove All Occurrences of a Substring

Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.

Example 1:

Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".

class Solution {
public:
    string removeOccurrences(string full, string pattern) {
        

        //jab tak full string k andar pattern string 
        //milti rahegi, tab tak loop chalao
        
        while(full.find(pattern) != string::npos) {
            //full string me se erase karo
            //erase function k 2 argument hai
            //first arguement me, pattern ka starting index dena hai
            // full.find(pattern), hume starting index of pattern inside
            //full string provide krra hau
            //2nd argument, usme specify krna hai, k kitne character
            //remove karna chahte ho, starting index se
            full.erase(full.find(pattern), pattern.length());
        }
        return full;

    }
};

*/
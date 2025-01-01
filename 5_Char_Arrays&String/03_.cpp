/*
--LEETCODE PROBLEM--
1047. Remove All Adjacent Duplicates In String

You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
We repeatedly make duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

class Solution {
public:
    string removeDuplicates(string s) {
        //intialise ans string as empty string
        string ans = "";        
        int n = s.length();

        for(int i=0; i<n; i++) {
            char currCharacter = s[i];
            if(ans.empty() || currCharacter != ans.back()) {
                //if ans is empty, seedha push karo
                ans.push_back(currCharacter);
            }//rightmost character of ans = ans.back()
            else if(currCharacter == ans.back()) {
                ans.pop_back();
            }
        }
        return ans;
    }
};

*/
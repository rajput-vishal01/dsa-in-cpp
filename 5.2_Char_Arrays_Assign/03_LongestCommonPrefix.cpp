//Leetcode problem 14. Longest Common Prefix


/*
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) { // Check for empty input
            return "";
        }
        
        string ans = "";
        int i = 0;
        
        while (true) {
            char curr_char = 0; // Initialize current character
            
            for (int j = 0; j < strs.size(); j++) { 
                if (i >= strs[j].size()) { // Out of bounds for any string
                    curr_char = 0;
                    break;
                }
                
                if (curr_char == 0) { // First character at position i
                    curr_char = strs[j][i];
                } else if (strs[j][i] != curr_char) { // Mismatch found
                    curr_char = 0;
                    break;
                }
            }
            
            if (curr_char == 0) { // No more common characters
                break;
            }
            
            ans.push_back(curr_char); 
            i++; 
        }
        
        return ans;
    }
};

*/
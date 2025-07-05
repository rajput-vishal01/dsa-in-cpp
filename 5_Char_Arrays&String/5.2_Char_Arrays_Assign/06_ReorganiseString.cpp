//Leetcode Problem :  767. Reorganize String

//m1: priority queue (but abhi aata ni vo)

/*m2:
count hash
try to place most occurrencant eleme in one go
 --if not possible return not possible
place other characters with one gap
*/

/*

class Solution {
public:
    string reorganizeString(string s) {
        int hash[26] = {0}; // Frequency count for each character
        int n = s.size();

        // Count the frequency of each character
        for (char ch : s) {
            hash[ch - 'a']++;
        }

        // Find the character with the maximum frequency
        int maxFreq = 0, maxChar = 0;
        for (int i = 0; i < 26; i++) {
            if (hash[i] > maxFreq) {
                maxFreq = hash[i];
                maxChar = i;
            }
        }

        // If the maximum frequency is more than (n + 1) / 2, it's not possible
        if (maxFreq > (n + 1) / 2) {
            return "";
        }

        // Create a result string
        string result(n, ' ');

        // Place the most frequent character first
        int index = 0;
        while (hash[maxChar] > 0) {
            result[index] = 'a' + maxChar;
            index += 2; // Alternate indices
            hash[maxChar]--;
        }

        // Place the remaining characters
        for (int i = 0; i < 26; i++) {
            while (hash[i] > 0) {
                if (index >= n) { // Switch to odd indices
                    index = 1;
                }
                result[index] = 'a' + i;
                index += 2;
                hash[i]--;
            }
        }

        return result;
    }
};


*/
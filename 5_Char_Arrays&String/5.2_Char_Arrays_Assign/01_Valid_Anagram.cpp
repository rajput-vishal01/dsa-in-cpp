// Leetcode Problem : 242. Valid Anagram


// m1(bruteForce):sort both the words and if s==t (it is a anagram)

/*
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        return s==t;
    }
};*/

//  T.C =O( n log n + m log m)



//m2:count the occurrences/freq of each word for both and then for s increment the frequency
// and for t decrement the frequency.if the frequency table has all the values 0 means that
//its a anagram
/*
 To create a freq. table for Strings.
 Take a 256 size of array(as ASCII range is also that)-initialize everything with 0
 And if elem found in the string increment that index with +1.
 
*/


/*
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) { // Check if lengths are different
            return false;
        }

        int freqTable[256] = {0}; // Assume ASCII characters only
        
        // Increment counts for `s` and decrement counts for `t`
        for (int i = 0; i < s.size(); i++) {
            freqTable[s[i]]++;
            freqTable[t[i]]--;
        }
        
        // Check if any count is non-zero
        for (int i = 0; i < 256; i++) {
            if (freqTable[i] != 0) {
                return false;
            }
        }
        
        return true; // Strings are anagrams
    }
};

*/
// LP :205. Isomorphic Strings

/*

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash[256] = {0}; // Mapping of each char of "s" to "t"
        bool istCharsMapped[256] = {0}; // Tracks if a char in "t" is already mapped

        for (int i = 0; i < s.size(); i++) {
            if (hash[s[i]] == 0 && !istCharsMapped[t[i]]) {
                // Map the character from s to t
                hash[s[i]] = t[i];
                istCharsMapped[t[i]] = true;
            } else if (hash[s[i]] != t[i]) {
                // If already mapped, check if the mapping is consistent
                return false;
            }
        }

        return true; // If all mappings are consistent
    }
};


*/
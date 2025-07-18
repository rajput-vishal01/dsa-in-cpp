// Leetcode :1209. Remove All Adjacent Duplicates in String II

class Solution {
public:
    bool checkIsEqual(string &s,int k,int i){
        if (i+k>s.size()) return false; 

        for (int j=i;j<i+k-1;j++) {
           if (s[j]!=s[j+1]) {
           return false;
        }
    }
        return true;
    }
    string removeDuplicates(string s, int k) {
        int i=0;
        while(i<s.size()){
             if(checkIsEqual(s,k,i)) {
                s.erase(i,k);
                i = max(0,i-k+1);  // Go back to check for new duplicates
            } else {
                i++; 
            }
        }
        return s;
    }
    
};
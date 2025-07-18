//Leetcode 28. Find the Index of the First Occurrence in a String
//my soln:
class Solution {
public:
    int strStr(string haystack, string needle) {
     int i=0;
     int j=needle.length();
    
     // Edge case: empty needle
     if (needle.empty()) return 0;
        
     // Edge case: needle longer than haystack
     if (needle.length() > haystack.length()) return -1;

     for (int i=0;i<=haystack.length()-needle.length();i++) {
            if (haystack.substr(i,needle.length())==needle) {
                return i;
            }
        }
     return -1;
    }
};

//class soln:
class Solution {
public:
    int strStr(string haystack, string needle) {
    int n=haystack.size();
    int m=needle.size();

    for(int i=0;i<n-m;i++){
        for(int j=0;j<m;j++){
            if(needle[j]!=haystack[i+j]){
                break;
            }
            if(j==m-1){
                return i;
            }
        }
    }
    return -1;
    }
};
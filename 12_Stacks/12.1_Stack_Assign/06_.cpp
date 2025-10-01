// leetcode 1003 : check-if-word-is-valid-after-substitutions

// Recursion
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()){
            return true;
        }

        int toFind= s.find("abc");
        if(toFind != string::npos){
            string left = s.substr(0,toFind);
            string right = s.substr(toFind+3,s.size());
            return isValid(left+right);
        }

        return false;
        
    }
};

//Stack 
class Solution {
public:
    bool isValid(string s) {
     if(s[0] != 'a') return false;

     stack<char>st;

     for(char ch:s){
        if(ch=='a'){
            // ch is a
            st.push(ch);
        }else if(ch=='b'){
            // ch is b
            if(!st.empty() && st.top()=='a'){
                st.push(ch);
            }else{
                return false;
            }
        }else{
            // ch is c
            if(!st.empty() && st.top()=='b'){
                st.pop();
                st.pop();
            }else{
                return false;
            }

        }
     }
        return(st.empty());

    }
};
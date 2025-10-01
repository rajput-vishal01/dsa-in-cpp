// leetcode 921 : minimum-add-to-make-parentheses-valid

class Solution {
public:
    int minAddToMakeValid(string s) {
      // why use stack??
        int open=0, close=0;

        for(char ch:s){
            if(ch=='('){
                open++;
            }else{
                if(open>0){
                    open--;
                }else{
                    close++;
                }
            }
        }

        return open+close;
    }
};





//with stack: 
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;

        for(char ch:s){
            if(ch=='('){
                st.push(ch);
            }else{
                if(!st.empty() && st.top()=='('){
                    st.pop(); // valid pair
                }else{
                    st.push(ch); // unmatched ')'
                }
            }
        }

        return st.size(); // all unmatched need to be fixed
    }
};

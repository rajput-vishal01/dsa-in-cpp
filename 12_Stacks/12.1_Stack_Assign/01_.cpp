// GFG : Count the Reversals


class Solution {
  public:
    int countMinReversals(string s) {
        stack<char>st;
        
        if(s.size() %2 != 0) return -1;//odd can not be balanced
        
        // remove valid pairs
        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && st.top() == '{' && s[i] == '}') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        
        int count=0;
        while(!st.empty()){
            char first = st.top();
            st.pop();
            
            char second = st.top();
            st.pop();
            
            // if(first == '}' && second =='}') count++;
            // if(first == '}' && second =='{') count++;
            // if(first == '}' && second =='{') count=count+2;
 
            
            if(first==second){
                count+=1;
            }else{
                count+=2;
            }
            
        }
        
        return count;
        
    }
};
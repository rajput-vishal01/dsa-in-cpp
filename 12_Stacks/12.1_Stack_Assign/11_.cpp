//leetcode 402: Remove K Digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        stack<char>st;

        for(auto digit:num){
            while(k > 0 && !st.empty() && st.top() > digit){
                st.pop();
                k--;
            }
            st.push(digit);
        }

        // remove remaining k digits if any
        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }

        // build answer from stack
        while(!st.empty()){
            char s = st.top(); 
            st.pop();
            ans.push_back(s);
        }

        reverse(ans.begin(), ans.end());

        // remove leading zeros
        int idx = 0;
        while(idx < ans.size() && ans[idx] == '0'){
            idx++;
        }
        ans = ans.substr(idx);

        if(ans.empty()) return "0";
        return ans;
    }
};

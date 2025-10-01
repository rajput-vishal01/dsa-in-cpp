// leetcode 739 : Daily Temperatures
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans(temperatures.size(),0);
        stack<int>st;

        st.push(0); // push index of first element

       for(int i=1;i<temperatures.size();i++){
        while(!st.empty() && temperatures[i] > temperatures[st.top()]){
            int idx=st.top();
            st.pop();
            ans[idx]=i-idx;
        }
        st.push(i);
       }
       return ans;
    }
};

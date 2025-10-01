// Leetcode 1019 : Next Greater Node In Linked List

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ll;
        
        while(head){
            ll.push_back(head->val);
            head=head->next;
        }

        stack<int>st;
        vector<int>ans(ll.size(),0);

        for(int i=0;i<ll.size();i++){
                  while(!st.empty() && ll[i]>ll[st.top()]) {
                    //save the value in ans;
                    ans[st.top()]=ll[i];
                    st.pop();
                }
                st.push(i);
        }
        return ans;
    }
};
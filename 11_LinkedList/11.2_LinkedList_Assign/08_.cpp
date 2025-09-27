//Leetcode 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans ={-1,-1};
        //As atleast 3 nodes are required to get critical points
        ListNode* prev = head;
        if(!prev) return ans;
        ListNode* curr = head->next;
        if(!curr) return ans;
        ListNode* next = head->next->next;
        if(!next) return ans;

        int firstCP=-1;
        int lastCP=-1;
        int minDist=INT_MAX;
        int i=1;

        while(next){
            bool isCP = ((curr->val > prev->val && curr->val > next->val)||(curr->val < prev->val && curr->val < next->val)) ? true : false;

            if(isCP && firstCP ==-1){
                firstCP=i;
                lastCP=i;
            }else if(isCP){
                minDist=min(minDist,i-lastCP);
                lastCP=i;
            }
            ++i;
            prev=prev->next;
            curr=curr->next;
            next=next->next;
        }

        if(lastCP==firstCP){
            //only one cp exists
            return ans;
        }else{
            ans[0]=minDist;
            ans[1]=lastCP-firstCP;
        }

        return ans;
    }
};
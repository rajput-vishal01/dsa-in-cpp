// Leetcode 148. Sort List


class Solution {
public:
    ListNode* findmid(ListNode* head){
       ListNode* slow=head;
       ListNode* fast=head->next;

       while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
       }
       return slow;
    }
     ListNode* merge(ListNode*  left, ListNode* right) {
        
        if(left == NULL) return right;
        if(right== NULL) return left;

        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans;

        while(left && right){
            if(left->val<=right->val){
            mptr->next=left;
            mptr=left;
            left=left->next;
        }else{
            mptr->next=right;
            mptr=right;
            right=right->next;
        }
        }
        if(left){
            mptr->next=left;
         
        }
          if(right){
            mptr->next=right;
        }
        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==0 || head->next == 0) return head;

        //Break LL into two halves
        ListNode* mid = findmid(head);

        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=0;

        //sort RE
        left = sortList(left);
        right = sortList(right);

        //merge Both
        ListNode* mergedLL = merge(left,right);
        return mergedLL;
    }
};
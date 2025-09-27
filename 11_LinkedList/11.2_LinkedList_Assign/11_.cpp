// Leetcode 2816. Double a Number Represented as a Linked List

class Solution {
public:

    void solve(ListNode* head,int &carry){
        if(!head) return;
        solve(head->next,carry);

        //reached the end;
        //1 case solve::
        int prod = head->val * 2 + carry;
        head->val=prod%10;
        carry=prod/10;
    }
 
    ListNode* doubleIt(ListNode* head) {
        int carry=0;
        solve(head,carry);

        if(carry){
            //insert at head with carry value;
            ListNode* carryNode = new ListNode(carry);
            carryNode->next=head;
            head=carryNode;
        }

        return head;
        
    }
};
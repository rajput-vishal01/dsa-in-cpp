/*
LeetCode 83 Remove Duplicates from Sorted List

*/


/*

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        // 1case -> LL is empty
        if(head == NULL) {
            return head;
        }
        //2 case -> LL -> single node 
        if(head -> next == NULL) {
            return head;
        }
        //3 case >1 node 
        // atleast 2 node toh pkka hogi 
        ListNode* prev = head;
        ListNode* temp = head->next;

        while(temp != NULL) {
            
            //duplicate check karo 
            if(temp->val == prev->val) {
                //duplicate found
                prev->next = temp->next;
                temp->next = NULL;
                delete temp;
            }
            else {
                //duplicate not found
                prev = prev->next;
                temp = temp->next;
            }
            //temp ko set kardo
            temp = prev->next;
        } 
        return head;
    }
};

*/
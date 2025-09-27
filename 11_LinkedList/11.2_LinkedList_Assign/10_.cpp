// Leetcode 328. Odd Even Linked List 

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || head->next == 0) return head;
        ListNode* oddptr= head;
        ListNode* evenptr=head->next;
        ListNode* evenHead=evenptr;

        while(evenptr && evenptr->next){
            oddptr->next=evenptr->next;
            evenptr->next=evenptr->next->next;

            oddptr=oddptr->next;
            evenptr=evenptr->next;
        }

        //two independent listnodes are prepared with odd and even values
        //Link : oddVals->evenVals
        oddptr->next=evenHead;
        return head;

        
    }
};
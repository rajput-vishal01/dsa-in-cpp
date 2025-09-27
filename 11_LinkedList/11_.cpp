// 25. Reverse Nodes in k-Group

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* &head){
        ListNode* temp=head;
        int length=0;

        while(temp!=NULL){
            length++;
            temp=temp->next;
        }

        return length;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head==NULL || head->next==NULL){
            return head;
        }

        int len=getLength(head);
        if(len<k){
            // reverse krne ki koi load ni hai
            return head;
        }

        //reverse single group
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward=NULL;
        
        int pos=0;
        while(pos<k){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            pos++;
        }

        // recursion for next groups
        if(curr!=NULL){
            ListNode* recurrHead = reverseKGroup(curr, k);
            head->next=recurrHead;
        }

        return prev;
    }
};

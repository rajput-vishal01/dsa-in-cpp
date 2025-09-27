// Leetcode 61. Rotate List

class Solution {
public:
    int getLength(ListNode* head){
        int len=0;
        while(head){
            ++len;head=head->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return 0;

        int length=getLength(head);
        // Calculate actual rotations needed (handle cases where k > length)
        int actualRotate = k % length;

        if(actualRotate==0) return head;
        // Find position of the new last node (0-indexed)
        // For right rotation by k, new last node is at position (length - k - 1)
        int newLastNodePos = length-actualRotate-1;
        ListNode* newLastNode = head;

        for(int i=0;i<newLastNodePos;i++){
            newLastNode=newLastNode->next;
        }

        ListNode* newHead= newLastNode->next;
        newLastNode->next=0;

        ListNode *it = newHead;
        while(it->next){
            it=it->next;
        }

        it->next=head;
        return newHead;
    }
};
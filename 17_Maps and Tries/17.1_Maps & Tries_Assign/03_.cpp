// Leetcode 160 : Intersection of Two Linked Lists


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while(a && b){
            if(a == b) return a;

            // else move
            a = a->next;
            b = b->next;
        }

        // if no intersection and both ended
        if(!a && !b) return NULL;

        // find lengths
        int lenA = 0, lenB = 0;
        a = headA;
        b = headB;

        while(a){
            lenA++;
            a = a->next;
        }
        while(b){
            lenB++;
            b = b->next;
        }

        // move longer list ahead
        a = headA;
        b = headB;

        if(lenA > lenB){
            int diff = lenA - lenB;
            while(diff--) a = a->next;
        }else{
            int diff = lenB - lenA;
            while(diff--) b = b->next;
        }

        // move both together until intersection
        while(a != b){
            a = a->next;
            b = b->next;
        }

        return a;
    }
};

/*
V.V.V.V.V.V important question

Leetcode 141
Check Cycle in LL

Approch 1: using hashset mark visted and unvisted .T.C -> O(n)
*/

/*

class Solution {
public:
    bool hasCycle(ListNode *head) {

        unordered_map<ListNode* ,bool> m;
        ListNode* temp = head;

        while(temp != NULL){
            if(m[temp]==true){
                return true;

            }else{
                m[temp]= true;
            }
            temp = temp->next;
        
            
        }
        return false;
    }
};
*/

/*
Approch 2: using fast and slow pointer .T.C -> O(n)
*/

/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {    
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) { // If slow and fast meet, a cycle exists
                return true;
            }
        }
        return false; // If fast reaches NULL, no cycle exists
    }
};


*/
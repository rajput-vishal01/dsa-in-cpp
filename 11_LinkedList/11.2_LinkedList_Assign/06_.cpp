// Leetcode 138. Copy List with Random Pointer



class Solution {
public:
    
    Node* helper(Node* head, unordered_map<Node*,Node*>&mp){
        if(head==0) return 0;

        Node* newHead = new Node(head->val);
        mp[head]=newHead;
        //created normal single linkedlist with next pointer
        newHead->next = helper(head->next,mp);
        //getting random pointers if exisits adding pointers
        if(head->random){
           newHead->random=mp[head->random];

        }

        return newHead;
    }

    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp; //old node -->new node
        return helper(head,mp);
    }
};
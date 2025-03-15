/*
Leetcode :: 109
*/

class Solution {
public:
    int getLength(ListNode*& head) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL) {
            cnt++;
            temp = temp ->next;
        }
        return cnt;
    }
    TreeNode* solve(ListNode*& head, int n) {
        if(head == NULL || n <= 0) {
           return NULL; 
        }
        //LNR
        //L
        TreeNode* leftSubTree = solve(head, n/2);
        //N
        //ab head mid node pr khada hoga
        TreeNode* root = new TreeNode(head->val);
        root->left = leftSubTree;
        //ab head mid pr khada tha, usko aage bhejo 
        head = head -> next;
        //ab head right part of LL k start node pr khada hoga 
        TreeNode* rightSubtree = solve(head, n-n/2-1);
        root->right  = rightSubtree;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int n = getLength(head);
        TreeNode* root = solve(head, n);
        return root;
    }
};
// leetcode 103 : Binary Tree Zigzag Level Order Traversal
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        bool flag = true;
        queue<TreeNode*> q;
        q.push(root);      

        while(!q.empty()){
            int newSize = q.size();
            vector<int> oneLevelTraversal(newSize);
            
            for(int i = 0; i < newSize; i++){
                TreeNode* front = q.front(); 
                q.pop();

                int index = flag ? i : newSize - i - 1;

                oneLevelTraversal[index] = front->val;

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }

            flag = !flag; // toggle the flag
            ans.push_back(oneLevelTraversal);
        }

        return ans;
    }
};

//Leetcode 94: Inorder Traversal

//Morris Traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr){
            // left node is NULL, then, visit it and go right;
            if(curr->left == nullptr){
                ans.push_back(curr->val);
                curr = curr->right;
            }

            // left node is NOT NULL
            else{
                // find inorder predecessor
                TreeNode* pred = curr->left;
                while(pred->right!= curr && pred->right){
                    pred = pred->right;
                }

                //if  pred right node is NULL, then, go left after establishing link from pred to curr;
                if( pred->right == nullptr){
                    pred->right = curr;
                    curr = curr->left;
                }
                else{
                    // left is already visited, Go right after visiting curr node, while removing link
                    pred->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};

//Normal

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        // LNR
        vector<int>left = inorderTraversal(root->left);
        ans.insert(ans.end(), left.begin(), left.end());

        ans.push_back(root->val);

        vector<int>right = inorderTraversal(root->right);
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }
};

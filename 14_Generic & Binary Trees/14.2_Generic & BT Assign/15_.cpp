//leetcode 652 : Find Duplicate Subtrees

class Solution {
public:
    unordered_map<string, int> mp;  // store serialized subtree frequency
    vector<TreeNode*> res;
    
    string serialize(TreeNode* root) {
        if (!root) return "#";  // null marker
        
        // serialize current subtree
        string s = to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
        
        // count occurrences
        if (++mp[s] == 2)  // add to result only once
            res.push_back(root);
        
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return res;
    }
};

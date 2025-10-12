//GFG : left-view-of-binary-tree

class Solution {
  public:
    void solve(Node* root,int level,vector<int>&ans){
        if(root==NULL) return;
        
        if(level == ans.size()){
            ans.push_back(root->data);
        }
        solve(root->left,level+1,ans);
        solve(root->right,level+1,ans);
    }
    
    vector<int> leftView(Node *root) {
        vector<int>ans;
        solve(root,0,ans);
        return ans;
    }
};

//GFG : right-view-of-binary-tree

class Solution {
  public:
     void solve(Node* root,int level,vector<int>&ans){
        if(root==NULL) return;
        
        if(level == ans.size()){
            ans.push_back(root->data);
        }
        solve(root->right,level+1,ans); //just moved above
        solve(root->left,level+1,ans);
    }
    
    vector<int> rightView(Node *root) {
        vector<int>ans;
        solve(root,0,ans);
        return ans;
        
    }
};


//Leetcode 119 : binary-tree-right-side-view

class Solution {
public:
    void solve(TreeNode* root,int level,vector<int>&ans){
        if(root==NULL) return;
        
        if(level == ans.size()){
            ans.push_back(root->val);
        }
        solve(root->right,level+1,ans);
        solve(root->left,level+1,ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        solve(root,0,ans);
        return ans;
    }
};
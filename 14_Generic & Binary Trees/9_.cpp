// GFG : boundary-traversal-of-binary-tree

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  void leftboundaryTraversal(Node *root,vector<int>&ans) {
        if(root ==NULL){
            return;
        }
        
        if(root->left==NULL && root->right == NULL){
            return;
        }
        
        ans.push_back(root->data);
        
        if(root->left!=NULL) leftboundaryTraversal(root->left,ans);
        else  leftboundaryTraversal(root->right,ans);
        
    }
    void leafboundaryTraversal(Node *root,vector<int>&ans) {
         if(root ==NULL){
            return;
        }
        
        if(root->left==NULL && root->right == NULL){
            ans.push_back(root->data);
        }
        
        leafboundaryTraversal(root->left,ans);
        leafboundaryTraversal(root->right,ans);
        
    }
    void rightboundaryTraversal(Node *root,vector<int>&ans) {
        if(root ==NULL){
            return;
        }
        
        if(root->left==NULL && root->right == NULL){
            return;
        }
        
        if(root->right!=NULL) rightboundaryTraversal(root->right,ans);
        else  rightboundaryTraversal(root->left,ans);
        
        //else ans is needed in reverse order
        ans.push_back(root->data);
        
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int>ans;
        
        if(root==NULL) return ans;
        // A->root node
        ans.push_back(root->data);
        // B->left subtree->left boundry
        leftboundaryTraversal(root->left,ans);
        // C->left subtree->leaf boundry
        leafboundaryTraversal(root->left,ans);
        // D->right subtree->leaf boundry
        leafboundaryTraversal(root->right,ans);
        // E-?right subtree->right boundry
        rightboundaryTraversal(root->right,ans);
        
        
        return ans;
        
    }
};
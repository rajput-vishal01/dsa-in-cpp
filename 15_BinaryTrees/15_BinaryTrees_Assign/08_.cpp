// GFG : Flatten BST to sorted list

/*
1.store the tree in vector and recreate the tree
2.Convert the BST to a sorted linked list by performing an in-order traversal and linking nodes using their right pointers.

*/

class Solution {
  public:
    void inOrderTraversal(Node *root, Node* &prev){
        if(root==NULL) return;
        
        //LNR
        inOrderTraversal(root->left,prev);
        //processing
        prev->left=0;
        prev->right=root;
        prev=root;
        
        inOrderTraversal(root->right,prev);
        
    }
    Node *flattenBST(Node *root) {
        Node* temp = new Node(-1);
        Node* prev =temp;
        
        inOrderTraversal(root,prev);
        
        prev->left=prev->right=NULL;
        return temp->right;
        
    }
};
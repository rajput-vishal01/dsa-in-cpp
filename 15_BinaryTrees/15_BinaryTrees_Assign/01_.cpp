// Work.tech 
// Inorder Predecessor of Node in BST
/*
Methods:
1.store traversal in vector and return the target using either linear search or binary search
2.traverse using inorder and maximise the value to the minimum of target using BST property
*/

Node* findPredecessor(Node* root, Node* p) {
    Node* pred = nullptr;
    Node* curr = root;  

    while(curr){
        if(curr->data < p->data){
            pred = curr;
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    return pred;
}

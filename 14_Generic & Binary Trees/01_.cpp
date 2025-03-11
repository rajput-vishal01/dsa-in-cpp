#include <iostream>
using namespace std;

/*
Trees - Non Linear Data Structure that stores data in the form of a hierarchy of nodes.
Traversal Types in tress:
(L= left sub tree R= right sub tree N= curr. Node)

(T.C-> O(N) S.C->O(N))
-pre order --NLR { LR is fixed and == pre =N phele}
-in order --LNR {LR is fixed and  == in =N beach}
-post order --LRN {LR is fixed and  == post =N end}


-level order
-morris traversal

*/

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


//T.C-> O(N)
Node* createTree() {
    cout << "Enter the Value for Node" << endl;
    int value;
    cin >> value;

    if(value == -1){
        return NULL;
    } else {
        Node* root = new Node(value);
        cout << "Adding left child for " << value << endl;
        root->left = createTree();
        cout << "Adding right child for " << value << endl;
        root->right = createTree();
        return root; // Return the constructed subtree.
    }
}


void preOrderTraversal(Node* root){
  if(root ==NULL){
    return;
  }
  //NLR
  //N
  cout<<root->data << "->";
  //L
  preOrderTraversal(root->left);
  //R
  preOrderTraversal(root->right);

}

void inOrderTraversal(Node* root){
  if(root==NULL){
    return;
  }

  //LNR
   //L
   preOrderTraversal(root->left);
   //N
   cout<<root->data << "->";
   //R
   preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
  if(root ==NULL){
    return;
  }
  //LRN
   //L
   preOrderTraversal(root->left);
  //R
  preOrderTraversal(root->right);
  //N
  cout<<root->data << "->";
}

int main() {
    Node* root;            
    root = createTree(); 

    if(root != NULL) {
        cout << "Printing root: " << root->data << endl;
    } else {
        cout << "Tree is empty." << endl;
    }

    cout<<"pre order traversal :"<<endl;
    preOrderTraversal(root);
    cout<<endl;

    cout<<"in order traversal :"<<endl;
    inOrderTraversal(root);
    cout<<endl;

    cout<<"post order traversal :"<<endl;
    postOrderTraversal(root);
    cout<<endl;
    return 0; 
}

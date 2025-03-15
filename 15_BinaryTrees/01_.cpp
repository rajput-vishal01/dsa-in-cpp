#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    this->data = val;
    left = NULL;
    right = NULL;
  }
};

/*
 * buildBST
 * --------
 * Inserts a value into the BST.
 * Time Complexity:
 *   - Average: O(log n)
 *   - Worst-case: O(n) when the tree is skewed.
 *
 * Space Complexity:
 *   - Average: O(log n) (recursive stack for a balanced tree)
 *   - Worst-case: O(n)
 */
Node* buildBST(int val, Node *root) {
  if (root == NULL) {
    root = new Node(val);
	return root;
  } else {
    if (val < root->data) {
      // val -> left subtree
      root->left = buildBST(val, root->left);
    } else {
      // val ->right subtree
      root->right = buildBST(val, root->right);
    }
  }
	return root;
}
/*
 * preorderTraversal
 * -----------------
 * Preorder traversal of the BST.
 *
 * Time Complexity: O(n)
 * Space Complexity:
 *   - Average: O(log n)
 *   - Worst-case: O(n)
 */   
void preorderTraversal(Node* root) {
	if(root == NULL)
		return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}
/*
 * inorderTraversal
 * ----------------
 * Inorder traversal of the BST.
 *
 * Time Complexity: O(n)
 * Space Complexity:
 *   - Average: O(log n)
 *   - Worst-case: O(n)
 */
void inorderTraversal(Node* root) {
	if(root == NULL)
		return;
	inorderTraversal(root->left);
	cout << root->data << " ";
	inorderTraversal(root->right);
}
/*
 * postorderTraversal
 * ------------------
 * Postorder traversal of the BST.
 *
 * Time Complexity: O(n)
 * Space Complexity:
 *   - Average: O(log n)
 *   - Worst-case: O(n)
 */
void postorderTraversal(Node* root) {
	if(root == NULL)
		return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout << root->data << " ";
}

/*
 * createTree
 * ----------
 * Builds the BST by inserting values provided by the user.
 * Time Complexity:
 *   - Average: O(k log k) for k nodes.
 *   - Worst-case: O(k^2) for k nodes in a skewed tree.
 *
 * Space Complexity: O(k) for storing nodes; recursive depth depends on tree height.
 */
void createTree(Node* &root) {
  cout << "Enter the value for Node: " << endl;
  int val;
  cin >> val;

  while (val != -1) {
    root = buildBST(val, root);
    cout << "Enter the value for Node: " << endl;
    cin >> val;
  }
}
/*
 * levelOrderTraversal
 * --------------------
 * Performs a level order (BFS) traversal of the BST.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) (queue size can grow up to n)
 */
void levelOrderTraversal(Node *root) {
  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty()) {
    Node *front = q.front();
    q.pop();
	
    if (front == NULL) {
      cout << endl;
      if (!q.empty()) {
        q.push(NULL);
      }
    } 
	else {
	  cout << front->data << " ";
      if (front->left) {
        q.push(front->left);
      }
      if (front->right) {
        q.push(front->right);
      }
    }
  }
}
/*
 * getMin
 * ------
 * Time Complexity:
 *   - Average: O(log n)
 *   - Worst-case: O(n)
 *
 * Space Complexity: O(1)
 */
int getMin(Node* root) {
	if(root == NULL) {
		return -1;
	}
	while(root->left != NULL) {
		root = root->left;
	}
	//iska mtlb, jab main yaha pohochunga
	//tab root extreme left pr hoga
	return root->data;
}

/*
 * getMax
 * ------
 *
 * Time Complexity:
 *   - Average: O(log n)
 *   - Worst-case: O(n)
 *
 * Space Complexity: O(1)
 */
int getMax(Node* root) {
	if(root == NULL) {
		return -1;
	}
	while(root->right != NULL) {
		root = root->right;
	}
	//iska mtlb, jab main yaha pohochunga
	//tab root extreme left pr hoga
	return root->data;
}
/*
 * searchBST
 * ---------
 * Time Complexity:
 *   - Average: O(log n)
 *   - Worst-case: O(n)
 *
 * Space Complexity:
 *   - Average: O(log n)
 *   - Worst-case: O(n)
 */
bool searchBST(Node* root, int target) {
	if(root == NULL) {
		return false;
	}
	if(root->data == target) {
		return true;
	}
	else {
		//data != target
		//decide -> left jau ya right jau
		if(target < root->data) {
			//left jao
			bool leftAns = searchBST(root->left, target);
			if(leftAns == true)
				return true;
		}
		else {
			//right jao
			bool rightAns = searchBST(root->right,  target);
			if(rightAns == true)
				return true;
		}
	}
	//agar leftAns / rightAns is false;
	return false;
}

/*
 * deleteFromBST
 * -------------
 * Time Complexity:
 *   - Average: O(log n)
 *   - Worst-case: O(n)
 *
 * Space Complexity:
 *   - Average: O(log n)
 *   - Worst-case: O(n)
 */
Node* deleteFromBST(Node* root, int target) {
  if (root == NULL)
    return NULL;
    
  if (target < root->data) {
    root->left = deleteFromBST(root->left, target);
    return root;
  } else if (target > root->data) {
    root->right = deleteFromBST(root->right, target);
    return root;
  } else {
    // Node to delete found
    // Case 1: No children (leaf node)
    if (root->left == NULL && root->right == NULL) {
      delete root;
      return NULL;
    }
    // Case 2: One child
    if (root->left == NULL) {
      Node* temp = root->right;
      delete root;
      return temp;
    }
    if (root->right == NULL) {
      Node* temp = root->left;
      delete root;
      return temp;
    }
    // Case 3: Two children
    // Find inorder successor (smallest in right subtree)
    int minValue = getMin(root->right);
    root->data = minValue;
    root->right = deleteFromBST(root->right, minValue);
    return root;
  }
}

int main() {
	Node *root = NULL;
	createTree(root);
	cout << "Printing Level Order:" << endl;
	levelOrderTraversal(root);
	cout << endl << "inorder: ";
	inorderTraversal(root);
	cout << endl << "preorder: ";
	preorderTraversal(root);
	cout << endl << "postorder: ";
	postorderTraversal(root);
	cout << endl;
	//NOTE: inorder of BST is always sorted
	cout << "Min Element: "<< getMin(root) << endl;
	cout << "Max Element: "<< getMax(root) << endl;
	
 
  bool searchAns = searchBST(root, 251);
	if(searchAns) 
		cout << "Node Found" << endl;
	else
		cout << "Node not found" << endl;
	

    // deletion:
  int deleteVal;
  cout << "\nEnter a value to delete: ";
  cin >> deleteVal;
  root = deleteFromBST(root, deleteVal);
  
  cout << "\nBST after deletion:" << endl;
  levelOrderTraversal(root);
  cout << endl;

  return 0;
}
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/*
-level order ::traversal
-Right dirn
-Left dirn
-Zig Zag dirn
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
    // cout << "Enter the Value for Nodes" << endl;
    int value;
    cin >> value;

    if (value == -1) {
        return NULL;
    } else {
        Node* root = new Node(value);
        // cout << "Adding left child for " << value << endl;
        root->left = createTree();
        // cout << "Adding right child for " << value << endl;
        root->right = createTree();
        return root; // Return the constructed subtree.
    }
}

void levelOrdertraversalR(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    // initial state maintain
    q.push(root);
    // Doing so that diff. b/w lvls
    q.push(NULL);
    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        if (front == NULL) {
            // means curr. lvl is completed
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << front->data << " ";

            if (front->left != NULL) {
                q.push(front->left);
            }
            if (front->right != NULL) {
                q.push(front->right);
            }
        }
    }
}

void levelOrdertraversalL(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    // initial state maintain
    q.push(root);
    // Doing so that diff. b/w lvls
    q.push(NULL);
    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        if (front == NULL) {
            // means curr. lvl is completed
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << front->data << " ";

            if (front->right != NULL) {
                q.push(front->right);
            }
            if (front->left != NULL) {
                q.push(front->left);
            }
        }
    }
}

void levelOrdertraversalZStack(Node* root) {
    // Zig Zag traversal using two stacks
    if (root == NULL)
        return;

    stack<Node*> currentLevel;
    stack<Node*> nextLevel;
    bool leftToRight = true;

    currentLevel.push(root);
    while (!currentLevel.empty()) {
        // Process all nodes at the current level.
        while (!currentLevel.empty()) {
            Node* node = currentLevel.top();
            currentLevel.pop();
            cout << node->data << " ";

            // If traversing left to right, push left child first, then right child.
            // Otherwise, push right child first, then left child.
            if (leftToRight) {
                if (node->left != NULL)
                    nextLevel.push(node->left);
                if (node->right != NULL)
                    nextLevel.push(node->right);
            } else {
                if (node->right != NULL)
                    nextLevel.push(node->right);
                if (node->left != NULL)
                    nextLevel.push(node->left);
            }
        }
        cout << endl;
        // Swap stacks and toggle the direction for the next level.
        swap(currentLevel, nextLevel);
        leftToRight = !leftToRight;
    }
}
 
int main() {
    Node* root;
    root = createTree();

    // Example input: 10 50 40 -1 -1 -1 30 20 -1 -1 -1

    cout << "Level Order Traversal - Right Direction:" << endl;
    levelOrdertraversalR(root);
    cout << endl;

    cout << "Level Order Traversal - Left Direction:" << endl;
    levelOrdertraversalL(root);
    cout << endl;

    cout << "Level Order Traversal - Zig Zag using Stack:" << endl;
    levelOrdertraversalZStack(root);

    return 0;
}

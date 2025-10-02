#include <iostream>
#include <queue>  // Needed for std::queue
using namespace std;

// Each node will store a string as its data
struct BinaryTreeNode {
    string data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(const string& value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void preorder(BinaryTreeNode* root) {

     if(root == nullptr) {
         return;
     }
    
     cout << root->data << " ";
     preorder(root->left);
     preorder(root->right);
}
// Only the order of the recursive calls change for pre-order and post-order
void inorder(BinaryTreeNode* root) {
    if (root == nullptr){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(BinaryTreeNode* root) {

     if(root == nullptr) {
         return;
     }
     
     postorder(root->left);
     postorder(root->right);
     cout << root->data << " ";
}
void levelorder(BinaryTreeNode* root) {
    if (root == nullptr) {
        return;
    }
    // Create a queue
    queue<BinaryTreeNode*> q;
    // Step 1: Enqueue root
    q.push(root);
    // While queue is not empty
    while (!q.empty()) {
        // Dequeue front node
        BinaryTreeNode* current = q.front();
        q.pop();
        // Process current node
        cout << current->data << " ";
        // Enqueue left child if it exists
        if (current->left) { 
            q.push(current->left);
        }
        // Enqueue right child if it exists
        if (current->right) { 
            q.push(current->right);
        }
    }
// Clean up the tree
    void freeTree(BinaryTreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    // Build demo tree:
    //         A
    //       /   \
    //      B     C
    //     / \   /
    //    D   E F

    BinaryTreeNode* root = new BinaryTreeNode("A");
    root->left = new BinaryTreeNode("B");
    root->right = new BinaryTreeNode("C");
    root->left->left = new BinaryTreeNode("D");
    root->left->right = new BinaryTreeNode("E");
    root->right->left = new BinaryTreeNode("F");
    cout << "In-order:   ";
    inorder(root);
    cout << "\n";

    cout << "Pre-order:  ";
    preorder(root);
    cout << "\n";

    cout << "Post-order: ";
    postorder(root);
    cout << "\n";
    cout << "Level-order: ";
    levelorder(root);
    cout << "\n";

    // Always free dynamically allocated memory
    freeTree(root);

    return 0;
}





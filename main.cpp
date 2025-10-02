#include <iostream>
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





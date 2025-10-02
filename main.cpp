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

void postorder(BinaryTreeNode* root) {

     if(root == nullptr) {
         return;
     }
     
     postorder(root->left);
     postorder(root->right);
     cout << root->data << " ";
}





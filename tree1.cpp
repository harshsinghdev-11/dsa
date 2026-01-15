#include <iostream>
using namespace std;


//class
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    //constructor
    TreeNode(int val){
        this->val = val;
        right = nullptr;
        left = nullptr;
    }
};

void inOrder(TreeNode *node){
    //base
    if(node == nullptr){
        return;
    }
    //left
    inOrder(node->left);
    //root
    cout<<node->val<<endl;
    //right
    inOrder(node->right);
}

void preOrder(TreeNode * node){
    //base
    if(node == nullptr) return;
    //root
    cout<<node->val<<endl;
    //left
    preOrder(node->left);
    //right
    preOrder(node->right);
}

//postOrder = left right root

int main(){

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(66);
    root->right->left = new TreeNode(43890);
    root->right->right = new TreeNode(6258);
    cout<<"inorder :";
    inOrder(root);
    cout<<"preOrder :";
    preOrder(root);
    

    return 0;
}
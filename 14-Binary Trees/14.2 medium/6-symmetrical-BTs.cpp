// Given the root of a binary tree, check whether it is a mirror of itself 
// (i.e., symmetric around its center).
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// time : O(N)
// space: O(h)
bool symmetry(TreeNode* left, TreeNode* right){
    if(left == nullptr && right == nullptr)
        return true;

    if(left == nullptr || right == nullptr)
        return false;

    if(left->data != right->data)
        return false;

    return symmetry(left->left, right->right) && symmetry(left->right, right->left);
}
bool isSymmetric(TreeNode* root){
    if(root == nullptr)
        return true;

    return symmetry(root->left, root->right);
}
// Given the root node of a binary tree. Return true if the given binary tree 
// is a binary search tree(BST) else false.
// A valid BST is defined as follows:
// The left subtree of a node contains only nodes with key strictly less than 
// the node's key.
// The right subtree of a node contains only nodes with key strictly greater 
// than the node's key.
// Both the left and right subtrees must also be binary search trees.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// Time Complexity O(N), Each node in the tree is visited once during the 
// inorder traversal.
// Space Complexity O(N), The recursive call stack can go up to the depth of 
// the tree and the ans list can also store N elements in the worst case.
bool validate(TreeNode* node, long min, long max){
    // base case: if the node is null, return true
    if(node == nullptr) return true;

    // check if the node's value falls within the valid range
    if(node->data <= min || node->data >= max) return false;

    // recursively validate the left subtree 
    // update the max value to the current node's value
    bool isLeftValid = validate(node->left, min, node->data);
    // recursively validate the right subtree
    // update the min value to the current node's value
    bool isRightValid = validate(node->right, node->data, max);

    // both subtrees must be valid for the tree to be a BST
    return isLeftValid && isRightValid;
}
bool isBST(TreeNode* root){
    return validate(root, LONG_MIN, LONG_MAX);
}
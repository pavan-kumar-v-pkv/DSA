// Given a binary tree root, find if it is height-balanced or not.
// A tree is height-balanced if the difference between the heights of left and 
// right subtrees is not more than one for all nodes of the tree. 
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// brute force using height of the tree as helper function
// time : O(N^2) where N is the number of nodes in the Binary Tree. 
// For each node in the Binary Tree, all other nodes are traversed to calculate 
// its height, resulting in a nested traversal structure, leading to O(N) 
// operations for each of the N nodes, hence O(N * N) = O(N^2).
// Space Complexity: O(N), because of the recursive stack space.
int getHeight(TreeNode* root){
    if(root == nullptr)
        return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}
bool isBalanced(TreeNode* root){
    // if the root is empty, it's balanced
    if(root == nullptr)
        return true;

    // calculate the height of left and right subtrees
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    // check if the absolute difference in heights of left and right subtrees is <= 1
    if(abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;

    return false;
}

// optimal approach:
// The O(N*N) time complexity of the previous method can be improved by 
// incorporating the balance check directly within the tree traversal process. 
// Instead of recalculating the heights of the left and right subtrees at each 
// node repeatedly, these heights can be determined in a bottom-up fashion via 
// postorder traversal. This method allows for the efficient validation of 
// balance conditions during traversal, minimizing redundant computations and 
// enabling the early identification of unbalanced nodes.
int dfsHeight(TreeNode* root){
    if(root == nullptr)
        return 0;

    int leftHeight = dfsHeight(root->left);
    if(leftHeight == -1) return -1;

    int rightHeight = dfsHeight(root->right);
    if(rightHeight == -1) return -1;

    if(abs(leftHeight - rightHeight) > 1) return -1;

    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced2(TreeNode* root){
    // check if the tree's height difference between subtrees is less than 2
    // if not, return false, otherwise return true
    return dfsHeight(root) != -1;
}


// Given the root of a binary tree, return the length of the diameter of the 
// tree.
// The diameter of a binary tree is the length of the longest path between any 
// two nodes in the tree. It may or may not pass through the root.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// brute force approach
// Time Complexity: O(N2) In this approach, for each node, we calculate the 
// height of its left and right subtrees, which takes O(N) time. Since this 
// calculation is done for each of the N nodes in the tree, the total time 
// complexity is O(N * N) = O(N2)

// Space Complexity: O(H) The space complexity is determined by the maximum 
// depth of the recursion stack, which corresponds to the height of the tree, 
// H. Thus, the space complexity is O(H).
int height(TreeNode* root){
    if(root == nullptr)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}
int diameterOfBinaryTree(TreeNode* root){
    if(root == nullptr) return 0;

    // get the height of left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // calculate diameter through the current node
    int currentDiameter = leftHeight + rightHeight;

    // recursively calculate the diameter of left and right subtrees
    int leftDiameter = diameterOfBinaryTree(root->left);
    int rightDiameter = diameterOfBinaryTree(root->right);

    // return the maximum of three values
    return max(currentDiameter, max(leftDiameter, rightDiameter));
}

// optimal approach:
// Time Complexity: O(N) In the optimized approach, each node is visited once, 
// and its height is calculated during the postorder traversal.

// Space Complexity: O(H) The space complexity is determined by the maximum 
// depth of the recursion stack, which corresponds to the height of the tree, 
// H.
int height2(TreeNode* node, int& diameter){
    if(!node){
        return 0;
    }

    int lh = height2(node->left, diameter);
    int rh = height2(node->right, diameter);
    diameter = max(diameter, lh+rh);

    return max(lh, rh) + 1;
}
int diameterOfBinaryTree2(TreeNode* root){
    int diameter = 0;
    height2(root, diameter);
    return diameter;
}










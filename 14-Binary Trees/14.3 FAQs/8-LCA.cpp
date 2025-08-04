// Given a root of binary tree, find the lowest common ancestor (LCA) of two 
// given nodes (p, q) in the tree.

// The lowest common ancestor is defined between two nodes p and q as the 
// lowest node in T that has both p and q as descendants (where we allow a 
// node to be a descendant of itself).
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// Complexity Analysis
// Time complexity: O(N) where n is the number of nodes.

// Space complexity: O(N), auxiliary space.

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    // base case
    if(root == nullptr || root == p || root == q){
        return root;
    }

    // Search in left and right subtrees
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // result
    if(left == nullptr){
        return right;
    }
    else if(right == nullptr){
        return left;
    }
    else{ // both left and right are not null, we found our result
        return root;
    }
}
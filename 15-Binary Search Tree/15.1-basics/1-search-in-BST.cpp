// Given the root of a binary search tree (BST) and an integer val.
// Find the node in the BST that the node's value equals val and return the 
// subtree rooted with that node. If such a node does not exist, return null.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// Time Complexity: O(log2(N)) : The time complexity is O(log2(N)) in a 
// balanced BST since the search space is halved at each step. However, in the 
// worst case (skewed tree), it can be O(N).

// Space Complexity: O(1): The space complexity is O(1) as the search is 
// performed iteratively without using additional space.
TreeNode* searchBST(TreeNode* root, int val){
    // Traverse the tree until we find the node with the given value or reach the end
    while(root != nullptr && root->data != val){
        // move to left or right child depending on the value comparison
        root = (root->data > val) ? root->left : root->right;
    }
    return root; 
}



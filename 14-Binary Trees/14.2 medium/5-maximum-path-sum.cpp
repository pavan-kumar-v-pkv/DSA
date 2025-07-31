// 🌳 Problem in Simple Words:
// We want to find the highest possible sum from any path in a binary tree.
// A path can start and end at any node, and it must follow parent-child links.

// 🧠 Step-by-Step Approach:
// ✅ 1. Think of each node as a turning point.
// Every node could be the center of the best path, so we must check the maximum path going through each node.

// ✅ 2. Use recursion to explore each node.
// We’ll write a function that:

// Visits every node,

// Calculates the best sum starting from the current node and going down to either the left or right child.

// ✅ 3. Ignore negative paths.
// If a subtree gives a negative sum, we just treat it as 0 — because adding it would reduce the total.

// ✅ 4. At every node, check the path through it.
// Add the node’s value.

// Add the max sum from the left and right children (only if they’re positive).

// Update a global max if this total is greater than any path seen before.

// ✅ 5. Return the best single path upward.
// When going back up the tree, only one path can continue (left or right). So we return:

// python
// Copy
// Edit
// node value + max(left sum, right sum)
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};
// Time Complexity: O(N) where N is the number of nodes in the Binary Tree. 
// This complexity arises from visiting each node exactly once during the 
// recursive traversal.

// Space Complexity: O(1) as no additional space or data structures are created 
// that are proportional to the input size of the tree. O(H) Recursive Stack 
// Auxiliary Space
int findMaxPathSum(TreeNode* root, int& maxi){
    // base case: if the current node is null, return 0
    if(root == nullptr)
        return 0;

    // calculate the maximum path sum for the left and right subtrees
    int leftMaxPath = max(0, findMaxPathSum(root->left, maxi));
    int rightMaxPath = max(0, findMaxPathSum(root->right, maxi));

    // update the overall maximum path sum including the current node
    maxi = max(maxi, leftMaxPath + rightMaxPath + root->data);
    // return the maximum sum considering only one branch along with current node
    return max(leftMaxPath, rightMaxPath) + root->data;
}

int maxPathSum(TreeNode* root){
    int maxi = INT_MIN;
    findMaxPathSum(root, maxi);
    return maxi;
}




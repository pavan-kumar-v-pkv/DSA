// Given the root node of a binary search tree (BST) and a value val to insert 
// into the tree. Return the root node of the BST after the insertion.
// It is guaranteed that the new value does not exist in the original BST. Note 
// that the compiler output shows true if the node is added correctly, else 
// false.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// Time Complexity: O(H), where H is the height of the tree, which in the worst
// case can be N (for a skewed tree), but for a balanced BST, it will be log(N).
// Space Complexity: O(N) For the worst-case scenario (a skewed tree), the 
// recursion depth will be N, and thus the space complexity will be O(N). 
// This accounts for both the tree and the recursive stack.

TreeNode* solve(TreeNode* root, int val){
    // if the current node is nullptr, create a new TreeNode with the given value
    if(root == nullptr)
        return new TreeNode(val);

    // Traverse the tree to find the correct position point
    if(val < root->data){
        // move to the left subtree
        root->left = solve(root->left, val);
    } else if(val > root->data){
        // move to the right subtree
        root->right = solve(root->right, val);
    }

    // return the potentially modified node
    return root;
}

TreeNode* insertIntoBST(TreeNode* root, int val){
    return solve(root, val);
}

// iterative approach:
TreeNode* insertIntoBST2(TreeNode* root, int val){
    if(root == nullptr)
        return new TreeNode(val);

    TreeNode* cur = root;
    while(true){
        if(cur->data < val){
            if(cur->right != nullptr) cur = cur->right;
            else{
                cur->right = new TreeNode(val);
                break;
            }
        }
        else{
            if(cur->left != nullptr) cur = cur->left;
            else{
                cur->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}

// Return the number of nodes in a binary tree given its root.
// Every level in a complete binary tree possibly with the exception of the 
// final one is fully filled, and every node in the final level is as far to 
// the left as it can be. At the last level h, it can have 1 to 2h nodes 
// inclusive.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// time: O((logn)^2)
// space: O(logn)
int findHeightLeft(TreeNode* root){
    int height = 0;
    while(root){
        height++;
        root = root->left;
    }
    return height;
}
int findHeightRight(TreeNode* root){
    int height = 0;
    while(root){
        height++;
        root = root->right;
    }
    return height;
}
int countNodes(TreeNode* root){
    if(root == nullptr)
        return 0;

    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);

    if(lh == rh)
        return (1<<lh) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Given two integer arrays Postorder and Inorder. Where Postorder is the 
// postorder traversal of a binary tree and Inorder is the inorder traversal of 
// the same tree.
// Construct and return the binary tree using the postorder and inorder arrays.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// Time Complexity : The time complexity of the algorithm is O(N) where N is 
// the number of nodes in the Binary Tree. This is because each node is 
// processed and visited exactly once.
// Space Complexity : The space complexity of the algorithm is O(N + log N) 
// where N is the number of nodes in the Binary Tree.
TreeNode* solve(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, unordered_map<int, int>& inMap){
    if(is > ie || ps > pe){
        return nullptr;
    }

    // create the root node fromt the last element in postorder
    TreeNode* root = new TreeNode(postorder[pe]);
    // find the index of root value in inorder to determine the left and right subtree

    int rootIndexInorder = inorder[root->data];
    int leftSubtreeSize = rootIndexInorder - is;

    root->left = solve(inorder, is, rootIndexInorder-1, postorder, ps, ps+leftSubtreeSize-1, inMap);
    root->right = solve(inorder, rootIndexInorder+1, ie, postorder, ps+leftSubtreeSize, pe-1, inMap);

    return root;

}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
    if(inorder.empty() || postorder.empty() || inorder.size() != postorder.size())
        return nullptr;

    // create a map to store the indices of elements in the inorder traversal
    unordered_map<int, int> inMap;
    for(int i=0;i<inorder.size();i++){
        inMap[inorder[i]] = i;
    }

    // call the helper function to build the binary tree
    return solve(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);
}
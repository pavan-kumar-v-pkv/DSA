// Given two integer arrays preorder and inorder. Where preorder is the 
// preorder traversal of a binary tree and inorder is the inorder traversal of 
// the same tree.
// Construct and return the binary tree using in-order and preorder arrays.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// Time Complexity : The time complexity is O(N), where N is the number of 
// nodes in the Binary Tree. This is because each node of the Binary Tree is 
// visited once.

// Space Complexity: O(N), where N is the number of nodes in the Binary Tree. 
// The inorder hashmap used to store the inorder array for fast lookup takes up 
// space proportional to the input nodes. Additionally, an auxiliary stack 
// space of approximately O(H) is used, where H is the height of the Binary 
// Tree.
TreeNode* solve(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inMap){
    // base case: if the start indices exceed the end indices, return null
    if(preStart > preEnd || inStart > inEnd)
        return nullptr;

    // create a new TreeNode with value at the current preorder index
    TreeNode* root = new TreeNode(preorder[preStart]);
    // find the index of the current root value in the inorder traversal
    int inRoot = inMap[root->data];
    // Calculate the number of elements in the left subtree
    int numsLeft = inRoot - inStart;

    // recursively build the left subtree
    root->left = solve(preorder, preStart + 1, preStart+numsLeft, inorder, inStart, inRoot-1, inMap);
    // recursively build the left subtree
    root->right = solve(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, inMap);

    // return the current root node
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
    // create a map tp store indices of elements in the inorder traversal
    unordered_map<int, int> inMap;
    // populate the map with indices of elements in the inorder traversal
    for(int i=0;i<inorder.size();i++){
        inMap[inorder[i]] = i;
    }
    // call the helper function to recursivel build the tree
    return solve(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
}
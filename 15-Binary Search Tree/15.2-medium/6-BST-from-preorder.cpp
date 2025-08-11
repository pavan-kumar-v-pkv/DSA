// Given an array of integers preorder, which represents the preorder traversal 
// of a BST (i.e., binary search tree), construct the tree and return its root.
// It is guaranteed that it is always possible to find a binary search tree 
// with the given requirements for the given test cases. Note. As there can be 
// many possible correct answers, the compiler outputs true if the solution is 
// correct, else false.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// Complexity Analysis
// Time Complexity: O(N) as each element is processed once.
// Space Complexity: O(N) due to the stack storing nodes.
TreeNode* buildBST(vector<int>& preorder, int& idx, int minVal, int maxVal){
    if(idx >= preorder.size())
        return nullptr;

    int val = preorder[idx];
    if(val <= minVal || val >= maxVal) return nullptr; // not in range

    TreeNode* root = new TreeNode(val);
    idx++;

    root->left = buildBST(preorder, idx, minVal, val);
    root->right = buildBST(preorder, idx, val, maxVal);

    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder){
    int idx = 0;
    return buildBST(preorder, idx, INT_MIN, INT_MAX);
}

/// another approach
TreeNode* build(vector<int>& preorder, int& i, int ub){
    if(i == preorder.size() || preorder[i] > ub){
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[i]);
    i++;

    root->left = build(preorder, i, root->data);
    root->right = build(preorder, i, ub);

    return root;
}
TreeNode* bstFromPreorder2(vector<int>& preorder){
    int i = 0;
    return build(preorder, i, INT_MAX);
}




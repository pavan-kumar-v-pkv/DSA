// Given a root of Binary Tree, perform the boundary traversal of the tree. 

// The boundary traversal is the process of visiting the boundary nodes of the 
// binary tree in the anticlockwise direction, starting from the root.

// The boundary of a binary tree is the concatenation of the root, the left 
// boundary, the leaves ordered from left-to-right, and the reverse order of 
// the right boundary.

// The left boundary is the set of nodes defined by the following:
// The root node's left child is in the left boundary. If the root does not 
// have a left child, then the left boundary is empty.
// If a node in the left boundary and has a left child, then the left child is 
// in the left boundary.
// If a node is in the left boundary, has no left child, but has a right child, 
// then the right child is in the left boundary.
// The leftmost leaf is not in the left boundary.
// The right boundary is similar to the left boundary, except it is the right 
// side of the root's right subtree. Again, the leaf is not part of the right 
// boundary, and the right boundary is empty if the root does not have a right 
// child.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// time: O(N)
// space: O(N)
// Function to check if a node is a leaf
bool isLeaf(TreeNode* root){
    return !root->left && !root->right;
}

// Function to add the left boundary of the tree
void addLeftBoundary(TreeNode* root, vector<int>& res){
    TreeNode* curr = root->left;
    while(curr) {
        if(!isLeaf(curr)){
            res.push_back(curr->data);
        }
        if(curr->left){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
}

// Function to add the right boundary of the tree
void addRightBoundary(TreeNode* root, vector<int>& res){
    TreeNode* curr = root->right;
    vector<int> temp;

    while(curr){
        if(!isLeaf(curr)){
            temp.push_back(curr->data);
        }
        if(curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}

// function to add the leaves of the tree
void addLeaves(TreeNode* root, vector<int>& res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left)
        addLeaves(root->left, res);
    if(root->right)
        addLeaves(root->right, res);
}

vector<int> boundary(TreeNode* root){
    vector<int> res;
    if(!root)
        return res;

    if(!isLeaf(root)){
        res.push_back(root->data);
    }

    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}
// Given root of binary tree, return the Inorder traversal of the binary tree.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// recursive approach
// time: O(N), where n is the number of nodes in the tree due to traversal of each node once
// space: O(h), where h is the height of the tree for the recursion stack, plus O(n) for the output array
void recursiveInorder(TreeNode* root, vector<int>& arr){
    if(root == nullptr)
        return;

    recursiveInorder(root->left, arr);
    arr.push_back(root->data);
    recursiveInorder(root->right, arr);
}

vector<int> inorder(TreeNode* root){
    vector<int> arr;
    recursiveInorder(root, arr);
    return arr;
}

// Iterative approach using stack
// time: O(N) since each node is processed once in binary tree
// space: O(h), where h is the height of the binary tree
vector<int> inorder2(TreeNode* root){
    // initialise a stack to track nodes
    stack<TreeNode*> st;
    // start from the root node
    TreeNode* node = root;
    vector<int> inorder;

    // start an infinite loop for traversal
    while(true){
        // if the current node is not NULL
        if(node != nullptr){
            // push the current node to the stack
            st.push(node);
            // move to the left child of the current node
            node = node->left;
        }
        else{
            // if the stack is empty, break the loop 
            // cuz we traversed the entire tree
            if(st.empty()){
                break;
            }
            // retrieve a node from the stack
            node = st.top();
            st.pop();
            // add the node's value to the inorder traversal list
            inorder.push_back(node->data);
            // move to right child of the current node
            node = node->right;
        }
    }
    return inorder;
    
}
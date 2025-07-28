// Given root of binary tree, return the preorder traversal of the binary tree.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// recursive approach
// time: O(N) where N is the number of nodes in the binary tree, as each node of the binary tree is visited exactly once
// space: O(N)
void func(TreeNode* node, vector<int>& ans){
    if(node==nullptr)
        return;

    ans.push_back(node->data);
    func(node->left, ans);
    func(node->right, ans);
}

vector<int> preorder(TreeNode* root){
    vector<int> ans;
    func(root, ans);
    return ans;
}

// iterative approach using stack
// time: O(n)
// space: O(n)
vector<int> preorder2(TreeNode* root){
    vector<int> preorder;
    if(root==nullptr)
        return preorder;

    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()){
        // get the current node from the top of the stack
        root = st.top();
        // remove the node from the stack
        st.pop();

        // add the node's value to the preorder traversal result
        preorder.push_back(root->data);
        // push the right child onto the stack if exists
        if(root->right != nullptr){
            st.push(root->right);
        }
        // push the left child onto the stack if exists
        if(root->left != nullptr){
            st.push(root->left);
        }
    }

    return preorder;
}

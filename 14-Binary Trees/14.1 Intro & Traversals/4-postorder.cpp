// Given root of binary tree, return the Postorder traversal of the binary tree.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// recursive solution
// time: O(N)
// space: O(N)
void recursivePostorder(TreeNode* root, vector<int>& ans){
    if(root == nullptr)
        return;

    recursivePostorder(root->left, ans);
    recursivePostorder(root->right, ans);
    ans.push_back(root->data);
}
vector<int> postorder(TreeNode* root){
    vector<int> arr;
    recursivePostorder(root, arr);
    return arr;
}

// iterative approach:
// The idea behind the iterative approach will be to use a stack to perform 
// postorder traversal to mimick the recursive stack. A recursive approach 
// naturally follows this order by going left, then right, and finally visiting 
// the root when returning from recursion. But in an iterative approach, we 
// don't have the function call stack to track nodes, so we need a way to 
// simulate this order.

// A key observation is that if we traverse the tree in Root → Right → Left 
// order (a modified preorder), the result will be a reverse of postorder. 
// This means that if we store nodes in this reversed order and then reverse 
// the list at the end, we get the desired postorder sequence.

// time: O(n)
// space: O(n)
vector<int> postorder2(TreeNode* root){
    vector<int> ans;
    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        ans.push_back(node->data);

        if(node->left) st.push(node->left);
        if(node->right) st.push(node->right);
    }
    // reverse the list to get the postorder traversal
    reverse(ans.begin(), ans.end());
    return ans;
}
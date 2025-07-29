// Given a binary tree with root node. Return the In-order,Pre-order and 
// Post-order traversal of the binary tree.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// time : O(3n)
// space: O(3n)
// approach:
// Approach
// 1. Create three vectors to store the results of Preorder, Inorder, and 
// Postorder traversals. Use a stack to keep track of nodes and their traversal 
// states. Start with the root node and a state of 1 (indicating Preorder).While
// the stack is not empty, pop the top element from the stack.
// 2. If the state is 1 (Preorder), add the node's data to the Preorder vector, 
// change the state to 2 (Inorder) and push the node back onto the stack. If 
// the node has a left child, push it onto the stack with a state of 1.
// 3. If the state is 2 (Inorder), add the node's data to the Inorder vector. 
// change the state to 3 (Postorder) and push the node back onto the stack. If 
// the node has a right child, push it onto the stack with a state of 1.
// 4. If the state is 3 (Postorder), Add the node's data to the Postorder vector. 
// Return the vectors containing the Preorder, Inorder, and Postorder traversals.

vector<vector<int> > treeTraversal(TreeNode* root){
    vector<int> pre, in, post;
    if(root == nullptr)
        return {in, pre, post};

    // stack to maintain nodes and their traversal state
    stack<pair<TreeNode*, int> > st;

    // start with the root node and state 1 (preorder)
    st.push({root, 1});

    while(!st.empty()){
        // get the top element from the stack
        auto [node, state] = st.top();
        st.pop();

        // process the node based on its state
        if(state == 1){
            // preorder:  add node data
            pre.push_back(node->data);
            // change the state to 2 (inorder) for this node
            st.push({node, 2});
            // push left child onto the stack for processing
            if(node->left != nullptr){
                st.push({node->left, 1});
            }
        }
        else if(state == 2){
            // Inorder: add node data
            in.push_back(node->data);
            // change the state to 3 (postorder) for this node
            st.push({node, 3});

            // push right child onto the stack for processing
            if(node->right != nullptr){
                st.push({node->right, 1});
            }
        }
        else{
            // Postorder: add node data
            post.push_back(node->data);
        }
    }
    return {in, pre, post};
}
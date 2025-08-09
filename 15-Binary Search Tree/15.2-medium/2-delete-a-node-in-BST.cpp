// Given the root node of a binary search tree (BST) and a value key. Return 
// the root node of the BST after the deletion of the node with the given key 
// value.
// Note: As there can be many correct answers, the compiler returns true if 
// the answer is correct, otherwise false.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// Time Complexity: O(H), explanation is that the time complexity is dependent 
// on the height of the tree.
// Space Complexity: O(H), explanation is that the maximum depth of the 
// recursion call stack is equal to the height of the tree.

// function to delte a node with a specific key from the BST
TreeNode* connector(TreeNode* root){
    // case 1: if the node has no left child, 
    // return the right subtree to bypass the node
    if(!root->left)
        return root->right;

    // case 2: if the node has no right child, return the left subtree to bypass the node.
    else if(!root->right)
        return root->left;

    // case 3: if the node has both left and right children:
    // 1. Save the left subtree in a temp variable.
    // 2. Find the leftmost node in the right subtree
    // 3. Attach the left subtree to the leftmost node in the right subtree
    TreeNode* leftchild = root->left;
    TreeNode* leftmost_child_in_right_subtree = root->right;
    // traverse to the leftmost node in the right subtree
    while(leftmost_child_in_right_subtree->left){
        leftmost_child_in_right_subtree = leftmost_child_in_right_subtree->left;
    }

    // attach the left subtree to the leftmost node in the right subtree.
    leftmost_child_in_right_subtree->left = leftchild;

    // return the right subtree as the new root of the modified tree.
    return root->right;
}
TreeNode* deleteNode(TreeNode* root, int key){
    // base case: if the tree is empty, return NULL
    if(root == nullptr)
        return nullptr;

    // if the node to be deleted is the root node,
    // use the connector function to replace the root.
    if(root->data == key){
        return connector(root);
    }

    // traverse the tree to find the node to be deleted
    TreeNode* node = root;
    while(node) {
        // if the key to be deleted is smaller than the current node's data,
        // move to the left subtree
        if(node->data > key){
            // if the left child is the node to be deleted,
            // update the left child with the connector function
            if(node->left && node->left->data == key) {
                node->left = connector(node->left);
                break;
            }
            else{
                node = node->left;
            }
        }
        // if the key to be deleted is larges in larger than the current node's data,
        // move to the right subtree
        else{
            // if the right child is the node to be deleted,
            // update the right child with the connector function.
            if(node->right && node->right->data == key){
                node->right = connector(node->right);
                break;
            } else {
                node = node->right;
            }
        }
    }
    return root;
}


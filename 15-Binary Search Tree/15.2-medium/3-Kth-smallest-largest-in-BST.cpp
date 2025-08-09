// Given the root node of a binary search tree (BST) and an integer k.

// Return the kth smallest and largest value (1-indexed) of all values of the 
// nodes in the tree.

// Return the 1st integer as kth smallest and 2nd integer as kth largest in 
// the returned array.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// brute force approach
// time: O(N)
// space: O(N)
void inorder(TreeNode* root, vector<int>& in){
    if(!root)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
vector<int> kLargeSmall(TreeNode* root, int k){
    // vector to store the node values
    vector<int> values;
    // perform inorder traversal and collect values
    inorder(root, values);
    int n = values.size();
    int kth_smallest = values[k-1];
    int kth_largest = values[n-k];  

    return {kth_smallest, kth_largest};
}

// optimal approach
// Time Complexity O(N), where N is the number of nodes in the binary tree. 
// The reason is that in the worst-case scenario, the inorder and reverse 
// inorder traversals visit each node exactly once.
// Space Complexity O(H), where H is the height of the binary tree.
class Solution {
public:
    // Function to find the kth smallest element
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        this->result = -1;
        inorder(root);
        return result;
    }

    // Function to find the kth largest element
    int kthLargest(TreeNode* root, int k) {
        this->k = k;
        this->result = -1;
        reverse_inorder(root);
        return result;
    }

    // Function to return kth smallest and kth largest elements
    vector<int> kLargesSmall(TreeNode* root, int k) {
        return {kthSmallest(root, k), kthLargest(root, k)};
    }

private:
    int k;
    int result;

    // Helper function for inorder traversal
    void inorder(TreeNode* node) {
        if (node != nullptr) {
            inorder(node->left);
            if (--k == 0) {
                result = node->data;
                return;
            }
            inorder(node->right);
        }
    }

    // Helper function for reverse inorder traversal
    void reverse_inorder(TreeNode* node) {
        if (node != nullptr) {
            reverse_inorder(node->right);
            if (--k == 0) {
                result = node->data;
                return;
            }
            reverse_inorder(node->left);
        }
    }
};


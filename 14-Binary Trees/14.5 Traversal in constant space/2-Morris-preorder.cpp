// Given root of binary tree, return the Inorder traversal of the binary tree.
// Morris Inorder Traversal is a tree traversal algorithm aiming to achieve a 
// space complexity of O(1) without recursion or an external data structure.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// Time Complexity: O(2N), where N is the number of nodes in the Binary Tree. 
// Each node is visited at most twice.
// Space Complexity: O(1). Morris Traversal is an in-place algorithm, using 
// only a constant amount of extra space.

vector<int> preorder(TreeNode* root){
    vector<int> pre;
    TreeNode* cur = root;

    while(cur != nullptr){
        if(cur->left == nullptr){
            pre.push_back(cur->data);
            cur = cur->right;
        }
        else{
            TreeNode* prev = cur->left;
            while(prev->right && prev->right != cur){
                prev = prev->right;
            }

            if(prev->right == nullptr){
                prev->right = cur;
                pre.push_back(cur->data);
                cur = cur->left;
            }
            else{
                prev->right = nullptr;
                cur = cur->right;
            }
        }
    }
    return pre;
}



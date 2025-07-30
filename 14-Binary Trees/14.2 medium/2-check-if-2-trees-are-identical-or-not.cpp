// Given the roots of two binary trees p and q, write a function to check if 
// they are the same or not.
// Two binary trees are considered the same if they are structurally identical, 
// and the nodes have the same value.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};
// use any of the traversal, here we'll be using preorder
// time: O(N) Visit each node exactly once during the traversal, where N is the number of nodes in the tree.
// space: O(h), h is the height of the tree

bool isSameTree(TreeNode* p, TreeNode* q){
    // if both nodes are null, the trees are same
    if(p == nullptr && q == nullptr){
        return true;
    }

    // if one of the nodes is null, the trees are not the same
    if(p == nullptr || q == nullptr){
        return false;
    }

    // if the values of the nodes are different, the trees are not the same
    if(p->data != q->data){
        return false;
    }

    // recursively check the left and right subtrees
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}



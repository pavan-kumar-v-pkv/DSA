// Given root of the binary tree, return its maximum depth.
// A binary tree's maximum depth is number of nodes along the longest path from 
// root node down to the farthest node.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// recursive approach
// time: O(N)
// space: O(h), h is the height of the tree
int maxDepth(TreeNode* root){
    if(root == nullptr)
        return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    // depth of tree is 1 current node + maximum depth of subtrees
    return 1 + max(left, right);
}

// iterative approach using level order traversal
int maxDepth2(TreeNode* root){
    if(root == nullptr)
        return 0;

    queue<TreeNode*> q;
    q.push(root);
    int level = 0;

    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* front = q.front();
            q.pop();

            if(front->left != nullptr){
                q.push(front->left);
            }
            if(front->right != nullptr){
                q.push(front->right);
            }
        }
        level++;
    }
    return level;
}

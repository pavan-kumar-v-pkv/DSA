// Given the root of a binary search tree (BST), where the values of exactly 
// two nodes of the tree were swapped by mistake.Recover the tree without 
// changing its structure.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// brute force approach
// time: O(N*logN)
// space: O(N)
class Solution{
    public:
    void recoverTree(TreeNode* root){
        // step 1: collect node values via inorder traversal
        collectInorder(root);
        // step 2: sort the values to get the correct inorder sequence
        sort(inorderValues.begin(), inorderValues.end());
        // step 3: traverse again and assign sorted values back
        restoreInorder(root);
    }

    private:
    vector<int> inorderValues;
    int index = 0;

    void collectInorder(TreeNode* root){
        if(!root) return;
        collectInorder(root->left);
        inorderValues.push_back(root->data);
        collectInorder(root->right);
    }

    void restoreInorder(TreeNode* root){
        if(!root) return;
        restoreInorder(root->left);
        root->data = inorderValues[index++];
        restoreInorder(root->right);
    }
};

// time:
class Solution2 {
    private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root){
        if(root == nullptr)
            return;

        inorder(root->left);
        if(prev != nullptr && (root->data < prev->data)){
            // if this is the first violation, mark these two nodes as 'first' and 'middle'
            if(first == nullptr)
            {
                first = prev;
                middle = root;
            }
            else{
                // if this is the second violation, mark this node as last
                last = root;
            }
            
        }
        // mark this node as previous 
        prev = root;
        inorder(root->right);
    }
    public:
    void recoverTree(TreeNode* root){
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->data, last->data);
        else if(first && middle) swap(first->data, middle->data);
    }
};
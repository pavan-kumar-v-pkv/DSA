// Given the root node of a binary search tree (BST) and an integer key. Return 
// the Inorder predecessor and successor of the given key from the provided BST.
// If predecessor or successor is missing then return -1.
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
void inorder(TreeNode* root, vector<int>& ans){
    if(root == nullptr)
        return;
    
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

vector<int> succPredBST(TreeNode* root, int key){
    vector<int> inorderList;
    inorder(root, inorderList);

    int predecessor = -1;
    int successor = -1;

    for(int i=0;i<inorderList.size();i++){
        if(inorderList[i] < key){
            // update predecessor if the current value is less than the key
            predecessor = inorderList[i];
        } else if(inorderList[i] > key){
            // update successor if the current value is greater than the key
            successor = inorderList[i];
            break; // no need to coniue onces successor is found
        }
    }
    return {predecessor, successor};
}

// optimal approach
void findSucc(TreeNode* root, int key, int& successor){
    while(root != nullptr){
        if(root->data <= key){
            root = root->right;
        }
        else{
            successor = root->data;
            root = root->left;
        }
    }
    
}
void findPre(TreeNode* root, int key, int& predecessor){
    while(root != nullptr){
        if(root->data >= key){
            root = root->left;
        }
        else{
            predecessor = root->data;
            root = root->right;
        }
    }
    
}
vector<int> succPredBST2(TreeNode* root,int key){
    //your code goes here
    int predecessor = -1;
    int successor = -1;

    findPre(root, key, predecessor);
    findSucc(root, key, successor);

    return {predecessor, successor};
}
// Given a root of binary search tree and a key(node) value, find the floor and 
// ceil value for that particular key value.

// Floor Value Node: Node with the greatest data lesser than or equal to the 
// key value. 
// Ceil Value Node: Node with the smallest data larger than or equal to the 
// key value.
// If a particular floor or ceil value is not present then output -1.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// Time Complexity : O(H) where h is the height of the BST, since we traverse 
// down the tree once for each of the floor and ceil searches

// Space Complexity : O(1) as we only use a constant amount of extra space for 
// storing the floor and ceil values.

vector<int> floorCeilOfBST(TreeNode* root, int key){
    int floor = -1;
    int ceil = -1;

    TreeNode* cur = root;
    while (cur) {
        // if the key matches the current node's value
        if(cur->data == key){
            // set the floor to this value
            floor = cur->data;
            break;
        }
        else if(cur->data < key){
            floor = cur->data;
            cur = cur->right;
        }
        else{
            cur = cur->left;
        }
    }

    cur = root;
    while(cur){
        if(cur->data == key){
            ceil = cur->data;
            break;
        }
        else if(cur->data > key){
            ceil = cur->data;
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }
    
    return {floor, ceil};
}
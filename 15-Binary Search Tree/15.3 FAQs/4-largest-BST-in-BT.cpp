// Given a root of Binary Tree, where the nodes have integer values. Return the 
// size of the largest subtree of the binary tree which is also a BST.

// A binary search tree (BST) is a binary tree data structure which has the 
// following properties.

// The left subtree of a node contains only nodes with data less than the 
// node’s data.
// The right subtree of a node contains only nodes with data greater than the 
// node’s data.
// Both the left and right subtrees must also be binary search trees.

#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

class Solution{
    public:
    tuple<int, bool, int, int> isBSTAndSize(TreeNode* node, int minVal, int maxValue){
        // base case: if node is nullptr, it is a valid BST of size 0;
        if(node == nullptr){
            return make_tuple(0, true, INT_MAX, INT_MIN);
        }

        // recursively check using postorder
        auto [leftSize, isLeftBST, leftMin, leftMax] = isBSTAndSize(node->left, minVal, node->data);
        auto [rightSize, isRightBST, rightMin, rightMax] = isBSTAndSize(node->right, node->data, maxValue);

        // check if the current node is a valide BST node
        if(isLeftBST && isRightBST && leftMax < node->data && node->data < rightMin){
            // current subtree is a valid BST, calculate the size
            int size = 1 + leftSize + rightSize;
            return make_tuple(size, true, min(node->data, leftMin), max(node->data, rightMax));
        }
        else{
            // current subtree is not a valid BST, return the size if the kargest valid BST
            return make_tuple(max(leftSize, rightSize), false, INT_MIN, INT_MAX);
        }
    }
    int largestBST(TreeNode* root){
        return get<0>(isBSTAndSize(root, INT_MIN, INT_MAX));
    }
};

// time: O(N)
// space: O(H)

// Given root of binary tree, return the Inorder traversal of the binary tree.
// Morris Inorder Traversal is a tree traversal algorithm aiming to achieve a 
// space complexity of O(1) without recursion or an external data structure.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// Approach:
// 1. Begin by initializing the current node to the root of the binary tree.
// 2. While the current node is not null:
//     2.1 If the current node lacks a left child, print its value and move to the 
//     right child by setting the current node to its right child.

//     2.2 If the current node has a left child:
//         Identify the in-order predecessor of the current node, which is the 
//         rightmost node in the left subtree.

//         If the right child of the in-order predecessor is null, create a 
//         thread by setting its right child to the current node. Then, move 
//         to the left child by updating the current node to its left child.

//         If the right child of the in-order predecessor is not null, this 
//         indicates a previously established thread. Revert this change by 
//         setting the right child of the in-order predecessor back to null. 
//         Print the current node's value and then move to the right child by 
//         setting the current node to its right child.
// 3. Repeat the above steps until the traversal reaches the end of the tree.

// Time Complexity: O(2N), where N is the number of nodes in the Binary Tree.
// Each node is visited at most twice.
// Space Complexity: O(1). Morris Traversal is an in-place algorithm, using 
// only a constant amount of extra space.

vector<int> getInorder(TreeNode* root){
    //vector to store inorder traversal
    vector<int> inorder;
    // pointer to current node
    TreeNode* cur = root;

    while(cur != nullptr){
        if(cur->left == nullptr){
            // add current node's value and move to right child
            inorder.push_back(cur->data);
            cur = cur->right;
        }
        else{
            // find current node's predecessor
            TreeNode* prev = cur->left;
            while(prev->right && prev->right != cur){
                prev = prev->right;
            }
            // establish a temporary link and move to the left child
            if(prev->right == nullptr){
                prev->right = cur;
                cur = cur->left;
            }
            else{
                // remove the temporary link, add current node's value and move to the right child
                prev->right = nullptr;
                inorder.push_back(cur->data);
                cur = cur->right;
            }
        }
    }
    return inorder;
}

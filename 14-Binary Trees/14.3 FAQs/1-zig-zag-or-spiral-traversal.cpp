// Given the root of a binary tree, return the zigzag level order traversal of 
// its nodes' values. (i.e., from left to right, then right to left for the 
// next level and alternate between).
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// approach: level order traversal along with flag variable to have that zig-zag logic
// time: O(N)
// space: O(N)
vector<vector<int> > zigzagLevelOrder(TreeNode* root){
    vector<vector<int> > result;

    if(root == nullptr)
        return result;

    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);

    bool leftToRight = true;

    while(!nodesQueue.empty()){
        int size = nodesQueue.size();
        vector<int> row(size);

        for(int i=0;i<size;i++){
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();

            // determine the index to insert the node's value based on the traversal direction
            int index = leftToRight ? i : (size - i - 1);
            // insert the node's value at the determined index
            row[index] = node->data;

            if(node->left)
                nodesQueue.push(node->left);
            if(node->right)
                nodesQueue.push(node->right);
        }
        // switch the traversal direction for the next level
        leftToRight = !leftToRight;
        // add the current level's values to the result vector
        result.push_back(row);
    }
    return result;
}
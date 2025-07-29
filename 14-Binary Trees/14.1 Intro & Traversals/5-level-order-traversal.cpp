// Given the root of a binary tree, return the level order traversal of its 
// nodes' values. (i.e., from left to right, level by level).
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

//time: O(N)
//space: O(N)
vector<vector<int> > levelOrder(TreeNode* root){
    vector<vector<int> > ans;
    if(root == nullptr)
        return ans;
    // create a queue to store nodes for level-orrder traversal
    queue<TreeNode*> q;
    // push yhe root node to the queue
    q.push(root);

    while(!q.empty()){
        // get the size of the current level
        int size = q.size();
        vector<int> level;

        for(int i=0;i<size;i++){
            // get the front node in the queue
            TreeNode* node = q.front();
            // remove the front node from the queue
            q.pop();
            // store the node value in current level vector
            level.push_back(node->data);

            // enqueue the child nodes if they exist
            if(node->left != nullptr)
                q.push(node->left);
            if(node->right != nullptr)
                q.push(node->right);
        }
        ans.push_back(level);

    }
    return ans;
}
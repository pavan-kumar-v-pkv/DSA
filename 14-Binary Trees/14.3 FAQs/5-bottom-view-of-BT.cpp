// Given root of binary tree, return the bottom view of the binary tree.
// The bottom view of a binary tree is the set of nodes visible when the tree 
// is viewed from the bottom. Return nodes from the leftmost node to the 
// rightmost node. Also if 2 nodes are outside the shadow of the tree and are 
// at the same position then consider the node that appears later in level 
// traversal.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};


// time: O(NlogN)
// space: O(N)
vector<int> bottomView(TreeNode* root){
    vector<int> ans;
    if(root == nullptr)
        return ans;

    // map {vertical, node's data}
    map<int, int> mpp;
    // queue {Node, vertical}
    queue<pair<TreeNode*, int> >q;
    q.push({root, 0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        int vertical = it.second;

        // update the map with the node's data for the current vertical position
        mpp[vertical] = node->data;

        if(node->left){
            q.push({node->left, vertical-1});
        }
        if(node->right){
            q.push({node->right, vertical+1});
        }
    }

    for(auto it: mpp){
        ans.push_back(it.second);
    }

    return ans;
}



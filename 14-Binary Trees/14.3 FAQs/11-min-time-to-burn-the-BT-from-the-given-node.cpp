// Given a target node data and a root of binary tree. If the target is set on 
// fire, determine the shortest amount of time needed to burn the entire binary 
// tree.
// It is known that in 1 second all nodes connected to a given node get burned. 
// That is its left child, right child, and parent.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// Time Complexity : O(N) where n is the number of nodes in the tree, due 
// to BFS traversals
// SpaceComplexity : O(N) for storing the parent mapping and the visited set.
TreeNode* bfsToMapParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mpp, int start){
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* res = new TreeNode(-1);

    while(!q.empty()){
        // get the front node from the queue
        TreeNode* node = q.front();
        q.pop();
        // check if this is the start node
        if(node->data == start) res = node;
        // map the left child to its parent
        if(node->left){
            mpp[node->left] = node;
            q.push(node->left);
        }
        if(node->right){
            mpp[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}
int findMaxDistance(unordered_map<TreeNode*, TreeNode*>& mpp, TreeNode* target){
    queue<TreeNode*> q;
    q.push(target);
    unordered_map<TreeNode*, int> vis;
    vis[target] = 1;
    int maxi = 0;
    
    while(!q.empty()){
        int size = q.size();
        int fl = 0;

        for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            q.pop();

            // check left child
            if(node->left && vis.find(node->left) == vis.end()){
                fl = 1;
                vis[node->left] = 1;
                q.push(node->left);
            }
            // check right child
            if(node->right && vis.find(node->right) == vis.end()){
                fl = 1;
                vis[node->right] = 1;
                q.push(node->right);
            }
            // check parent node
            if(mpp.find(node) != mpp.end() && vis.find(mpp[node]) == vis.end()){
                fl = 1;
                vis[mpp[node]] = 1;
                q.push(mpp[node]);
            }
        }
        if(fl == 1) maxi++;
    }
    return maxi;
}
int timeToBurnTree(TreeNode* root, int start){
    // create a map to store the parent nodes
    unordered_map<TreeNode*, TreeNode*> mpp;
    // get the target node (starting node for burning)
    TreeNode* target = bfsToMapParents(root, mpp, start);
    // find the maxi distance to burn the tree (min time)
    int maxi = findMaxDistance(mpp, target);
    return maxi;
}



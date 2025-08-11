// Given the root node of a binary search tree (BST) and two node values p,q.

// Return the lowest common ancestors(LCA) of the two nodes in BST.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// brute force approach, where u get the path from root to node for both the
// given nodes and get the last common node and return it
// Time Complexity O(N + log(2N)), where N is the number of nodes. Finding 
// the root-to-node paths using DFS is O(N), and iterating through arrays is 
// O(min(P1, P2)).

// Space Complexity O(log2 N) due to storing root-to-node paths and the 
// recursion stack during DFS. The height of the tree (log2(N)) determines 
// the space required for arrays and the maximum depth of the recursion stack.
bool getPath(TreeNode* root, vector<int>& path, int x){
    if(!root)
        return false;

    // add the current node's value to the path vector
    path.push_back(root->data);

    // if the current node's value is equal to the target value 'x', return true
    if(root->data == x)
        return true;

    // recursively search for the target value 'x' in the left and right subtrees
    if(getPath(root->left, path, x) || getPath(root->right, path, x))
        return true;

    // if the target value 'x' is not found int the current path, backtrack
    path.pop_back();
    return false;
}
TreeNode* lca(TreeNode* root, int p, int q){
    vector<int> path1, path2;
    // find paths from the root to the given nodes
    if(!getPath(root, path1, p) || !getPath(root, path2, q))
        return nullptr;

    // find the last common element in the paths
    int i = 0;
    while(i < path1.size() && i < path2.size() && path1[i] == path2[i])
        i++;
    // the last common element is the LCA
    return new TreeNode(path1[i-1]);
}

// optimal method:
// time: O(H)
// space: O(H)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == nullptr)
        return nullptr;

    int cur = root->data;

    if(cur < p->data && cur < q->data)
        return lowestCommonAncestor(root->right, p, q);

    if(cur > p->data && cur > q->data)
        return lowestCommonAncestor(root->left, p, q);

    return root;
}


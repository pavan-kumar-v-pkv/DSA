// Given the root of a binary tree, return the maximum width of the given tree.
// The maximum width of a tree is the maximum width among all levels. The width
// of a level is determined by measuring the distance between its end nodes, 
// which are the leftmost and rightmost non-null nodes. The length calculation
// additionally takes into account the null nodes that would be present between 
// the end nodes if a full binary tree were to stretch down to that level.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// time: O(N)
// space: O(N)
int widthOfBinaryTree(TreeNode* root){
    // if the root is null, the wodth is zero
    if(root == nullptr)
        return 0;

    // initialise a variable 'ans' to store the maximum width
    int ans = 0;
    // Create a queue to perform level order traversal
    // queue {Node, index(position in the level)} 
    queue<pair<TreeNode*, int> > q;
    q.push({root, 0});

    while(!q.empty()){
        // get the number of nodes at the current level
        int size = q.size();
        // get the position of the front node in the current level
        int mmin = q.front().second;
        // store the first and last positions of nodes in the current level
        int first = 0, last = 0;

        // process each node in the current level
        for(int i=0;i<size;i++){
            // calculate current position relative to the minimum position in the level
            int cur_ind = q.front().second - mmin;
            // get the current node
            TreeNode* node = q.front().first;
            q.pop();

            // if this is the first node in the level
            if(i == 0)
                first = cur_ind;
            // if this is the last node in the level
            if(i == size-1)
                last = cur_ind;

            if(node->left){
                q.push({node->left, cur_ind*2+1});
            }
            if(node->right){
                q.push({node->right, cur_ind*2+2});
            }
        }
        ans = max(ans, last-first+1);
    }
    return ans;
}


// Compute the binary tree's vertical order traversal given its root.
// The left and right children of a node at location (row, col) will be at 
// (row + 1, col - 1) and (row + 1, col + 1), respectively. The tree's root is 
// located at (0, 0).
// The vertical order traversal of a binary tree is a list of top-to-bottom 
// orderings for each column index starting from the leftmost column and ending 
// on the rightmost column. There may be multiple nodes in the same row and 
// same column. In such a case, sort these nodes by their values. Return the 
// binary tree's vertical order traversal.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// Time Complexity:O(N * log2N * log2N * log2N) : This complexity arises from 
// performing postorder traversal using BFS, where each node's insertion and 
// retrieval operations in nested maps take logarithmic time. Overall, it 
// reflects the combined cost of processing each node and managing the node 
// mappings.

// Space Complexity: O(N + N/2) : The space usage is dominated by the map 
// storing nodes by their vertical and level information, occupying O(N) space. 
// Additionally, the queue for BFS can occupy up to O(N/2) space in a balanced 
// tree's worst-case scenario, contributing to the total space complexity.
vector<vector<int> > verticalTraversal(TreeNode* root){
    // list to store the final result
    vector<vector<int> > result;

    if(root == nullptr)
        return result;

    // map to store the nodes at each vertical distance and level
    // map {vertical, level, node's data}
    map<int, map<int, priority_queue<int, vector<int>, greater<int> > > > nodesMap;
    // queue {Node, vertical, level}
    queue<pair<TreeNode*, pair<int, int> > > q;
    q.push({root, {0, 0}});

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int vertical = p.second.first;
        int level = p.second.second;

        nodesMap[vertical][level].push(node->data);

        // add the left child with updated vertical and level
        if(node->left){
            q.push({node->left, {vertical-1, level+1}});
        }
        if(node->right){
            q.push({node->right, {vertical+1, level+1}});
        }
    }

    // prepare the result by sorting keys and compiling nodes
    for(auto& p: nodesMap){
        vector<int> column;
        for(auto& q: p.second){
            while(!q.second.empty()){
                column.push_back(q.second.top());
                q.second.pop();
            }
        }
        result.push_back(column);
    }

    return result;
}
// Given the root of a binary tree, the value of a target node target, and an 
// integer k. Return an array of the values of all nodes that have a distance 
// k from the target node.
// The answer can be returned in any order (N represents null).
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// Time Complexity: Traversing the tree to create the parent hashmap requires 
// visiting each node once (O(N)), exploring all nodes at a distance of 'K' in 
// the worst case is O(N), and the logarithmic lookup time for the hashmap is 
// O(log N). Therefore, the overall time complexity simplifies to O(N).

// Space Complexity: The space complexity is determined by the data structures 
// used: O(N) for the parent hashmap, O(N) for the DFS queue, and O(N) for the 
// visited hashmap. Thus, the total space complexity is O(N).

vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
    // step 1: create a map to store the parent of each node
    unordered_map<TreeNode*, TreeNode*> parentMap;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        // if the left child exists, map its parent and push it into the queue
        if(node->left){
            parentMap[node->left] = node;
            q.push(node->left);
        }
        if(node->right){
            parentMap[node->right] = node;
            q.push(node->right);
        }
    }

    // step 2: BFS until the desired distance is reached
    vector<int> result;
    unordered_set<TreeNode*> visited;
    q.push(target);
    visited.insert(target);
    int currentDistance = 0;

    while(!q.empty()){
        if(currentDistance == k){
            // collect all nodes at distance k
            while(!q.empty()){
                result.push_back(q.front()->data);
                q.pop();
            }
            return result;
        }
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            q.pop();

            // check left child
            if(node->left && visited.find(node->left) == visited.end()){
                q.push(node->left);
                visited.insert(node->left);
            }
            // check right child
            if(node->right && visited.find(node->right) == visited.end()){
                q.push(node->right);
                visited.insert(node->right);
            }
            // check parent
            if(parentMap.find(node) != parentMap.end() && visited.find(parentMap[node]) == visited.end()){
                q.push(parentMap[node]);
                visited.insert(parentMap[node]);
            }
        }
        currentDistance++; 
    }
    return result;
}






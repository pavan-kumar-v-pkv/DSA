// Assuming standing on the right side of a binary tree and given its root, 
// return the values of the nodes visible, arranged from top to bottom.
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
vector<vector<int> > levelOrder(TreeNode* root){
    vector<vector<int> > ans;

    if(!root)   
        return ans;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->data);

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        ans.push_back(level);
    }
    return ans;
}
vector<int> rightSideView(TreeNode* root){
    vector<int> res;
    vector<vector<int> > levelTraversal = levelOrder(root);

    for(auto level: levelTraversal){
        res.push_back(level.back());
    }
    return res;
}
vector<int> leftSideView(TreeNode* root){
    vector<int> res;
    vector<vector<int> > levelTraversal = levelOrder(root);

    for(auto level : levelTraversal){
        res.push_back(level.front());
    }
    return res;
}

// recursive solution
// right view:
void solveRight(TreeNode* root, vector<int>& res, int level){
    if(root == nullptr)
        return;

    if(level == res.size()){
        res.push_back(root->data);
    }
    solveRight(root->right, res, level+1);
    solveRight(root->left, res, level+1);
}
vector<int> rightView(TreeNode* root){
    vector<int> res;
    int level = 0;
    solveRight(root, res, level);
    return res;
}
void solveLeft(TreeNode* root, vector<int>& res, int level){
    if(root == nullptr)
        return;

    if(level == res.size()){
        res.push_back(root->data);
    }
    solveLeft(root->left, res, level+1);
    solveLeft(root->right, res, level+1);
}
vector<int> leftView(TreeNode* root){
    vector<int> res;
    int level = 0;
    solveLeft(root, res, level);
    return res;
}
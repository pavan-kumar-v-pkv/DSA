// Given the root of a binary search tree and an integer k.Return true if 
// there exist two elements in the BST such that their sum is equal to k 
// otherwise false.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// brute force approach
class Solution {
    private:
        void inorder(TreeNode* root, vector<int>& sorted){
            if(!root)   
                return;
            
            inorder(root->left, sorted);
            sorted.push_back(root->data);
            inorder(root->right, sorted);
        }
    public:
    bool twoSumBST(TreeNode* root, int k){
        //get the sorted list of elements from BST
        vector<int> sorted;
        inorder(root, sorted);

        int left = 0, right = sorted.size()-1;

        // 2 pointers
        while(left < right){
            int current_sum = sorted[left] + sorted[right];
            if(current_sum == k)
                return true;
            else if(current_sum < k)
                left++;
            else
                right--;
        }
        return false;
    }
};

// optimal approach
class BSTIterator{
    stack<TreeNode*> st;
    bool reverse; // false = inorder, true = reverse inorder (R Root L)

    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            if(!reverse) node = node->left;
            else node = node->right;
        }
    }
    public:
    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext() { 
        return !st.empty();
    }

    bool next(){
        TreeNode* node = st.top();
        st.pop();
        if(!reverse) pushAll(node->right); // normal in-order
        else pushAll(node->left); // reverse inorder

        return node->data;
    }
};

bool findTarget(TreeNode* root, int k){
    if(!root) return false;

    BSTIterator l(root, false); //smallest first
    BSTIterator r(root, true); //largest first

    int i = l.next();
    int j = r.next();

    while(i < j){
        if(i + j == k) return true;
        else if(i + j < k) i = l.next();
        else j = r.next();
    }
    return false;
}
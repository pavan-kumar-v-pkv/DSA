// Implement the BSTIterator class that represents an iterator over the 
// in-order traversal of a binary search tree (BST):

// BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. 
// The root of the BST is given as part of the constructor. The pointer should 
// be initialized to a non-existent number smaller than any element in the BST.
// boolean hasNext() Returns true if there exists a number in the traversal to 
// the right of the pointer, otherwise returns false.
// int next() Moves the pointer to the right, then returns the number at the 
// pointer.
// Notice that by initializing the pointer to a non-existent smallest number, 
// the first call to the next() will return the smallest element in the BST.

// Assume that the next() calls will always be valid. That is, there will be at 
// least a next number in the in-order traversal when the next() is called.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// brute force approach
// time: O(N)
// space: O(N)
class BSTIterator{
    private:
    vector<int> values;
    int index;

    void inorder(TreeNode* node){
        if(node == nullptr)
            return;

        inorder(node->left);
        values.push_back(node->data);
        inorder(node->right);
    }
    public:
    // Constructor to initialise the iterator
    BSTIterator(TreeNode* root){
        // perform the inorder traveral and store values
        inorder(root);
        index = -1;
    }

    // check if there are more elements in the BST
    bool hasNext(){
        // true if there are more elements
        return index + 1 < values.size(); 
    }

    // return the next element in the BST
    int next(){
        // increment index and return the next value
        return values[++index];
    }
};

// optimal approach
class BSTIterator2{
    private:
    stack<TreeNode*> st;

    void pushAll(TreeNode* root){
        while(root != nullptr){
            st.push(root->left);
            root = root->left;
        }
    }
    public:
    BSTIterator2(TreeNode* root){
        pushAll(root);
    }

    bool hasNext(){
        return !st.empty();
    }

    int next(){
        TreeNode* node = st.top();
        st.pop();
        pushAll(node->right);
        return node->data;
    }
};
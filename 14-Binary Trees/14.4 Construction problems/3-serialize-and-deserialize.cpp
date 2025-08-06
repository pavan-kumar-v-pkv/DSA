// Serialization is converting a data structure or object into a sequence of 
// bits so that it can be stored in a file or memory buffer, or transmitted 
// across a network connection link to be reconstructed later in the same or 
// another computer environment.
// Design an algorithm to serialize and deserialize a binary tree. There is no 
// restriction on how your serialization/deserialization algorithm should work. 
// Ensure that a binary tree can be serialized to a string, and this string can 
// be deserialized to the original tree structure.
// The encoded string should be as compact as possible.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// Time Complexity: O(N) Both serialize and deserialize functions have a time 
// complexity of O(N), where N is the number of nodes in the tree. This is 
// because each function processes every node once.

// Space Complexity: O(N) Both serialize and deserialize functions have a space 
// complexity of O(N). This space is used by the queue to hold nodes at various 
// levels of the tree during traversal and reconstruction.

string serialize(TreeNode* root){
    if(root == nullptr)
        return "";

    // initialize an empty string to store the serialized data
    stringstream ss;
    // use a queue for level-order traversal
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        // get the front node in the queue
        TreeNode* node = q.front();
        q.pop();

        // check if the current node is null and append "#" to the string
        if(node == nullptr){
            ss << "#,";
        }
        else{
            ss << node->data << ",";
            q.push(node->left);
            q.push(node->right);
        }
    }
    return ss.str();
}

TreeNode* deserialize(string data){
    if(data.empty())
        return nullptr;

    // use a stringstream to tokenize the serialized data
    stringstream s(data);
    string str;
    getline(s, str, ',');
    // read the root value from the serialized data
    TreeNode* root = new TreeNode(stoi(str));

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();

        getline(s, str, ',');
        if(str != "#"){
            TreeNode* leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');
        if(str != "#"){
            TreeNode* rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}

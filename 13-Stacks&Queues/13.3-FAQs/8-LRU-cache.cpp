// Design a data structure that follows the constraints of Least Recently Used 
// (LRU) cache.
// Implement the LRUCache class:
// LRUCache(int capacity): We need to initialize the LRU cache with positive 
// size capacity.
// int get(int key): Returns the value of the key if the key exists, otherwise 
// return -1.
// void put(int key,int value): Update the value of the key if the key exists. 
// Otherwise, add the key-value pair to the cache. If the number of keys 
// exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.
#include<bits/stdc++.h>
using namespace std;

// time: O(N), where N is the number of queries
// Since Put and Get method takes an average of constant time, the overall complexity to process all the queries is O(N) time.
// space: O(cap) where cap is the capacity of LRU cache

// Class to implement Nodes of a doubly linked list
class Node{
public:
    int key, val;
    Node* next;
    Node* prev;

    Node(){
        key = val = -1;
        next = prev = nullptr;
    }

    Node(int k, int value){
        key = k;
        val = value;
        next = prev = nullptr;
    }
};

// class implementing LRU cache
class LRUCache{
private:
    map<int, Node*> mpp; // map <key, Node* value>
    int cap; // capacity
    Node* head; // dummy head pointer
    Node* tail; // dummy tail pointer

    // method to delete node from DLL
    void deleteNode(Node* node){
        // get the previous and next nodes of node to be deleted
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        // remove the pointers to node 
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // method to insert node after head
    void insertAfterHead(Node* node){
        Node* nextNode = head->next;
        head->next = node;
        node->next = nextNode;
        node->prev = head;
        nextNode->prev = node;
    }
public:
    // constructor
    LRUCache(int capacity){
        cap = capacity;
        mpp.clear();

        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->next = head;
    }

    // method to get the kwy from cache
    int get(int key_){
        // return -1 if it is not present in the cache
        if(mpp.find(key_) == mpp.end())
            return -1;

        Node* node = mpp[key_]; // get the value node for that key_ from map
        int val = node->val; // get the value

        // delete the node
        deleteNode(node);
        // insert this node to front as it was recently used
        insertAfterHead(node);

        return val;
    }

    // method to update value if key exists, otherwise insert the key-value pair
    void put(int key_, int value){
        // update the value if key is already present
        if(mpp.find(key_) != mpp.end()){
            Node* node = mpp[key_]; // get the node
            node->val = value; // get the value
            // delete the node
            deleteNode(node);
            // insert this node to front as it was recently used
            insertAfterHead(node);
            return;
        }

        // check if the capacity limit is has reached
        if(mpp.size() == cap){
            // get the least recently used (LRU) node
            Node* node = tail->prev;
            // delete node from map
            mpp.erase(node->key);
            // delete node from DLL
            deleteNode(node);
        }
        // create a new node
        Node* newNode = new Node(key_, value);
        // insert it in map
        mpp[key_] = newNode;
        // insert in DLL
        insertAfterHead(newNode);
    }

};


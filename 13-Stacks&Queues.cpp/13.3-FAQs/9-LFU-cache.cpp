// Design and implement a data structure for a Least Frequently Used (LFU) 
// cache.
// Implement the LFUCache class with the following functions:
// LFUCache(int capacity): Initialize the object with the specified capacity.
// int get(int key): Retrieve the value of the key if it exists in the cache; 
// otherwise, return -1.
// void put(int key, int value): Update the value of the key if it is present 
// in the cache, or insert the key if it is not already present. If the cache 
// has reached its capacity, invalidate and remove the least frequently used 
// key before inserting a new item. In case of a tie (i.e., two or more keys 
// with the same frequency), invalidate the least recently used key.
// A use counter is maintained for each key in the cache to determine the least 
// frequently used key. The key with the smallest use counter is considered the 
// least frequently used.
// When a key is first inserted into the cache, its use counter is set to 1 due 
// to the put operation. The use counter for a key in the cache is incremented 
// whenever a get or put operation is called on it.
// Ensure that the functions get and put run in O(1) average time complexity.
#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N) (where N is the number of queries on the LFU cache)
// Each get and put method takes an average of constant time making the overall complexity as O(N).

// Space Complexity: O(cap) (where cap is the capacity of LFU cache defined)
// At maximum the cache can store the numbers of data-items equal to its capacity taking O(cap) space.

struct Node{
    int key, value, cnt;
    Node* next;
    Node* prev;
    Node(int _key, int _value){
        key = _key;
        value = _value;
        cnt = 1;
    }
};

struct List {
    int size; // size
    Node* head; // dummy head
    Node* tail; // dummy tail

    // Constructor
    List(){
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    // Function to add node in front
    void addFront(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->next = temp;
        node->prev = head;
        temp->prev = node;
        size++;
    }

    // Function to remove node from the list
    void removeNode(Node* delnode){
        Node* prevNode = delnode->prev;
        Node* nextNode = delnode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
};

// class to implement LFU cache
class LFUCache{
private:
    // hashmap to store key-node pairs
    map<int, Node*> keyNode;
    // hasmap to maintain the list having different frequencies
    map<int, List*> freqListMap;

    int maxSizeCache; // max size of cache
    // to store the frequency of least frequently used data-item
    int minFreq;
    // to store current size of cache
    int curSize;

public:
    // Constructor
    LFUCache(int capacity){
        // set the capacity
        maxSizeCache = capacity;
        minFreq = 0; // set minimum frequency
        curSize = 0; // set current frequency
    }

    // method to update frequency of data-items
    void updateFreqListMap(Node* node){
        // remove from Hashmap
        keyNode.erase(node->key);
        // update the frequency list hashmap
        freqListMap[node->cnt]->removeNode(node);

        // if node which was removed was the last node in that list having it's frequency
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0){
            // update the minimum frequency
            minFreq++;
        }

        // creating a dummy list for next higher frequency
        List* nextHigherFreqList = new List();
        // if the next higher frequency list already exusts
        if(freqListMap.find(node->cnt+1) != freqListMap.end()){
            // update pointer to already existing list
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }
        // increment the counut of data-item
        node->cnt += 1;
        // add the node in front of highrt frequency list
        nextHigherFreqList->addFront(node);
        // update the map
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    // method to get the value of key from LFU cache
    int get(int key){
        // return the value if it exists
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key]; // get the node
            int val = node->value; // get the value
            updateFreqListMap(node); // update the frequency

            // return the value
            return val;
        }

        return -1; // if key is not found
    }

    void put(int key, int value){
        // if the ssize of cache is 0, no data-items can be inserted
        if(maxSizeCache == 0){
            return;
        }

        // if key already exists
        if(keyNode.find(key) != keyNode.end()){
            // get the node
            Node* node = keyNode[key];
            // update the value
            node->value = value;
            // update the frequency
            updateFreqListMap(node);
        }
        // else if the key does not exist
        else{
            // if cache limit is reached
            if(curSize == maxSizeCache){
                // remove the least frequently used data-item
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);

                // update the frequenct map
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--; // decrease the current size of cache
            }
            // increment the current cache size
            curSize++;
            // adding new value of the cache
            minFreq = 1; // set its frequency to 1
            // create a dummy list
            List* listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()){
                // update the pointer to already present list
                listFreq = freqListMap[minFreq];
            }
            // create the node to store data-item
            Node* node = new Node(key, value);
            // add the node to dummy list
            listFreq->addFront(node);
            // add the node to HashMap
            keyNode[key] = node;
            // update the frequency list map
            freqListMap[minFreq] = listFreq;
        }
    }
};
// Given the head of a singly linked list. Return true if a loop exists in the 
// linked list or return false.
// A loop exists in a linked list if some node in the list can be reached again 
// by continuously following the next pointer.
// Internally, pos is used to denote the index(0-based) of the node from where 
// the loop starts. Note that pos is not passed as a parameter.
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int data1, Node* next1){
        val = data1;
        next = next1;
    }
    Node(int data1){
        val = data1;
        next = nullptr;
    }
};

// brute force approach
// time: O(N*2*log(N)), N is for traversal and 2*log(N) is for insertion and searching in the set
// space: O(N), where N is the number of nodes in the linked list.
bool hasCycle(Node* head){
    // initialize an empty set to store visited nodes
    unordered_set<Node*> visited;
    Node* curr = head;
    // traverse the linked list
    while(curr != nullptr){
        // if the current node is already in the set, it means we have a cycle
        if(visited.find(curr) != visited.end()){
            return true;
        }
        curr = curr->next; // move to the next node
        visited.insert(curr); // insert the current node into the set
    }

    return false; // if we reach the end of the linked list, there is no cycle
}

// optimized approach using Floyd's Cycle Detection Algorithm (Tortoise and Hare)
// time: O(N), where N is the number of nodes in the linked list
// space: O(1), no extra space is used.
bool hasCycleOptimized(Node* head){
    if(!head || !head->next){
        return false; // if the linked list is empty or has only one node, there is no cycle
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false; // if fast pointer reaches the end, there is no cycle
}


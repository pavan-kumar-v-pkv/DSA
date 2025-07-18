// Given the head of a singly linked list, the task is to find the starting 
// point of a loop in the linked list if it exists. Return the starting node if 
// a loop exists; otherwise, return null.
// A loop exists in a linked list if some node in the list can be reached again 
// by continuously following the next pointer. Internally, pos denotes the 
// index (0-based) of the node from where the loop starts.
// Note that pos is not passed as a parameter.
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;       
    Node* next;
    Node(int data1, Node* next1) {  
        data = data1;   
        next = next1;
    }
    Node(int data1) {   
        data = data1;
        next = nullptr;
    }
};

// brute force approach
// time: O(N), where N is the number of nodes in the linked list
// space: O(N), where N is the number of nodes in the linked list
Node* findStartingPointInLoop(Node* head){
    Node* curr = head;
    unordered_set<Node*> visited;

    while(curr != nullptr){
        // if the current node is already in the set, it means we have found the starting point of the loop
        if(visited.find(curr) != visited.end()){
            return curr; // return the starting point of the loop
        }
        visited.insert(curr);
        curr = curr->next;
    }
    return nullptr; // if we reach the end of the linked list, there is no loop
}

// optimized approach using Floyd's Cycle Detection Algorithm (Tortoise and Hare)
// time: O(N), where N is the number of nodes in the linked list
// space: O(1), no extra space is used
Node* findStartingPointInLoopOptimized(Node* head){
    Node* slow = head;
    Node* fast = head;

    // first check if a loop exists
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            // if a loop exists, find the starting point of the loop
            slow = head; // reset slow pointer to the head
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
                // when slow and fast meet again, it's the first node of the loop
            }
            return slow; // return the starting point of the loop
        }
    }
    return nullptr; // if no loop exists, return nullptr
}
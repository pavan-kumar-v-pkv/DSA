// // Given the head of a singly linked list, find the length of the loop in 
// the linked list if it exists. Return the length of the loop if it exists; 
// otherwise, return 0.
// // A loop exists in a linked list if some node in the list can be reached 
// again by continuously following the next pointer. Internally, pos is used to
// denote the index (0-based) of the node from where the loop starts.
// // Note that pos is not passed as a parameter.

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
int findLengthOfLoop(Node* head){
    unordered_map<Node*, int> visitedNodes;
    Node* curr = head;
    int timer = 0; // initialize pointer to traverse the linked list

    while(curr != nullptr){
        if(visitedNodes.find(curr) != visitedNodes.end()){
            int loopLength = timer - visitedNodes[curr];
            return loopLength; // if the current node is already in the map, return the length
        }
        visitedNodes[curr] = timer; // store the current node with its timer value
        curr = curr->next; // move to the next node
        timer++; // increment the timer
    }   
    return 0; // if we reach the end of the linked list, there is no loop
}

// optimized approach using Floyd's Cycle Detection Algorithm (Tortoise and Hare)
// time: O(N), where N is the number of nodes in the linked list
// space: O(1), no extra space is used
int findLength(Node* slow, Node* fast){
    int cnt = 1; // initialize count to 1 as slow and fast are at the same node
    fast = fast->next; // move fast pointer one step ahead
    // traverse fast till it reaches back to slow
    while(slow != fast){
        cnt++;
        fast = fast->next; // move fast pointer one step ahead
    }
    return cnt; // return the count of nodes in the loop
}
int findLengthOfLoopOptimized(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return findLength(slow, fast);
        }
    }
    return 0; // if no loop is found, return 0
}
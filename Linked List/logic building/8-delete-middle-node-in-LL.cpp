// Given the head of a non-empty singly linked list containing integers, delete
// the middle node of the linked list. Return the head of the modified linked 
// list.
// The middle node of a linked list of size n is the (⌊n / 2⌋ + 1)th node from 
// the start using 1-based indexing, where ⌊x⌋ denotes the largest integer less 
// than or equal to x.
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
// time: O(n + n/2) = O(n), where n is the number of nodes in the linked list.
// space: O(1), no extra space is used.
Node* deleteMiddle(Node* head){
    // edge case: if the linked list has only one node, return nullptr
    if(head == nullptr || head->next == nullptr){
        delete head; // free the memory of the single node
        return nullptr; // return nullptr as the new head
    }

    // temp node to traverse
    Node* temp = head;
    int cnt = 0;
    // count the number of nodes in the linked list
    while(temp != nullptr){
        cnt++;
        temp = temp->next;
    }
    int midPos = cnt /2;
    temp = head;
    for(int i=0;i<midPos;i++){
        Node* middle = temp->next; // create pointer to the middle node
        // adjust pointers to skip middle node
        temp->next = temp->next->next;
        delete middle; // free the memory of the middle node
    }
    return head; // return the modified head of the linked list
}

// optimized approach using two pointers
// time: O(n/2)
// space: O(1), no extra space is used.
Node* deleteMiddleOptimized(Node* head){
    // edge case: if the linked list has only one node, return nullptr
    if(head == nullptr || head->next == nullptr){
        delete head;    
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;
    fast = head->next->next; // move fast pointer two steps ahead

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = slow->next->next;
    return head;
}
// Given the head of a singly linked list and an integer n. Remove the nth node from the
// back of the linked List and return the head of the modified list. The value of n will
// always be less than or equal to the number of nodes in the linked list.
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
//time: O(l) + (l-n), where l is the length of the linked list and n is the position of the node to be removed from the back.
//space: O(1), no extra space is used.
Node* removeNthFromEnd(Node* head, int n){
    if(head == nullptr)
        return nullptr;

    int cnt = 0;
    Node* temp = head;

    // cont the number of nodes in the linked list
    while(temp != nullptr){
        cnt++;
        temp = temp->next;
    }
    // if n is equal to the number of nodes, then remove the head node
    if(cnt == n){
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    int res = cnt - n;
    temp = head;
    // traverse the linked list to the node just before the node to be removed
    while(temp != nullptr){
        res--;
        if(res == 0){
            break;
        }
        temp = temp->next;
    }
    // delete the nth node from the end
    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
    return head;
}

// optimized approach:
// Technique: Two Pointers (Fast & Slow)
// 🔍 Steps:
// Initialize Two Pointers:
//      Set fast and slow to the head of the list.
// Advance Fast Pointer:
//      Move fast N steps ahead of slow.
// Traverse Together:
//      Move both fast and slow one step at a time until fast reaches the end.
//      Now, slow is just before the node to be removed.
// Remove Node:
//      Update slow->next to skip the target node.
//      Free memory (if using C/C++).
// time: O(l), where l is the length of the linked list.
// space: O(1), no extra space is used.
Node* removeNthFromEnd2(Node* head, int n) {
    // creating pointers
    Node* fast = head;
    Node* slow = head;
    // move fast pointer n steps ahead
    for(int i=0;i<n;i++){
        fast = fast->next;
    }
    // if fast pointer is null, it means we need to remove the head node
    // that means, Nth node to be deleted from end in head
    if(fast == nullptr){
        return head->next;
    }
    // move both pointers until fast reches the end
    while(fast->next != nullptr){
        fast=fast->next;
        slow=slow->next;
    }
    // delete the nth node from the end
    Node* delNode = slow->next;
    slow->next = delNode->next;
    delete delNode;
    return head;
}
// Given the head of a singly linked list. Reverse the given linked list and return the 
// head of the modified list.
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

// iterative approach
// time: O(n), where n is the number of nodes in the linked list.
// space: O(1), no extra space is used.
Node* reverseList(Node* head){
    Node* temp = head;
    Node* prevN = nullptr;
    Node* nextN = nullptr;
    while(temp != nullptr){
        nextN = temp->next; // store the next node
        temp->next = prevN; //reverse the link
        prevN = temp; // move prevN to the current node
        temp = nextN; // move temp to the next node
    }
    return prevN; // prevN will be the new head of the reversed linked list
}

// recursive approach
// time: O(n), where n is the number of nodes in the linked list.
// space: O(n), due to the recursive stack space.
Node* reverseListRec(Node* head){
    // base case: if the linked list is empty or has only one node, 
    // return the head as it is already reversed.
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    // recursive step:
    // reverse the linked list starting from the second node (head->next)
    Node* newHead = reverseListRec(head->next);
    // save a reference to the node following the current 'head'node.
    Node* front = head->next;
    // make the 'front' node point to the current 'head' node in the reversed order
    front->next = head;
    // break the link from the current 'head' node to the next node
    head->next = nullptr;
    // return the new head of the reversed linked list
    return newHead;
}
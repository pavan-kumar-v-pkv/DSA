// Given the head of a singly linked list representing a positive integer number. Each 
// node of the linked list represents a digit of the number, with the 1st node 
// containing the leftmost digit of the number and so on. The task is to add one to the 
// value represented by the linked list and return the head of a linked list containing 
// the final value.
// The number will contain no leading zeroes except when the value represented is zero 
// itself.

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

// time: O(n), where n is the number of nodes in the linked list.
// space: O(1), no extra space is used.
Node* reverseList(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* addOne(Node* head){
    // reverse the linked list to make addition easier
    head = reverseList(head);
    // create a dummy node
    Node* curr = head;
    int carry = 1; // start with carry of 1 to add one to the number
    while(curr != nullptr){
        int sum = curr->data + carry;
        carry = sum/10;
        curr->data = sum%10;

        if(carry == 0){
            break; // if no carry, we can stop
        }

        // if we've reached the end of the list there's still a carry, 
        // add a new node with carry values
        if(curr->next ==nullptr && carry != 0){
            curr->next = new Node(carry);
            break; // exit the loop after adding the new node
        }
        curr = curr->next; // move to the next node
    }

    head = reverseList(head); // reverse the list back to original order
    return head; // return the modified head of the linked list
}



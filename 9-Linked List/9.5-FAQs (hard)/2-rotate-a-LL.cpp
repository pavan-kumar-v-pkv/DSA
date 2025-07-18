// Given the head of a singly linked list containing integers, shift the 
// elements of the linked list to the right by k places and return the head of 
// the modified list. Do not change the values of the nodes, only change the 
// links between nodes.
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
    Node(int val, Node* nextNode) : data(val), next(nextNode) {}
};

// brute force approach
// time: O(N*k) where N is the number of nodes in the list and k is the number of places to shift
// space: O(1) as we are not using any extra space except for pointers
Node* rotateRight(Node* head, int k){
    if(head == nullptr || head->next == nullptr)
        return head; // if the list is empty or has only one node, return it

    // perform rotation k times
    for(int i=0;i<k;i++){
        Node* temp = head;
        // find the second last node
        while(temp->next->next != nullptr)
            temp = temp->next;
        // get the last node
        Node* end = temp->next;
        // break the link between second last and last node
        temp->next = nullptr;
        // make the last node point to the head
        end->next = head;
        head = end;
    }
    return head;
    
}

// optimal approach
// time: O(N) + O(N - (N%k)) where N is the number of nodes in the list
// space: O(1) as we are not using any extra space except for pointers
Node* rotateRightOptimal(Node* head, int k){
    if(head == nullptr || head->next == nullptr)
        return nullptr; // if the list is empty or has only one node, return it

    // calculating length
    Node* temp = head;
    int length = 1; // start with 1 as we are already at the head
    while(temp->next != nullptr){
        ++length;
        temp = temp->next;
    }

    // link the last node to the first node
    temp->next = head;
    // when k is more than length of list
    k = k % length;
    // to get the end of list
    int end = length - k;
    while(end > 0){
        temp = temp->next; // move to the next node
        end--; // decrement end
    }
    // breaking last node link and pointing to NULL
    head = temp->next;
    temp->next = nullptr;

    return head; // return the new head of the rotated list
}

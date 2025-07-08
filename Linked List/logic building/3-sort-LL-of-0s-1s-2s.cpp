// Given the head of a singly linked list consisting of only 0, 1 or 2. Sort 
// the given linked list and return the head of the modified list. Do it 
// in-place by changing the links between the nodes without creating new nodes.
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
// time: O(2n), where n is the number of nodes in the linked list.
// space: O(1), no extra space is used.
Node* sortList(Node* head){
    int c0 = 0, c1 = 0, c2 = 0;
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == 0)c0++;
        else if(temp->data == 1)c1++;
        else if(temp->data == 2)c2++;
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        if(c0 > 0){
            temp->data = 0;
            c0--;
        }
        else if(c1 > 0){
            temp->data = 1;
            c1--;            
        }
        else if(c2 > 0){
            temp->data = 2;
            c2--;
        }
        temp = temp->next;
    }
    return head;
}

// optimized approach
// time: O(n), where n is the number of nodes in the linked list.
// space: O(1), no extra space is used.
Node* sortList2(Node* head){
    if(head == nullptr || head->next == nullptr)
        return head;
    
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;
    Node* temp = head;

    while(temp != nullptr){
        if(temp->data == 0){
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = temp;
        }
        else if(temp->data == 2){
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }

    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;

    Node* newHead = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return newHead;
}
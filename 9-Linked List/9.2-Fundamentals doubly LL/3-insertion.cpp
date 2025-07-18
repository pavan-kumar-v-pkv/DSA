#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* back;
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// function to insert new node before head
Node* insertBeforeHead(Node* head, int val){
    Node* newNode = new Node(val, head, nullptr);
    head->back = newNode; // set the back pointer of the old head
    return newNode; // return the new head  
}

// insert new node before tail
Node* insertBeforeTail(Node* head, int val){
    if(head == nullptr){
        return new Node(val);
    }
    if(head->next == nullptr){
        return insertBeforeHead(head, val);
    }

    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    Node* prev = tail->back;
    prev->next = new Node(val, tail, prev);
    tail->back = prev->next; // update the back pointer of the tail
    return head; // return the head of the list
}

// function to insert new node before k-th position
Node* insertBeforeKthPosition(Node* head, int k, int val){
    if(k == 1){
        return insertBeforeHead(head, val);
    }

    Node* temp = head;
    int cnt = 1;
    while(temp != nullptr){
        cnt++;
        if(cnt == k)
            break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);

    prev->next = newNode; // link the previous node to the new node
    if(temp != nullptr) {
        temp->back = newNode; // link the new node back to the current node 
    }

    return head; // return the head of the list
}

// function to insert a new node before a given node
void insertBeforeNode(Node* node, int val){
    Node*prev = node->back;
    Node* newNode = new Node(val, node, prev);
    if(prev != nullptr) {
        prev->next = newNode; // link the previous node to the new node
    }
    node->back = newNode; // link the new node back to the current node
    return;
}
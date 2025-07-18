#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = NULL;
    }
    
};

// function to insert a new node at the head of the linked list
Node* insertAtHead(Node* head, int data) {
    Node* newNode = new Node(data, head);
    return newNode;
}

// function to insert a new node at the tail of the linked list
Node* insertAtTail(Node* head, int data) {
    if(head == nullptr)
        return new Node(data);
        
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    Node* newNode = new Node(data);
    temp->next = newNode;

    return head;
}

// function to insert a new node at the k-th position in the linked list
Node* insertAtKthPosition(Node* head, int data, int k) {
    if(head == nullptr){
        if(k == 1) {
            return new Node(data);
        } else {
            cout << "Invalid position!" << endl;
            return head;
        }
    }

    // if k is 1, insert at the head
    if(k == 1){
        return new Node(data, head);
    }

    int cnt = 0;
    Node* temp = head;

    while(temp != nullptr){
        cnt++;
        if(cnt == k-1){
            Node* newNode = new Node(data, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// insertion a new node with data 'el after the node with data 'val
Node* insertAtK(Node* head, int el, int val){
    if(head == nullptr){
        return nullptr;
    }

    // insert the beginning if th value matches the head's data
    if(head->data == val){
        return new Node(el, head);
    }

    Node* temp = head;
    while(temp->next != nullptr){
        // insert at the current position if the next node has the desired value
        if(temp->next->data == val){
            Node* newNode = new Node(el, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

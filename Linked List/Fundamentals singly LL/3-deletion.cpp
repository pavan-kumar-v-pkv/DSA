#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};

Node* deleteHead(Node* head){
    // check if the list is empty
    if(head == nullptr)
        return nullptr;

    // store the current heda in a temporary variable
    Node* temp = head;
    // move the head to the next node
    head = head->next;
    // delete the old head node
    delete temp;
    // return the new head
    return head;
}

Node* deleteTail(Node* head){
    // if the list is empty, return nullptr
    if(head == nullptr){
        return nullptr;
    }

    // if the list has only one node, delete it and return nullptr
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }
    // find the second last node
    Node* second_last = head;
    while(second_last->next->next != nullptr){
        second_last = second_last->next;
    }
    // delete the last node
    delete second_last->next;
    // set the next of the second last node to nullptr
    second_last->next = nullptr;
    // return the head
    return head;
}

// function to delete the k-th node in a linked list
Node* deleteKthNode(Node* head, int k){
    // check if the list is empty
    if(head == NULL){
        return head;
    }

    // if k is 1, delete the head node
    if(k == 1){
        Node* temp = head;
        head= head->next;
        delete temp;
        return head;
    }

    // traverse the list to find the k-th node
    Node* current = head;
    Node* prev = nullptr;
    int cnt = 0;
    while(current != nullptr){
        cnt++;
        // if the k-th node is found
        if(cnt == k){
            // adjust the pointers to skip the k-th node
            prev->next = current->next;
            // delete the k-th node
            delete current;
            break;
        }
        // move to the next node
        prev = current;
        current = current->next;
    }
    return head;
}

// function to delete a node with a specific value ina linked list
Node* deleteNodeWithValue(Node* head, int value){
    // check if the list is empty
    if(head == nullptr){
        return nullptr;
    }

    // if the first node has the target value, delete it
    if(head->data == value){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    // traverse the list to find the node with the target value
    Node* current = head;
    Node* prev = nullptr;
    while(current != nullptr){
        if(current->data == value){
            // adjust the pointers to skip the node with the target value
            prev->next = current->next;
            // delete the node
            delete current;
            break; // return the head of the modified list
        }
        prev = current;
        current = current->next;
    }
    return head;
}
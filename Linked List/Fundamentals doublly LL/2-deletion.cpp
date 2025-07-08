#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }
    Node(int data1) {
        data = data1;
        next = NULL;
        prev = NULL;
    }
};

// function to delete the head node of a doubly linked list
Node* deleteHead(Node* head){
    if(head == nullptr || head->next == nullptr){
        // return nullptr uf the list is empty or has only one node
        return nullptr;
    }
    Node* prev = head;
    head = head->next;
    head->prev = nullptr;
    prev->next = nullptr; // disconnect the old head
    delete prev; // delete the old head
    return head; // return the new head
}

// function to delete the tail node of a doubly linked list
Node* deleteTail(Node* head){
    if(head == nullptr || head->next == nullptr){
        return nullptr; // return nullptr if the list is empty or has only one node
    }

    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next; // find the last node
    }

    tail->prev->next = nullptr; // disconnect the tail node
    Node* prev = tail->prev; // store the previous node
    delete tail; // delete the tail node

    return head; // return the head of the list
}

// function to delete the k-th element in a doubly linked list
Node* removeKthElement(Node* head, int k){
    if(head == nullptr){
        return nullptr; // return nullptr if the list is empty
    }

    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr){
        cnt++;
        if(cnt == k){
            if(temp->prev != nullptr){
                temp->prev->next = temp->next;
            }else{
                head = temp->next; // if k is 1, update the head
            }
            if(temp->next != nullptr){
                temp->next->prev = temp->prev;
            }
            delete temp; // delete the k-th node
            return head; // return the head of the list
        }
        temp = temp->next; // move to the next node
    }
    cout << "Invalid position!" << endl; // if k is out of bounds
    return head; // return the head of the list
}

// function to delete the entire doubly linked list
void deleteDLL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        Node* nextNode = temp->next; // store the next node
        delete temp; // delete the current node
        temp = nextNode; // move to the next node
    }
}       

// function to remove the given node from the doubly linked list
void deleteNode(Node* temp){
    Node* prevN = temp->prev;
    Node* front = temp->next;

    // if the front node is tail node
    if(front == nullptr){
        prevN->next = nullptr; // disconnect the tail node
        temp->prev = nullptr; // disconnect the tail node
        delete temp; // delete the tail node
        return;
    }

    // disconnect the current node from the list
    prevN->next = front; // link the previous node to the front node
    front->prev = prevN; // link the front node back to the previous node

    temp->next = nullptr; // disconnect the current node
    temp->prev = nullptr; // disconnect the current node
    delete temp; // delete the current node
    return;
}
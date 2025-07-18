#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int data, Node* next1, Node* prev1){
        this->data = data;
        this->next = next1;
        this->prev = prev1;
    }
    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

Node* convertArr2DLL(vector<int> arr){
    // create the head node with the first element
    Node* head = new Node(arr[0]);
    Node* prev = head;
    // iterate through the array and create nodes
    for(int i=0;i<arr.size();i++){
        Node* newNode = new Node(arr[i]);
        prev->next = newNode; // link the previous node to the new node
        newNode->prev = prev; // link the new node back to the previous node
        prev = newNode; // move the prev pointer to the new node
    }
    return head;
}

void printDLL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}
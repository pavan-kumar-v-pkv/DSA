// Given the head of a singly linked list. Group all the nodes with odd indices 
// followed by all the nodes with even indices and return the reordered list.
// Consider the 1st node to have index 1 and so on. The relative order of the 
// elements inside the odd and even group must remain the same as the given 
// input.
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
        next = nullptr;
    }
};

// brute force approach
// time: O(2*n), where n is the number of nodes in the linked list.
// space: O(n), for the new linked list that is created.
Node* oddvenList(Node* head){
    if(head == nullptr || head->next == nullptr)
        return head;
        
    vector<int> array;
    Node* temp = head;

    while(temp != nullptr && temp->next != nullptr){
        array.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp!=nullptr){
        array.push_back(temp->data);
    }
    temp = head->next;
    while(temp != nullptr && temp->next != nullptr){
        array.push_back(temp->data);
        temp = temp->next->next;
    }

    if(temp != nullptr){
        array.push_back(temp->data);    
    }

    temp = head;
    int i = 0;
    while(temp != nullptr){
        temp->data = array[i];
        i++;
        temp = temp->next;
    }
    return head;
}

// optimized approach
// time: O(n), where n is the number of nodes in the linked list.
// space: O(1), no extra space is used.
Node* oddEvenList2(Node* head){
    if(!head || !head->next){
        return head;
    }

    Node* odd = head;
    Node* even = head->next;
    Node* firstEven = head->next;

    while(even && even->next){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = firstEven; // link the last odd node to the first even node
    return head; // return the head of the modified linked list
}
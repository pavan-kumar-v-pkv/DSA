// Given the head of a doubly linked list with its values sorted in 
// non-decreasing order. Remove all duplicate occurrences of any value in the 
// list so that only distinct values are present in the list.
// Return the head of the modified linked list.
#include <bits/stdc++.h>
using namespace std;    

class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
    Node(int val, Node* nextNode, Node* prevNode) 
        : data(val), next(nextNode), prev(prevNode) {}  
};

// time: O(N)
// space: O(1)
Node* removeDuplicates(Node* head){
    Node* temp = head;

    while(temp != nullptr && temp->next != nullptr){
        Node* nextNode = temp->next;
        while(nextNode != nullptr && nextNode->data == temp->data){
            // store the duplicate node
            Node* duplicate = nextNode;
            nextNode = nextNode->next;
            delete duplicate;
        }
        // update the next pointer of the current node
        temp->next = nextNode;
        if(nextNode != nullptr){
            nextNode->prev = temp;
        }
        temp = temp->next;
    }
    return head;

}
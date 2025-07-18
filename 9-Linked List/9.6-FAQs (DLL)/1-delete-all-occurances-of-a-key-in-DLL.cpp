// Given the head of a doubly linked list and an integer target. Delete all 
// nodes in the linked list with the value target and return the head of the 
// modified linked list.
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
Node* deleteAllOccurrences(Node* head, int target){
    Node* temp = head;

    while(temp != nullptr){
        if(temp->data == target){
            // update head if the target node is at the beginning
            if(temp == head){
                head = head->next;
            }
            Node* prevNode = temp->prev;
            Node* nextNode = temp->next;
            // update next node's prev pointer if it exists
            if(nextNode != nullptr){
                nextNode->prev = prevNode;
            }
            // update prev node's next pointer if it exists
            if(prevNode != nullptr){
                prevNode->next = nextNode;
            }
    
            delete temp;
            temp = nextNode; // move to the next node
        }
        else{
            temp = temp->next;
        }
    }

    return head;
}
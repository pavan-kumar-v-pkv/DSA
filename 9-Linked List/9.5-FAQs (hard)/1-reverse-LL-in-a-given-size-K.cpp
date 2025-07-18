// Given the head of a singly linked list containing integers, reverse the 
// nodes of the list in groups of k and return the head of the modified list. 
// If the number of nodes is not a multiple of k, then the remaining nodes at 
// the end should be kept as is and not reversed.
// Do not change the values of the nodes, only change the links between nodes.
#include <bits/stdc++.h>
using namespace std;    

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
    Node(int val, Node* nextNode) : data(val), next(nextNode) {}
};

// time: O(2N) for traversing the list for find the Kth element in a group and reversing the group
// space: O(1) as we are not using any extra space except for pointers
Node*reverseList(Node* head){
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while(current != nullptr){
        next = current->next; // store the next node
        current->next = prev; // reverse the link
        prev = current; // move prev to current
        current = next; // move to the next node    
    }
    return prev; // new head of the reversed list
}

Node* getKthNode(Node* temp, int k){
    // decrement k as we already start from the 1st node
    k--;
    while(temp != nullptr && k > 0){
        k--;
        temp = temp->next; 
    }
    return temp; // return the Kth node or nullptr if not found
}
Node* reverseKgroup(Node* head, int k){
    // initialize a temp node to traverse the list
    Node* temp = head;
    // initialise a pointer to track the last node of the previous group
    Node* prevGroupEnd = nullptr;

    while(temp != nullptr){
        // get the Kth node of the current group
        Node* kThNode = getKthNode(temp, k);
        // if the kth node is NULL (not a complete group)
        if(kThNode == nullptr){
            // if there was a previous group, link the last node to the current node
            if(prevGroupEnd != nullptr){
                prevGroupEnd->next = temp;
            }
            break; // exit the loop as we cannot reverse this group
        }
        // store the next node after the Kth node
        Node* nextGroupStart = kThNode->next;
        // Disconnect the Kth node to prepare for reversal
        kThNode->next = nullptr;
        // Reverse the current group of k nodes
        reverseList(temp);
        // adjust the head if the reversal starts from the head
        if(temp == head){
            head = kThNode; // new head after reversal
        } else {
            prevGroupEnd->next = kThNode; // link the previous group to the new head
        }

        // update the previous group end to the last node of the current group
        prevGroupEnd = temp;
        // move temp to the start of the next group
        temp = nextGroupStart;
    }
    return head; // return the modified head of the list
}
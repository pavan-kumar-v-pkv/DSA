// Given the head of a singly Linked List, return the middle node of the Linked 
// List.
// If the Linked List has an even number of nodes, return the second middle one.
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

//brute force approach
// Time Complexity: O(N), where N is the number of nodes in the linked list.
// Firstly the size of the linked list is determined which takes O(N) time. 
// Then traversing to the middle nodes takes another O(N/2) time. 
// Thus the overall time complexity is O(N) + O(N/2) or O(3N/2) or O(N).
// space Complexity: O(1), no extra space is used.
Node* middleOfLinkedList(Node* head){
    Node* temp = head;
    int cnt= 0;

    while(temp != nullptr){
        cnt++;
        temp = temp->next;
    }

    int midPos = cnt/2 + 1; // if even, return second middle node
    temp = head;
    for(int i=1;i<midPos;i++){
        temp = temp->next;
    }
    return temp; // return the middle node
}

// Optimized approach using two pointers
// time: O(N/2) where N is the number of nodes in the linked list.
// space: O(1), no extra space is used.
Node* middleOfLinkedListOptimized(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next; // move slow pointer by 1 step
        fast = fast->next->next; // move fast pointer by 2 steps
    }
    return slow; // when fast reaches the end, slow will be at the middle
}


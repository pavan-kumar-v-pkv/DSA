// Given two non-empty linked lists l1 and l2 which represent two non-negative 
// integers.
// The digits are stored in reverse order with each node storing one digit.
// Add two numbers and return the sum as a linked list.
// The sum Linked List will be in reverse order as well.
// The Two given Linked Lists represent numbers without any leading zeros, 
// except when the number is zero itself.
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

// time: O(max(m, n)), where m and n are the lengths of the two linked lists.
// space: O(max(m, n)), for the new linked list that is created.
Node* addTwoNumbers(Node* l1, Node* l2){
    Node* dummy = new Node(-1);
    Node* current = dummy;
    int carry = 0;

    while(l1 != nullptr || l2 != nullptr || carry){
        int sum = carry;
        if(l1 != nullptr){
            sum += l1->data;
            l1 = l1->next;
        }
        if(l2 != nullptr){
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10; // calculate the carry for the next iteration
        current->next = new Node(sum % 10);
        current = current->next;
    }
    return dummy->next; // return the next of dummy node which is the head of the new linked list 
}


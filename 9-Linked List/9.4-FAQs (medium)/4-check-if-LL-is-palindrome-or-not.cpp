// Given the head of a singly linked list representing a positive integer number.
// Each node of the linked list represents a digit of the number, with the 1st 
// node containing the leftmost digit of the number and so on. Check whether 
// the linked list values form a palindrome or not. Return true if it forms a 
// palindrome, otherwise, return false.
// A palindrome is a sequence that reads the same forward and backwards.
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

// brute force appraoch
// time: O(2*N) = O(N), where N is the number of nodes in the linked list.
// space: O(N), we are using a stack to store the values of the linked list
bool isPalindrome(Node* head){
    stack<int> st;
    Node* temp = head;
    // push all the values of the linked list into the stack
    while(temp != nullptr){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    // pop the values from the stack and compare with the linked list valuesw
    while(temp != nullptr){
        if(temp-> data != st.top()){
            return false; // if any value does not match, return false
        }
        st.pop();
        temp = temp->next;
    }
    return true; // if all values match, return true
}

// optimized approach using two pointers
// time: O(2*N), where N is the number of nodes in the linked list.
// space: O(1), no extra space is used.
Node* reverseList(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    // reverse the linked list;
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; // return the new head of the reversed linked list
}
bool isPalindromeOptimized(Node* head){
    if(head == nullptr || head->next == nullptr){
        return true; // if the linked list is empty or has only one node, it is a palindrome
    }

    Node* slow = head;
    Node* fast = head;
    // find the middle of the linked list using two pointers
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse the second half of the linked list
    Node* newHead = reverseList(slow->next);
    Node* firstHalf = head;
    Node* secondHalf = newHead;
    // compare the first half and the reversed second half of the linked list
    while(secondHalf != nullptr){
        if(firstHalf->data != secondHalf->data){
            reverseList(newHead);
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    reverseList(newHead);
    return true;
}
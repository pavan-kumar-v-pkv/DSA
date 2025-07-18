// Given the head of a singly linked list. Sort the values of the linked list 
// in non-decreasing order and return the head of the modified linked list.
#include <bits/stdc++.h>
using namespace std;    

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
    Node(int val, Node* nextNode) : data(val), next(nextNode) {}
};

// brute force approach
// time: O(N) + O(NlogN) + O(N)
// space: O(N)
Node* sortList(Node* head){
    vector<int> arr;
    Node* temp = head;

    while(temp != nullptr){
        arr.push_back(temp->data);
        temp = temp->next;
    }

    sort(arr.begin(),arr.end());
    temp  = head;
    for(int i=0;i<arr.size();i++){
        temp->data = arr[i];
        temp = temp->next;
    }

    return head;
}

// optimized approach
// time: O(NlogN)
// space: O(1)
Node* merge(Node* l1, Node* l2){
    Node* dummy = new Node(-1);
    Node* temp = dummy;

    while(l1 != nullptr && l2 != nullptr){
        if(l1->data < l2->data){
            temp->next = l1;
            l1 = l1->next;
        }
        else{
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }

    if(l1 != nullptr){
        temp->next = l1;
    }
    else{
        temp->next = l2;
    }

    return dummy->next; 
}
Node* findMiddle(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    Node* slow = head;
    Node* fast = head->next; // so that in the even number of nodes, slow will point to the first middle node

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* sortList2(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    // find the middle of the linked list
    Node* middle = findMiddle(head);

    // divide the list into two halves
    Node* right = middle->next;
    middle->next = nullptr;
    Node* left = head;

    // recursively sort left and right halves
    left = sortList2(left);
    right = sortList2(right);
    // merge the sorted halves
    return merge(left, right);

}
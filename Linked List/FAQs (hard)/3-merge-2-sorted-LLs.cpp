// Given the heads of two linked lists, list1 and list2, where each linked list 
// has its elements sorted in non-decreasing order, merge them into a single 
// sorted linked list and return the head of the merged linked list.
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
// time: (N1 + N2) + (NlogN) + O(N)
// space : O(N) for storing the merged list
Node* mergeTwoLists(Node* list1, Node* list2){
    vector<int> arr;
    Node* t1 = list1;
    Node* t2 = list2;

    while(t1 != nullptr){
        arr.push_back(t1->data);
        t1 = t1->next;
    }
    while(t2 != nullptr){
        arr.push_back(t2->data);
        t2 = t2->next;
    }

    sort(arr.begin(), arr.end());
    Node* dummyNode = new Node(-1);
    Node* current = dummyNode;
    for(int i=0;i<arr.size();i++){
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return dummyNode->next;
}

// optimal approach
// time: O(N1 + N2) where N1 and N2 are the lengths
// of the two linked lists
// space: O(1) as we are not using any extra space except for pointers
Node* mergeTwoListsOptimal(Node* list1, Node* list2){
    // create a dummy node to serve as the head of the merged list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while(list1 != nullptr && list2 != nullptr){
        if(list1->data < list2->data){
            temp->next = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    if(list1 != nullptr){
        temp->next = list1;
    }
    else{
        temp->next = list2;
    }

    return dummyNode->next; // return the head of the merged list
}
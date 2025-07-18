// Given the heads of two linked lists A and B, containing positive integers. 
// Find the node at which the two linked lists intersect. If they do intersect, 
// return the node at which the intersection begins, otherwise return null.

// The Linked List will not contain any cycles. The linked lists must retain 
// their original structure, given as per the input, after the function returns.

// Note: for custom input, the following parameters are required(your program 
// is not provided with these parameters):

// intersectVal - The value of the node where the intersection occurs. This is 
// -1 if there is no intersected node.
// skipA - The number of nodes to skip ahead in listA (starting from the head) 
// to get to the intersected node(-1 if no intersection).
// skipB - The number of nodes to skip ahead in listB (starting from the head) 
// to get to the intersected node(-1 if no intersection).
// listA - The first linked list.
// listB - The second linked list.

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

// brute force approach
// time: O(n+m), where n is the number of nodes in listA and m is the number of nodes in listB.
// space: O(n), where n is the number of nodes in listA.
Node* getIntersectionNode(Node* headA, Node* headB) {
    unordered_set<Node*> nodes_set;
    while(headA != nullptr){
        nodes_set.insert(headA);
        headA = headA->next;
    }

    // traverse the second linked list and check for intersection
    while(headB != nullptr){
        if(nodes_set.find(headB) != nodes_set.end()){
            return headB; // if the node is found in the set, return it
        }
        headB = headB->next; // move to the next node in listB
    }
    return nullptr;
}

// better approach using two pointers
// time:O(n) + O(m) + O(|n-m|) + O(min(n, m)) =>O(n+m), where n is the number of nodes in listA and m is the number of nodes in listB.
// space: O(1), no extra space is used
Node* collisionPoint(Node* headA, Node* headB, int skip){
    Node* t1 = headA;
    Node* t2 = headB;

    // adjust the pointers to same level
    for(int i=0;i<skip;i++){
        t2 = t2->next; // move t2 ahead by skip nodes
    }

    while(t1 != t2){
        t1 = t1->next;
        t2 = t2->next;
    }
    return t1; // return the intersection point
}
Node* getIntersectionNodeBetter(Node* headA, Node* headB){
    Node* t1 = headA;
    Node* t2 = headB;
    int n1 = 0, n2 = 0;
    // get the length of first linked list
    while(t1 != nullptr){
        n1++;
        t1 = t1->next;
    }
    while(t2 != nullptr){
        n2++;
        t2 = t2->next;
    }
    if(n1 < n2){
        return collisionPoint(headA, headB, n2-n1);
    }
    return collisionPoint(headB, headA, n1-n2);
}

// optimized approach using two pointers
// time: O(n+m), where n is the number of nodes in listA and m is the number of nodes in listB.
// space: O(1), no extra space is used
Node* getIntersectionNode3(Node* headA, Node* headB){
    // edge case
    if(!headA || !headB){
        return nullptr; // if either list is empty, return nullptr
    }

    Node* t1 = headA;
    Node* t2 = headB;

    while(t1 != t2){
        // move both pointers one step at a time
        t1 = t1->next;
        t2 = t2->next;
        // if intersection is found
        if(t1 == t2)
            return t2;

        // if either pointer reaches end, place at the front of next linked list
        if(t1 == nullptr) t1 = headB;
        if(t2 == nullptr) t2 = headA;
    }
    return t1;

}
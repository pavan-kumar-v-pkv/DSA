// Given the head of a special linked list of n nodes where each node contains 
// an additional pointer called 'random' which can point to any node in the 
// list or null.
// Construct a deep copy of the linked list where, n new nodes are created 
// with corresponding values as original linked list.
// The random pointers point to the corresponding new nodes as per their 
// arrangement in the original list.
// Return the head of the newly constructed linked list.
// Note: For custom input, a n x 2 matrix is taken with each row having 2 
// values:[ val, random_index] where,
// val: an integer representing ListNode.val
// random_index: index of the node (0 - n-1) that the random pointer points to, 
// otherwise -1.
#include <bits/stdc++.h>
using namespace std;    

class Node{
public:
    int data;
    Node* next;
    Node* random;
    
    Node(int val) : data(val), next(nullptr), random(nullptr) {}
    Node(int val, Node* nextNode, Node* randomNode) 
        : data(val), next(nextNode), random(randomNode) {}
};

//brute force appprpoach
// time: O(2N)
// space: O(N) + O(N), where N is the number od nodes in LL and O(N) is for maintaining a map
Node* copyRandomList(Node* head){
    if(!head) return nullptr;

    // create a map to store the original node to their corresponding copied node
    unordered_map<Node*, Node*> mpp;
    Node* temp = head;

    while(temp != nullptr){
        Node* newNode = new Node(temp->data);
        mpp[temp] = newNode;
        temp = temp->next;
    }

    temp = head;
    while(temp != nullptr){
        Node* copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp = temp->next;
    }
    return mpp[head];
}

// optimized approach
// time: O(3N), 
// first traversal to create copies of the nodes and insert them between the original nodes.
// second traversal to set the random pointers of the copied nodes to their corresponding nodes.
// third traversal to separate the copied nodes from the original list.
// space: O(N)
void insertCopyNodes(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        Node* nextElement = temp->next;
        Node* copyNode = new Node(temp->data);
        temp->next = copyNode;
        copyNode->next = nextElement;
        temp = nextElement;
    }
}

void connectRandomPointers(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        Node* copyNode = temp->next;
        // if the original node's random pointer is not null, set the copied node's random pointer
        if(temp->random != nullptr){
            copyNode->random = temp->random->next;
        }else{
            copyNode->random = nullptr;
        }
        // move to the next original node
        temp = temp->next->next;
    }
}
Node* separateLists(Node* head){
    Node* temp = head;
    Node* dummy = new Node(-1);
    Node* res = dummy;

    while(temp != nullptr){
        res->next = temp->next; // add the copied node to the result list
        res = res->next; // move to the next copied node
        temp->next = temp->next->next; // restore the original list's next pointer
        temp = temp->next; // move to the next original node
    }
    return dummy->next; // return the head of the copied list
}
Node* copyRandomList2(Node* head){
    if(!head) return nullptr;

    // insert nodes in between
    insertCopyNodes(head);
    // connect random nodes
    connectRandomPointers(head);
    // separate the copied nodes from the original list
    return separateLists(head);
}
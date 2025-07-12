// Given a special linked list containing n head nodes where every node in the
// linked list contains two pointers:
// * ‘Next’ points to the next node in the list
// * ‘Child’ pointer to a linked list where the current node is the head
// * Each of these child linked lists is in sorted order and connected by a
// 'child' pointer.
// Flatten this linked list such that all nodes appear in a single sorted layer
// connected by the 'child' pointer and return the head of the modified list.
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node(int val) : data(val), next(nullptr), child(nullptr) {}
    Node(int val, Node *nextNode, Node *childNode) : data(val), next(nextNode), child(childNode) {}
};

// brute force approach
// time: O(N*M) + O(N*M log(N*M)) + (N*M) where N is the number of head nodes and M is the average number of nodes in each child linked list
// space: O(N*M) for storing the merged list
Node *convertArrToLinkedList(vector<int> &arr)
{
    Node *dummyNode = new Node(-1);
    Node *current = dummyNode;

    for (int i = 0; i < arr.size(); i++)
    {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return dummyNode->next;
}
Node *flattenLinkedList(Node *head)
{
    vector<int> arr;
    Node *temp = head;

    // traverse the linked list
    while (temp != nullptr)
    {
        Node *t2 = temp;
        // traverse the child linked list
        while (t2 != nullptr)
        {
            // staore each node's data in the array
            arr.push_back(t2->data);
            t2 = t2->child; // move to the next child node
        }
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    return convertArrToLinkedList(arr);
}

// optimal approach
// time: O(N*(2M)) ~ O(2NM) where N is the number of head nodes and M is the average number of nodes in each child linked list
// space: O(1) as we are not using any extra space except for pointers
Node *merge(Node *l1, Node *l2)
{
    Node *dummyNode = new Node(-1);
    Node *current = dummyNode;

    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->data < l2->data)
        {
            current->child = l1;
            current = l1;
            l1 = l1->child;
        }
        else
        {
            current->child = l2;
            current = l2;
            l2 = l2->child;
        }
        current->next = nullptr;
    }
    if (l1 != nullptr)
    {
        current->child = l1;
    }
    else
    {
        current->child = l2;
    }

    // break the last node's link tp prevent cycles
    if (dummyNode->child)
    {
        dummyNode->child->next = nullptr;
    }

    return dummyNode->child;
}
Node *flattenLinkedListOptimal(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head; // if the list is empty or has only one node, return it

    Node *mergedHead = flattenLinkedListOptimal(head->next);
    // merge the current head with the merged head
    head = merge(head, mergedHead);
    return head;
}
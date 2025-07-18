// Given the head of a singly Linked List. Traverse the entire Linked List and 
// return its elements in an array in the order of their appearance.
#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(){
        val = 0;
        next = nullptr;
    }
    ListNode(int data){
        val = data;
        next = nullptr;
    }
    ListNode(int data, ListNode* next){
        val = data;
        this->next = next;
    }
};

class Solution {
public:
    vector<int> LLTraversal(ListNode *head) {
        vector<int> ans;
        ListNode* temp = head;

        while(temp != nullptr){
            ans.push_back(temp->val);
            temp = temp->next;
        }
        return ans;
    }
};
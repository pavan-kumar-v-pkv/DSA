#include<bits/stdc++.h>
using namespace std;

struct Node{
public:
    int data;
    Node* next;
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = NULL;
    }
};

// function to convert ana rray to a linked list
Node* arrayToLinkedList(int arr[], int size){
    if(size == 0) return nullptr;

    // create head of the linked list
    Node* head = new Node(arr[0]);
    Node* current = head;

    // iterate through the array and create nodes
    for(int i=1;i<size;i++){
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

// to calculate the length of a linked list
int lengthOfLinkedList(Node* head){
    int length = 0;
    Node* current = head;
    while(current != nullptr){
        length++;
        current = current->next;
    }
    return length;
}

// search element in a linked list
bool searchInLinkedList(Node* head, int key){
    Node* current = head;
    while(current != nullptr){
        if(current->data == key){
            return true;
        }
        current = current->next;
    }
    return false;
}

void printLinkedList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    
    cout<<endl;
}
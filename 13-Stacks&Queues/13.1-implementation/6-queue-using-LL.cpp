// Implement a First-In-First-Out (FIFO) queue using a singly linked list. The 
// implemented queue should support the following operations: push, pop, peek, 
// and isEmpty.
// Implement the LinkedListQueue class:
// void push(int x): Adds element x to the end of the queue.
// int pop(): Removes and returns the front element of the queue.
// int peek(): Returns the front element of the queue without removing it.
// boolean isEmpty(): Returns true if the queue is empty, false otherwise.
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int d){
        val = d;
        next = nullptr;
    }
};

class LinkedListQueue{
    Node* start;
    Node* end;
    int size;
public:
    LinkedListQueue(){
        start = start = nullptr;
        size = 0;
    }

    void push(int x){
        // push at the tail operation
        Node* element = new Node(x);
        // if it is the first element being pushed
        if(start == nullptr){
            // initialise the pointers
            start = end = element;
        }
        else{
            end->next = element; // updating pointers
            end = element;
        }
        size++;
    }

    int pop(){
        if(start == nullptr){
            return -1;
        }

        int value = start->val;
        Node *temp = start;
        start = start->next;
        delete temp;
        size--;

        return value;
    }

    int peek(){
        if(start == nullptr){
            return -1;
        }
        return start->val;
    }

    bool isEmpty(){
        return (size == 0);
    }
};

int main() {
    // Creating a queue
    LinkedListQueue q;

    // List of commands
    vector<string> commands = {"LinkedListQueue", "push", "push", 
                               "peek", "pop", "isEmpty"};
    // List of inputs
    vector<vector<int>> inputs = {{}, {3}, {7}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            q.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << q.pop() << " ";
        } else if (commands[i] == "peek") {
            cout << q.peek() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (q.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "LinkedListQueue") {
            cout << "null ";
        }
    }

    return 0;
}
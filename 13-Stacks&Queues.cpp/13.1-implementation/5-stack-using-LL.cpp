// Implement a Last-In-First-Out (LIFO) stack using a singly linked list. The 
// implemented stack should support the following operations: push, pop, top, 
// and isEmpty.
// Implement the LinkedListStack class:
// void push(int x): Pushes element x onto the stack.
// int pop(): Removes and returns the top element of the stack.
// int top(): Returns the top element of the stack without removing it.
// boolean isEmpty(): Returns true if the stack is empty, false otherwise.
#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(1) for push, pop, size,isEmpty, peek operations.

// Space Complexity: O(N) because the stack requires space proportional to the number of elements it stores.
struct Node{
    int val;
    Node* next;
    Node(int d){
        val = d;
        next = nullptr;
    }
};

class LinkedListStack{
    Node* head; // top of stack
    int size;
public:
    LinkedListStack(){
        head = nullptr;
        size = 0;
    }

    void push(int x){
        // insert element at the head operation
        Node *element = new Node(x);
        element->next = head; // updating the pointers;
        head = element;
        size++;
    }

    int pop(){
        if(head == nullptr)
            return -1;

        int value = head->val;
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;

        return value;
    }

    int top(){
        if(head == nullptr){
            return -1;
        }
        return head->val;
    }

    bool isEmpty(){
        return (size == 0);
    }
};

int main() {
    // Creating a stack
    LinkedListStack st;

    // List of commands
    vector<string> commands = {"LinkedListStack", "push", "push", 
                               "pop", "top", "isEmpty"};
    // List of inputs
    vector<vector<int>> inputs = {{}, {3}, {7}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            st.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << st.pop() << " ";
        } else if (commands[i] == "top") {
            cout << st.top() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (st.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "LinkedListStack") {
            cout << "null ";
        }
    }

    return 0;
}
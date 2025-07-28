// Implement a First-In-First-Out (FIFO) queue using a single stack. The 
// implemented queue should support the following operations: push, pop, peek, 
// and isEmpty.
// Implement the StackQueue class:
// void push(int x): Adds element x to the end of the queue.
// int pop(): Removes and returns the front element of the queue.
// int peek(): Returns the front element of the queue without removing it.
// boolean isEmpty(): Returns true if the queue is empty, false otherwise.
#include<bits/stdc++.h>
using namespace std;

// using two stack where push operation is O(N)
// Time Complexity: O(N) where N is the number of elements.

// Space Complexity: O(2N) because, in the worst case, both the input and 
// output stacks can each hold up to N elements, totalling 2N elements. Here N 
// is the size of the stack.
class StackQueue{
    stack<int> st1, st2;
public:
    StackQueue(){}
    void push(int x){
        // pop out elements from the first stack and push on top of the second stack
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        // insert the desired element
        st1.push(x);
        
        // pop out elements from the second stack and push back on top of the first stack
        while(!st2.empty()){
            st1.push(st2.top());
            st1.pop();
        }
    }

    int pop(){
        if(st1.empty()){
            cout<<"Queue is Empty";
            return -1;
        }
        int topElement = st1.top();
        st1.pop(); 

        return topElement;
    }

    int peek(){
        if(st1.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return st1.top();
    }

    bool isEmpty(){
        return st1.empty();
    }
};

int main() {
    StackQueue q;
    
    // List of commands
    vector<string> commands = {"StackQueue", "push", "push", 
                               "pop", "peek", "isEmpty"};
    // List of inputs
    vector<vector<int>> inputs = {{}, {4}, {8}, {}, {}, {}};

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
        } else if (commands[i] == "StackQueue") {
            cout << "null ";
        }
    }
    
    return 0;
}
// Implement a Last-In-First-Out (LIFO) stack using a single queue. The 
// implemented stack should support the following operations: push, pop, top, 
// and isEmpty.
// Implement the QueueStack class:
// void push(int x): Pushes element x onto the stack.
// int pop(): Removes and returns the top element of the stack.
// int top(): Returns the top element of the stack without removing it.
// boolean isEmpty(): Returns true if the stack is empty, false otherwise.
#include<bits/stdc++.h>
using namespace std;

// time:
// Push operation: O(n) (where n is the number of elements in the queue at 
// that time) because every time an element is pushed, all the elements in the 
// queue are popped from front and pushed in the back again.
// Pop operation: O(1) as constant operations are performed.
// Top operation: O(1) as constant operations are performed.
// IsEmpty operation: O(1) as constant operations are performed.
// space: O(k) for storing k elements in the queue.
class QueueStack{
    queue<int>q;
public:
    void push(int x){
        // get size
        int s = q.size();
        q.push(x);

        // move elements before new element to back
        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop(){
        int n = q.front();
        q.pop();
        return n;
    }

    int top(){
        return q.front();
    }

    bool isEmpty(){
        return q.empty();
    }
};

int main() {
    QueueStack st;
    
    // List of commands
    vector<string> commands = {"QueueStack", "push", "push", 
                               "pop", "top", "isEmpty"};
    // List of inputs
    vector<vector<int>> inputs = {{}, {4}, {8}, {}, {}, {}};

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
        } else if (commands[i] == "QueueStack") {
            cout << "null ";
        }
    }

    return 0;
}
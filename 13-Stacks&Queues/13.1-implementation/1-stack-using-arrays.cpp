// Implement a Last-In-First-Out (LIFO) stack using an array. The implemented 
// stack should support the following operations: push, pop, peek, and isEmpty.
// Implement the ArrayStack class:
// void push(int x): Pushes element x onto the stack.
// int pop(): Removes and returns the top element of the stack.
// int top(): Returns the top element of the stack without removing it.
// boolean isEmpty(): Returns true if the stack is empty, false otherwise.
#include<bits/stdc++.h>
using namespace std;

// time: O(1)
// space: depends on the size of the array
class ArrayStack{
private:
    int* stackArray;
    int capacity;
    int topIndex;
public:
    ArrayStack(int size=1000){
        capacity = size;
        stackArray = new int[capacity];
        topIndex = -1;
    }
    // destructor
    ~ArrayStack() {
        delete[] stackArray;
    }

    void push(int x){
        if(topIndex >= capacity-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }

        stackArray[++topIndex] = x;
    }

    int pop(){
        if (isEmpty()){
            cout<<"Stack in empty"<<endl;
            return -1;
        }
        return stackArray[topIndex--];
    }

    int top(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        return stackArray[topIndex];
    }

    bool isEmpty(){
        return topIndex == -1;
    }
};

int main(){
    ArrayStack stack;
    vector<string> commands = {"ArrayStack", "push", "push", "top", "pop", "isEmpty"};
    vector<vector<int> > inputs = {{}, {5}, {10}, {}, {}, {}};

    for(size_t i=0;i<commands.size();++i){
        if(commands[i] == "push"){
            stack.push(inputs[i][0]);
            cout<<"null ";
        }
        else if (commands[i] == "pop") {
            cout << stack.pop() << " ";
        } else if (commands[i] == "top") {
            cout << stack.top() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (stack.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "ArrayStack") {
            cout << "null ";
        }
    }
    return 0;
}
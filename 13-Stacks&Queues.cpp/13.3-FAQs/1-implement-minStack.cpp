// Design a stack that supports the following operations in constant time: push, 
// pop, top, and retrieving the minimum element.
// Implement the MinStack class:
// MinStack(): Initializes the stack object.
// void push(int val): Pushes the element val onto the stack.
// void pop(): removes the element on the top of the stack.
// int top(): gets the top element of the stack.
// int getMin(): retrieves the minimum element in the stack.
#include<bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(1) all operations take constant time
// space: O(2*N) all the numbers are stored in pairs leading to a stack space of O(2*N).
class MinStack1{
private:
    stack<pair<int, int> > st;
public:
    MinStack1(){}

    void push(int x){
        // if stack is empty
        if(st.empty()){
            st.push({x, x});
            return;
        }
        int mini = min(getMin(), x);
        st.push({x, mini});
    }

    void pop(){
        st.pop();
    }

    int top(){
        return st.top().first;
    }

    int getMin(){
        return st.top().second;
    }
};

// optimal approach
// time: O(1) all operations take constant time
// space: O(N) where N is the total number of calls made for push operation
class MinStack2{
private:
    stack<int> st;
    int mini;
public:
    MinStack2(){}

    void push(int value){
        if(st.empty()){
            mini = value;
            st.push(value);
            return;
        }

        // if the value is greater then the minimum
        if(value > mini){
            st.push(value);
        }
        else{
            // add the modified value to stack
            st.push(2*value-mini);
            mini = value;
        }
    }

    void pop(){
        // base case
        if(st.empty())
            return;

        // get the top
        int x = st.top();
        st.pop();

        // if the modified values was added to stack
        if(x < mini){
            // update the minimum to previous minimum
            mini = 2*mini - x;

        }
    }

    int top(){
        // base case
        if(st.empty()) return -1;
        // get the top
        int x = st.top();
        // retunr top if minimum is less than the top
        if(mini < x) return x;
        // otherwise
        return mini;
    }

    int getMin(){
        return mini;
    }

};
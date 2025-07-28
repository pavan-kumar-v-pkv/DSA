// Given string str containing just the characters '(', ')', '{', '}', '[' and 
// ']', check if the input string is valid and return true if the string is 
// balanced otherwise return false
#include<bits/stdc++.h>
using namespace std;
// time: O(N), for traversing the string
// space: O(N), for using stack to store the parenthesis

bool isMatched(char open, char close){
    if((open == '(' && close == ')') ||
      (open == '[' && close == ']') ||
      (open == '{' && close == '}'))
    return true;

    return false;
}
bool isValid(string str){
    stack<char> st;

    for(int i=0;i<str.length();i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            st.push(str[i]);
        }
        else{
            if(st.empty())
                return false;

            // get the top element from the stack
            char ch = st.top();
            st.pop();

            // if the opening and closing bracets are not matched, return false
            if(!isMatched(ch, str[i]))
                return false;
        }
    }
    // if stack is empty, the string is valid, else invalid
    return st.empty();
}
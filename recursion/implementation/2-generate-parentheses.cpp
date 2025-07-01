// Given an integer n.Generate all possible combinations of well-formed parentheses of length 2 x N.
#include<bits/stdc++.h>
using namespace std;

// time: O(4^n / sqrt(n))
// space: O(4^n / sqrt(n))
void func(int open, int close, int n, string s, vector<string>& ans){
    // base case: if the number of open and close parentheses used
    // is equal to the total number of pairs, add the string to the result
    if(open == close && (open + close)== 2*n){
        ans.push_back(s);
        return;
    }
    // if the number of open parentheses is less than n, we can add an open parenthesis
    if(open < n){
        func(open + 1, close, n, s + "(", ans);
    }

    // if the number of close parentheses is less than open, we can add a close parenthesis
    if(close < open){
        func(open, close + 1, n, s + ")", ans);
    }
}
vector<string> generateParenthesis(int n){
    // vector to store the result
    vector<string> result;
    // helper function to generate parentheses
    func(0, 0, n, "", result);
    return result;
}
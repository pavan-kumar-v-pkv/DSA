// Find the validity of an input string s that only contains the letters '(', 
// ')' and '*'.
// A string entered is legitimate if
// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis
// '(' or an empty string "".
#include<bits/stdc++.h>
using namespace std;

// brute force approach using recursion
// time: O(3^N) where N is the length of the string
// space: O(N) for the recursion stack
bool checkValid(int ind, int count, string &s, vector<vector<int> >& dp){
    // basecase
    if(count < 0) return false;
    if(ind == s.size())
        return count == 0;

    // if already computed, returnt he value directly
    if(dp[ind][count] != -1) return dp[ind][count];

    bool ans = false;
    if(s[ind] == '(')
        ans = checkValid(ind+1, count+1, s, dp);
    else if(s[ind] == ')')
        ans = checkValid(ind+1, count-1, s, dp);
    else{
        for(int i=-1;i<=1;i++){
            ans = ans || checkValid(ind+1, count+i, s, dp);
        }
    }

    return dp[ind][count] = ans; // store the result in dp table and return
}

bool isValid(string s){
    int n = s.size();
    // dp table
    vector<vector<int> > dp(n, vector<int>(n, -1));
    return checkValid(0, 0, s, dp);
}

// optimal approach
// time: O(N) where N is the length of the string
// space: O(1) for constant space usage
bool isValid2(string s){
    int minOpen = 0 , maxOpen = 0;
    for(char c: s){
        if(c == '('){
            minOpen++;
            maxOpen++;
        }
        else if(c == ')'){
            minOpen--;
            maxOpen--;
        }
        else if(c == '*'){
            minOpen--;
            maxOpen++;
        }

        if(maxOpen < 0) return false; // if maxOpen is negative, it means we have more ')' than '('
        minOpen = max(minOpen, 0);
    }
    return minOpen == 0; // if minOpen is zero, it means we have balanced parentheses
}
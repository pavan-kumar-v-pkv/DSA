// Given a string s partition string s such that every substring of partition
// s palindrome. Return all possible palindrome partition of string s.
#include<bits/stdc++.h>
using namespace std;

// Function to check if a string is a palindrome
// time: O(2^n) where n is the length of the string, as it checks all substrings
// space: O(n) for the recursion stack

// Function to check if a substring is a palindrome
bool isPalindrome(string s, int start, int end){
    while(start <= end){
        if(s[start++] != s[end--])
            return false;
    }
    return true;
}

void dfs(int ind, string& s, vector<string>& path, vector<vector<string> >& ans){
    // if the index reaches the end of the string
    if(ind == s.size()){
        ans.push_back(path);
        return;
    }
    // iterate through the string from the current index
    for(int i=ind;i<s.size();i++){
        // check if the substring s[ind:i] is a palindrome
        if(isPalindrome(s, ind, i)){
            // if true, add it to the current path
            path.push_back(s.substr(ind, i-ind+1));
            // recursively call the function with the next index
            dfs(i+1, s, path, ans);
            // backtrack: remove the last added substring from the path
            path.pop_back();
        }
    }
}

vector<vector<string> > partition(string s){
    vector<vector<string> > ans;
    vector<string> path;
    // start the depth-first search from index 0
    dfs(0, s, path, ans);
    return ans;
}




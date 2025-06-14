// Given an input string as an array of characters, write a function that reverses the string.

#include<bits/stdc++.h>
using namespace std;


class Solution{	
public:		
    void solve(vector<char>& s, int i, vector<char>& ans){
        if(i == s.size())
            return;

        solve(s, i+1, ans);
        ans.push_back(s[i]);
    }
	vector<char> reverseString(vector<char>& s){
		//your code goes here
        vector<char> ans;
        int i = 0;
        solve(s, i, ans);
        return ans;
	}
};
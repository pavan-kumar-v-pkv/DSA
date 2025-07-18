// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position.
// For example, if s = "abcde", then it will be "bcdea" after one shift.

#include<bits/stdc++.h>
using namespace std;

class Solution{	
	public:
		bool rotateString(string& s,string& goal){
			//your code goes here
            if(s.length() != goal.length())
                return false;
            string temp = s + s;
            return temp.find(goal) != string::npos;
		}
};
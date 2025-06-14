#include<bits/stdc++.h>
using namespace std;
// Function to calculate the sum of first n natural numbers using recursion
class Solution{	
	public:		
        bool solve(string& s, int left, int right){
            if(left > right)
                return true;
            if(s[left] != s[right])
                return false;
            return solve(s, left+1, right-1);
        }
		bool palindromeCheck(string& s){
			//your code goes here
            int left = 0, right = s.length()-1;
            return solve(s, left, right);
		}
};
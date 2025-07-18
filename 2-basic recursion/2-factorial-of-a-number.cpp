#include<bits/stdc++.h>
using namespace std;

class Solution{	
	public:
        void solve(int n, long long int& ans){
            if(n == 0)
                return;

            ans *= n;
            solve(n-1, ans);
        }
		long long int factorial(int n){
			//your code goes here
            long long int ans = 1;
            solve(n, ans);
            return ans;
		}
};
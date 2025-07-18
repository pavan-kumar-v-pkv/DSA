#include<bits/stdc++.h>
using namespace std;

// Time Complexity O(N) — The function makes N recursive calls to reach the base case, so the time complexity is proportional to the number of calls made
// Space Complexity O(N) — In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space
class Solution{	
	public:
        void solve(int N, int& sum){
            if(N == 0)
                return;

            sum += N;
            solve(N-1, sum);
        }
		int NnumbersSum(int N){
			//your code goes here
            int sum = 0;
            solve(N, sum);
            return sum;
		}
};
#include<bits/stdc++.h>
using namespace std;

// Function to calculate the sum of first n natural numbers using recursion
// time complexity O(N) — The function makes N recursive calls to reach the base case, so the time complexity is proportional to the number of calls made
// space complexity O(N) — In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space
class Solution{	
	public:
        void solve(vector<int>& nums, int l, int r){
            if(l > r)
                return;

            swap(nums[l], nums[r]);
            solve(nums, l+1, r-1);
        }
		vector<int> reverseArray(vector<int>& nums){			
			//your code goes here
            
            int l=0, r=nums.size()-1;
            solve(nums, l, r);
            return nums;
		}
};
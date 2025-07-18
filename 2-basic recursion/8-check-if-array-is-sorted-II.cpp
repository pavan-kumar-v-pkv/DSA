#include<bits/stdc++.h>
using namespace std;

// time complexity O(N) — The function makes N recursive calls to check each element in the array, so the time complexity is proportional to the number of elements in the array.
// space complexity O(N) — In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space.
class Solution{	
	public:
        bool solve(vector<int>& nums, int i){
            if(i == nums.size())
                return true;

            if(nums[i] < nums[i-1])
                return false;

            return solve(nums, i+1);
        }
		bool isSorted(vector<int>& nums){
			//your code goes here
            int i = 1;
            return solve(nums, i);
		}
};
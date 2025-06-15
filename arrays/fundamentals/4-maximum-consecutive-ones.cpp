// Given a binary array nums, return the maximum number of consecutive 1s in the array.
// A binary array is an array that contains only 0s and 1s.

#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N) where N is the length of the input array. The function iterates through the entire array once.
// Space Complexity: O(1) as it uses a constant amount of space for the variables cnt and ans.
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int ans = 0;
    
        for(int i=0;i<nums.size();++i){
            if(nums[i] == 1)
                cnt++;
            else{
                ans = max(ans, cnt);
                cnt = 0;
            }
                
        }
        ans = max(ans, cnt);
        return ans;
    }
};
// Given an integer array nums, return a list of all the leaders in the array.
// A leader in an array is an element whose value is strictly greater than 
//all elements to its right in the given array. 
//The rightmost element is always a leader. The elements in the leader array 
//must appear in the order they appear in the nums array.
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // time: O(N^2), where N is the size of the nums array.
    // space: O(1), since we are not using any extra space except for the
    vector<int> leaders(vector<int>& nums){
        vector<int> ans;
        // check whether nums[i] is greater than all elements to its right
        // if it is, then it is a leader
        for(int i=0;i<nums.size();i++){
            bool leader=true;
            for(int j=i+1;j<nums.size();j++){
                // if nums[i] is not greater than nums[j], then it is not a leader
                // so we break the loop and set leader to false
                if(nums[j] >= nums[i]){
                    leader=false;
                    break;
                }
            }
            if(leader){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }

    // optimized version
    // time: O(N), where N is the size of the nums array.
    // space: O(1), an extra space to store the answer is not considered.
    vector<int> leaders2(vector<int>& nums) {
        vector<int> ans;
        if(nums.empty())
            return ans;

        int max = nums[nums.size()-1];
        ans.push_back(max); // the rightmost element is always a leader

        // check elements from right to left
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i] > max){
                ans.push_back(nums[i]);
                max = nums[i];
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

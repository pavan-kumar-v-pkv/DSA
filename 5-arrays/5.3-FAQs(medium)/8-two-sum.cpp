// Given an array of integers nums and an integer target. Return the indices(0 - indexed) of two elements in nums such that they add up to target.
// Each input will have exactly one solution, and the same element cannot be used twice. Return the answer in non-decreasing order.

#include <bits/stdc++.h>
using namespace std;    

class Solution{
    public:
    // brute force approach
    // time: O(N^2), where N is the number of elements in the array
    // space: O(1), no extra space is used
    vector<int> twoSum(vector<int>& nums, int target){
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans; // return empty vector if no solution is found
    }

    // better approach using hashing
    // time: O(N), where N is the number of elements in the array
    // space: O(N), where N is the number of elements in the array
    vector<int> twoSum2(vector<int>& nums, int target){
        unordered_map<int, int> mpp;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int num = nums[i];
            int complement = target - num;
            if(mpp.find(complement) != mpp.end()){
                vector<int> result;
                result.push_back(mpp[complement]);
                result.push_back(i);
                return result;
            }
            mpp[num] = i;
        }
        vector<int> result;
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }

    // optimized approach using two pointers
    // time: O(N log N), where N is the number of elements in the array
    // space: O(1), no extra space is used
    static bool comp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    vector<int> twoSum3(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        vector<vector<int> > eleIndex;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            temp.push_back(nums[i]);
            temp.push_back(i);
            eleIndex.push_back(temp);
        }
        // Sort the array based on the elements
        sort(eleIndex.begin(), eleIndex.end(), comp); 
        
        int left = 0, right = n - 1;
        while (left < right) {
            int sum = eleIndex[left][0] + eleIndex[right][0];
            if (sum == target) {
                ans.push_back(min(eleIndex[left][1], eleIndex[right][1]));
                ans.push_back(max(eleIndex[left][1], eleIndex[right][1]));
                return ans;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return ans; // return empty vector if no solution is found
    }
};



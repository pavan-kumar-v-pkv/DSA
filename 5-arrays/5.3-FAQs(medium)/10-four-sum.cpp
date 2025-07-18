// Given an integer array nums and an integer target. Return all quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
// ·      a, b, c, d are all distinct valid indices of nums.
// ·      nums[a] + nums[b] + nums[c] + nums[d] == target.
// Notice that the solution set must not contain duplicate quadruplets. One element can be a part of multiple quadruplets. The output and the quadruplets can be returned in any order.
#include <bits/stdc++.h>
using namespace std;    

class Solution {
    public:
    // brute force approach
    // time: O(N^4), where N is the number of elements in the array
    // space: O(2*no. of unique quadruplets), no extra space is used
    vector<vector<int> > fourSum(int n, vector<int>& arr, int target) {
        set<vector<int> > st;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    for(int l = k + 1; l < n; l++) {
                        if(arr[i] + arr[j] + arr[k] + arr[l] == target) {
                            vector<int> temp;
                            temp.push_back(arr[i]);
                            temp.push_back(arr[j]);
                            temp.push_back(arr[k]);
                            temp.push_back(arr[l]);
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        return vector<vector<int> >(st.begin(), st.end());
    }
    // better approach using hashing
    // time: O(N^3*log(M)), where N is the number of elements in the array
    // space: O(2*no. of unique quadruplets)+O(N), no extra space is used
    vector<vector<int> > foursum2(vector<int>& nums, int target){
        int n = nums.size();
        set<vector<int> > st;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                set<long long> hashset;
                for(int k=j+1;k<n;k++){
                    long long sum = nums[i] + nums[j] + nums[k];
                    long long fourth = target - sum;
                    if(hashset.find(fourth) != hashset.end()){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(fourth);
                        sort(temp.begin(), temp.end());
                        st.insert(temp);    
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int> > ans(st.begin(), st.end());
        return ans;
    }
    // optimized approach using two pointers
    // time: O(N^3), where N is the number of elements
    // space: O(no. of unique quadruplets), no extra space is used
    vector<vector<int> > fourSum3(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates
            for(int j = i + 1; j < n; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue; // skip duplicates
                int left = j + 1, right = n - 1;
                while(left < right) {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right];
                    if(sum == target) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        ans.push_back(temp);
                        while(left < right && nums[left] == nums[left + 1]) left++; // skip duplicates
                        while(left < right && nums[right] == nums[right - 1]) right--; // skip duplicates
                        left++;
                        right--;
                    } else if(sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};



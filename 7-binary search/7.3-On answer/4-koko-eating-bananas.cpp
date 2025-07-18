// A monkey is given n piles of bananas, where the 'ith' pile has nums[i] 
// bananas. An integer h represents the total time in hours to eat all the 
// bananas.
// Each hour, the monkey chooses a non-empty pile of bananas and eats k bananas.
// If the pile contains fewer than k bananas, the monkey eats all the bananas in
// that pile and does not consume any more bananas in that hour.
// Determine the minimum number of bananas the monkey must eat per hour to finish
// all the bananas within h hours.
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(n * max(nums[]))
// space: O(1)
int calculateTime(vector<int>& nums, int k){
    int totalH = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        totalH += ceil((double)nums[i] / (double)k);
    }
    return totalH;
}
int minEatingSpeed(vector<int>& nums, int h) {
    int maxi = *max_element(nums.begin(), nums.end());
    // find the minimum eating speed (k)
    for(int i=1;i<=maxi;i++){
        int reqTime = calculateTime(nums, i);
        if (reqTime <= h){
            return i;   
        }   
    }
    return -1;
}

// binary search approach
// time: O(n * log(max(nums[])))
// space: O(1)
int calculateTime2(vector<int>& nums, int k){
    int totalH = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        totalH += ceil((double)nums[i] / (double)k); // equivalent to ceil(nums[i] / k)
    }
    return totalH;
}
int minEatingSpeed2(vector<int>& nums, int k){
    int low = 1, high = *max_element(nums.begin(), nums.end());

    int totalH = 0;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        totalH = calculateTime2(nums, mid);
        if(totalH <= k){
            ans = mid;
            high = mid - 1; // search in the left half
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

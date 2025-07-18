// Given a sorted array of nums and an integer x, write a program to find the lower bound of x. 
// The lower bound algorithm finds the first or the smallest index in a sorted array where the
// value at that index is greater than or equal to a given key i.e. x.
// If no such index is found, return the size of the array.

#include<bits/stdc++.h>
using namespace std;   

// using binary search to find the lower bound
// time complexity: O(log n)
// space complexity: O(1)
int lowerBound(vector<int>& nums, int x){
    int low = 0, high = nums.size() - 1;
    int ans = nums.size(); // default answer is size of the array
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] >= x){
            ans = mid;
            high = mid - 1; // search in the left half
        }else{
            low = mid + 1; // search in the right half
        }
    }
    return ans; // return the index of the lower bound
}

// using lower_bound function from STL
// time complexity: O(log n)
// space complexity: O(1)
int lowerBoundSTL(vector<int>& nums, int x){
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}
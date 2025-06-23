// Given a sorted array of nums and an integer x, write a program to find the upper bound
// of x. The upper bound algorithm finds the first or the smallest index in a sorted array
// where the value at that index is greater than a given key i.e. x.
// If no such index is found, return the size of the array.
#include <bits/stdc++.h>
using namespace std;    

// using binary search to find theupper bound
// time complexity: O(log n)
// space complexity: O(1)
int upperBound(vector<int>& nums, int x){
    int low = 0, high = nums.size() - 1;
    int ans = nums.size();

    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] > x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

// using upper_bound function from STL
// time complexity: O(log n)
// space complexity: O(1)
int upperBoundSTL(vector<int>& nums, int x){
    return upper_bound(nums.begin(), nums.end(), x) - nums.begin();
}
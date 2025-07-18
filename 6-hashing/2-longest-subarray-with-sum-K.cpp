// Given an array nums of size n and an integer k, find the length of the 
//longest sub-array that sums to k. If no such sub-array exists, return 0.
#include <bits/stdc++.h>
using namespace std;   

// brute force solution
// time complexity: O(n^2)
// space complexity: O(1)
int getLongestSubarray(vector<int>& a, int k){
    int n = a.size();
    int len = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += a[j];
            if(sum == k){
                len = max(len, j-i+1);
            }
        }
    }
    return len;
}

// optimized solution using hashing
// time complexity: O(n) or O(nlogn) depending on the implementation of the unordered_map
// space complexity: O(n)
int getLongestSubarrayOptimized(vector<int>& a, int k){
    int n = a.size();
    unordered_map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for(int i=0;i<n;i++){
        // calculate the prefix sum till the current index
        sum += a[i];
        // if the prefix sum is equal to k, update maxLen
        if(sum == k){
            maxLen = max(maxLen, i+1);
        }
        // calculate the sum of remaining part, i.e., sum - k
        int rem = sum - k;
        // calculate the length and update maxLen if the remaining part exists in the map
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        // finally, update the map with checking if the current prefix sum already exists
        // if it does not exist, we store the index of the first occurrence
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}
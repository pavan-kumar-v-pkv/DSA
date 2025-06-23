// Given an array of integers nums and an integer k, return the total number 
// of subarrays whose sum equals to k.
#include <bits/stdc++.h>
using namespace std;

// brute force solution
// time complexity: O(n^2)
// space complexity: O(1)
int countSubarrays(vector<int>& arr, int k){
    int n = arr.size();
    int cnt = 0;

    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            if(sum == k){
                cnt++;
            }
        }
    }
    return cnt;
}

// optimized solution using hashing
// time complexity: O(n)
// space complexity: O(n)
int countSubarraysOptimized(vector<int>& arr, int k){
    int n = arr.size();
    //map <prefix sum, count of occurrences>
    unordered_map<int, int> preSumMap;
    int preSum = 0;
    int cnt = 0;
    preSumMap[0] = 1; // to handle the case when prefix sum equals k at some index
    for(int i=0;i<n;i++){
        // add current element to prefix sum
        preSum += arr[i];
        // calculate the remaining part of the prefix sum
        int rem = preSum - k;
        // add the number of subarrays to be removed
        cnt += preSumMap[rem];
        // update the count of prefix sum in the map
        preSumMap[preSum]++;
    }
    return cnt;

}


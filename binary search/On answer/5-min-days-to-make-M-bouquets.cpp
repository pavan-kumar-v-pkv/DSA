// Given n roses and an array nums where nums[i] denotes that the 'ith' rose
// will bloom on the nums[i]th day, only adjacent bloomed roses can be picked
// to make a bouquet. Exactly k adjacent bloomed roses are required to make a 
// single bouquet. Find the minimum number of days required to make at least m 
// bouquets, each containing k roses. Return -1 if it is not possible.
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(n * (max(num[]) - min(nums[])))
// space: O(1)
bool possible(vector<int>& arr, int day, int k, int m){
    int n = arr.size();
    int cnt = 0;
    int noOfB = 0;
    for(int i=0;i<n;i++){
        if(arr[i] <= day)
            cnt++;
        else{
            noOfB += cnt / k; // count how many bouquets can be made with the current count
            cnt = 0; // reset count for the next segment
        }
    }
    noOfB += cnt / k; // count bouquets for the last segment
    return noOfB >= m; // check if we can make at least m bouquets
}
int roseGarden(vector<int>& arr, int k, int m){
    long long val = m * 1ll * k * 1ll;
    int n = arr.size();
    if(n < val)
        return -1; // not enough roses to make m bouquets
    int mini = *min_element(arr.begin(), arr.end());
    int maxi = *max_element(arr.begin(), arr.end());
    for(int i=mini;i<=maxi;i++){
        if(possible(arr, i, k, m))
            return i;
    }
    return -1; // not possible to make m bouquets
}

// binary search approach
// time: O(n * log(max(nums[]) - min(nums[])))
// space: O(1)
bool possible2(vector<int>& arr, int day, int k, int m){
    int n = arr.size();
    int cnt = 0;
    int noOfB = 0;
    for(int i=0;i<n;i++){
        if(arr[i] <= day)
            cnt++;
        else{
            noOfB += cnt/k; // count how many bouquets can be made with the current count
            cnt = 0; // reset count for the next segment
        }
    }
    noOfB += cnt/k; // count bouquets for the last segment
    return noOfB >= m; // check if we can make at least m bouquets
}
int roseGarden2(vector<int>& arr, int k , int m){
    long long val = m * 1ll * k * 1ll;
    int n = arr.size();
    if(n < val)
        return -1;
    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(possible2(arr, mid, k, m)){
            ans = mid; // found a valid day, try to find a smaller one
            high = mid - 1; // search in the left half
        }
        else{
            low = mid + 1; // search in the right half
        }
    }
    return ans;
}
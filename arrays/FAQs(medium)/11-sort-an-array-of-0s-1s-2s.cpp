// Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing 
// order. The sorting must be done in-place, without making a copy of the original array.
// https://takeuforward.org/plus/dsa/arrays/faqs-medium/sort-an-array-of-0's-1's-and-2's?tab=editorial
#include <bits/stdc++.h>
using namespace std;    

// brute force approach using sorting
// time: O(N*logN), where N is the number of elements in the array
// space: O(1), where N is the number of elements in the array
vector<int> sortArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums;
}

// better approach: keeping count of values
// time: O(N) + O(N), where N is the number of elements in the array
// space: O(1), no extra space is used
void sortArray(vector<int>& arr, int n){
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 0) cnt0++;
        else if(arr[i] == 1)cnt1++;
        else cnt2++;
    }

    // replace the palces in the original array
    for(int i=0;i<arr.size();i++) {
        if(i < cnt0) arr[i] = 0;
        else if(i < cnt0 + cnt1) arr[i] = 1;
        else arr[i] = 2;
    }
}

// optimized approach: Dutch National Flag Algorithm
// time: O(N), where N is the number of elements in the array
// space: O(1), no extra space is used
void sortArrayDutchFlag(vector<int>& arr, int n){
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            mid++;
            low++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
        
    }
}

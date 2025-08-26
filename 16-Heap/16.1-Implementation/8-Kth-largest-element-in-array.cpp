// Given an array nums, return the kth largest element in the array.
#include<bits/stdc++.h>
using namespace std;

// time: O(NlogK)
// space: O(K)
int kthLargestElement(vector<int>& nums, int k){
    // min heap
    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i=0;i<k;i++){
        pq.push(nums[i]);
    }

    for(int i=k;i<nums.size();i++){
        if(nums[i] < pq.top()){
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}
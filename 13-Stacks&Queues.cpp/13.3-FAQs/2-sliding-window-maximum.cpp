// Given an array of integers arr, there is a sliding window of size k which is 
// moving from the very left of the array to the very right. You can only see 
// the k numbers in the window. Each time the sliding window moves right by one 
// position. Return the max sliding window.
#include<bits/stdc++.h>
using namespace std;

// brute force approach
// Time Complexity: O((N-K)*K) (where N is the size of given array)
// Using two nested loops.

// Space Complexity: O(N-K)
// Due to the size taken to return the answer.
vector<int> maxSlidingWindow(vector<int>& arr, int k){
    int n = arr.size();
    vector<int> ans;

    for(int i=0;i<=n-k;i++){
        int maxi = arr[i];
        for(int j=i;j<i+k;i++){
            maxi = max(maxi, arr[j]);
        }
        ans.push_back(maxi);
    }

    return ans;
}

// optimal approach using queue
// The maximum element in a particular window can be found directly using the 
// concept of monotonic queue, which includes storing the elements in a 
// decreasing order. This way the maximum element will always be the front 
// element in the queue which can be retrieved from the queue in constant time.
// In order to maintain the decreasing order of elements in queue, before adding
// the new element to the queue, all the smaller elements already present in 
// front of the queue can be popped out.

// But, a queue data structure does not provide pop operation from the front. 
// To overcome this, a Deque (Double Ended Queue) can be used, which enables 
// efficient insertion and retrieval from both ends.

// Time Complexity: O(N) (where N is the size of given array)
// 1. The array is traversed once taking O(N) time.
// 2. In the worst-case, each element is pushed in and popped out from deque only once taking O(N) time.

// Space Complexity: O(N-K) + O(K)
// 1. The deque will store K elements at maximum, taking O(K) time.
// 2. The result list stores N-K+1 maximums taking O(N-K) space.
vector<int> maxSlidingWindow2(vector<int>& arr, int k){
    int n = arr.size();
    vector<int> ans;
    deque<int> dq; // deque for storing the index

    for(int i=0;i<n;i++){
        // update deque to maintain current window
        if(!dq.empty() && dq.front() <= (i-k)){
            dq.pop_front();
        }
        // maintain the monotonic (decreasing) order of elements in deque
        while(!dq.empty() && arr[dq.back()] <= arr[i]){
            dq.pop_back();
        }

        // add current elements index to the deque
        dq.push_back(i);

        // store the maximum element from the first window possible
        if(i >= (k-1)){
            ans.push_back(arr[dq.front()]);
        }
    }
    return ans;
}
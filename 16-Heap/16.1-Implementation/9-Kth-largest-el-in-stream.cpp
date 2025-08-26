// Implement a class KthLargest to find the kth largest number in a stream. It should have the following methods:

// KthLargest(int k, int [] nums) Initializes the object with the integer k and the initial stream of numbers in nums
// int add(int val) Appends the integer val to the stream and returns the kth largest element in the stream.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.
#include<bits/stdc++.h>
using namespace std;

// time: O(NlogK)
// space: O(k)
class KthLargest{
    private:
    int K;
    priority_queue<int, vector<int>, greater<int> > pq;

    public:
    KthLargest(int k, vector<int>& nums){
        K = k;
        for(int i=0;i<nums.size();i++){
            if(pq.size() < K)
                pq.push(nums[i]);

            else if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }

    int add(int val){
        if(pq.size() < K){
            pq.push(val);

            return pq.top();
        }

        if(val > pq.top()){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};
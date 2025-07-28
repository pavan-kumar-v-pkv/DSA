// Given an integer array nums, determine the range of a subarray, defined as 
// the difference between the largest and smallest elements within the subarray. 
// Calculate and return the sum of all subarray ranges of nums.
// A subarray is defined as a contiguous, non-empty sequence of elements within 
// the array.
#include<bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(n^2)
// space: O(1)
long long subArrayRanges(vector<int>& arr){
    int n = arr.size();
    long long sum = 0;

    for(int i=0;i<n;i++){
        // to store the smallest value of subarray
        int smallest = arr[i];
        // to store the largest value eof subarray
        int largest = arr[i];
        for(int j=i;j<n;j++){
            smallest = min(smallest, arr[j]);
            largest = max(largest, arr[j]);
            sum += (largest - smallest);
        }
    }
    return sum;
}

// optimal approach using monotonic stack
// this can be solved by the concept of "sum of subarray minimums"
// time: O(10N) ~ O(N)
// space: O(N)
vector<int> findNSE(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i=n-1;i>=0;i--){
        int currEle = arr[i];
        while(!st.empty() && arr[st.top()] >= currEle)
            st.pop();

        ans[i] = !st.empty() ? st.top() : n;
        st.push(i);
    }
    return ans;
}
vector<int> findNGE(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i=n-1;i>=0;i--){
        int currEle = arr[i];
        while(!st.empty() && arr[st.top()] <= currEle)
            st.pop();

        ans[i] = !st.empty() ? st.top() : n;
        st.push(i);
    }
    return ans;
}
vector<int> findPSEE(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i=0;i<n;i++){
        int currEle = arr[i];
        while(!st.empty() && arr[st.top()] > currEle)
            st.pop();

        ans[i] = !st.empty() ? st.top() : -1;
        st.push(i);
    }
    return ans;
}
vector<int> findPGEE(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i=0;i<n;i++){
        int currEle = arr[i];
        while(!st.empty() && arr[st.top()] < currEle)
            st.pop();

        ans[i] = !st.empty() ? st.top() : -1;
        st.push(i);
    }
    return ans;
}
long long sumSubarrayMins(vector<int>& arr){
    vector<int> nse = findNSE(arr);
    vector<int> psee = findPSEE(arr);

    int n = arr.size();
    long long sum = 0;

    for(int i=0;i<n;i++){
        int left = i - psee[i];
        int right = nse[i] - i;
        long long freq = left*right*1LL;
        long long val = freq*arr[i]*1LL;
        sum += val;
    }
    return sum;
}
long long sumSubarrayMaxs(vector<int>& arr){
    vector<int> nge = findNGE(arr);
    vector<int> pgee = findPGEE(arr);

    int n = arr.size();
    long long sum = 0;

    for(int i=0;i<n;i++){
        // count of first type of subarrays
        int left = i - pgee[i];
        // count of second type of subarrays
        int right = nge[i] - i;
        // count of subarrays where current element is minimum
        long long freq = left*right*1LL;
        long long val = (freq*arr[i]*1LL);

        sum += val;
    }
    return sum;
}
long long subArrayRanges2(vector<int>& arr){
    return (sumSubarrayMaxs(arr) - sumSubarrayMins(arr));
}



// Given an array of integers arr of size n, calculate the sum of the minimum 
// value in each (contiguous) subarray of arr. Since the result may be large, 
// return the answer modulo 109 +7.
#include<bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(n^2)
// space: O(1)
int sumSubarrayMins(vector<int>& arr){
    int n = arr.size();
    int mod = 1e9+7;
    int sum = 0;

    for(int i=0;i<n;i++){
        // to store the minimum if subarray
        int mini = arr[i];
        // nested loop to get all subarrays strting from index i
        for(int j=i;j<n;j++){
            mini = min(mini, arr[j]);
            // update the sum;
            sum = (sum + mini) % mod;
        }
    }
    return sum;
}

// optimal approach using monotonic stack, NSE and PSE
// Time Complexity: O(N) (where N is the size of given array)
// Finding the indices of next smaller elements and previous smaller elements take O(2*N) time each.
// Calculating the sum of subarrays minimum takes O(N) time.

// Space Complexity: O(N)
// Finding the indices of the next smaller elements and previous smaller elements takes O(N) space each due to stack space.
// Storing the indices of the next smaller elements and previous smaller elements takes O(N) space each.
vector<int> findNSE(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st; // stack to store index

    for(int i=n-1;i>=0;i--){
        int currEle = arr[i];
        while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        arr[i] = !st.empty() ? st.top() : n;

        st.push(i);
    }
    return ans;
}
vector<int> findPSEE(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st; // stack to store index

    for(int i=0;i<n;i++){
        int currEle = arr[i];
        // pop the element in the stack until the stack is not empty
        // and the top elements are greater than the current element
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        ans[i] = !st.empty() ? st.top() : -1;

        st.push(i);
    }
    return ans;
}

int sumSubarrayMins2(vector<int>& arr){
    vector<int> nse = findNSE(arr);
    vector<int> psee = findPSEE(arr);

    int n = arr.size();
    int mod = 1e9+7;
    int sum = 0;

    for(int i=0;i<n;i++){
        // count of first type of subarray
        int left = i - psee[i];
        // count of second type of subarrays
        int right = nse[i] - i;
        // count the subsarray where current element is minimum
        long long freq = left*right*1LL;
        // contribution from current element
        int val = (freq*arr[i]*1LL) % mod;
        sum = (sum+val)%mod;
    }
    return sum;
}
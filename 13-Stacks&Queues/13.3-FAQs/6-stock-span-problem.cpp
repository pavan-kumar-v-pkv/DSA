// Given an array arr of size n, where each element arr[i] represents the stock 
// price on day i. Calculate the span of stock prices for each day.
// The span Si for a specific day i is defined as the maximum number of 
// consecutive previous days (including the current day) for which the stock 
// price was less than or equal to the price on day i.
#include<bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(N^2) where n is the length of the given arrat
// space: O(1)
vector<int> stockSpan(vector<int> arr, int n){
    vector<int> ans(n);

    for(int i=0;i<n;i++){
        // to store the current span of stocks
        int currSpan = 0;
        // traversing backwards to find stock span
        for(int j=i;j>=0;j--){
            // update stoack span
            if(arr[j] <= arr[i])
                currSpan++;

            else break;
        }
        // store the current span
        ans[i] = currSpan;
    }
    return ans;
}

// optimal approach using PGE
// time: O(N)
// Finding the indices of previous greater elements takes O(N) time.
// Traversing the array once to find the stock span taking O(N) time.

// space: O(N), the stack space used to find the PGE
vector<int> findPGE(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] <= arr[i])
            st.pop();

        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}
vector<int> stackSpan2(vector<int> arr, int n){
    vector<int> PGE = findPGE(arr);
    vector<int> ans(n);

    for(int i=0;i<n;i++){
        ans[i] = i - PGE[i];
    }

    return ans;
}
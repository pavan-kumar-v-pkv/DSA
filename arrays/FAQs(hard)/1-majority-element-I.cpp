// Given an integer array nums of size n, return the majority element of the array.
// The majority element of an array is an element that appears more than n/2 times in the array. The array is guaranteed to have a majority element.
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(N^2), where N is the number of elements in the array
// space: O(1), no extra space is used
int  majorityElement(vector<int> v){
    int n = v.size();

    for(int i=0;i<n;i++){
        // select the current element
        int cnt = 0;
        for(int j=0;j<n;j++){
            // count the number of occurrences of the current element
            if(v[i] == v[j]){cnt++;}
        }
        // if the count is greater than n/2, return the current element
        if(cnt > n/2)
            return v[i];
    }
    return -1; // return -1 if no majority element is found
}

// better approach using hashing
// time: O(N), where N is the number of elements in the array
// space: O(N), where N is the number of elements in the array
int majorityElement2(vector<int> v){
    int n = v.size();
    unordered_map<int, int> mpp;
    // storing the elements with its occurances in the map
    for(int i=0;i<n;i++){
        mpp[v[i]]++;
    }
    // iterating through the map to find the majority element
    for(auto it: mpp){
        if(it.second > n/2)
            return it.first;
    }
    return -1; // return -1 if no majority element is found
}

// optimal approach using Boyer-Moore Voting Algorithm
// time: O(N), where N is the number of elements in the array
// space: O(1), no extra space is used
int majorityElement3(vector<int> v){
    int n = v.size();
    int cnt = 0;
    int el;

    for(int i=0;i<n;i++){
        if(cnt == 0){
            el = v[i];
            cnt = 1; // reset the count to 1
        }
        else if(v[i] == el){
            cnt++; // increment the count if the current element is equal to the selected element
        }
        else{
            cnt--; // decrement the count if the current element is not equal to the selected element
        }
    }
    // chgecking if the stored element is the majority element
    int cnt1 = 0;
    for(int i=0;i<n;i++){
        if(v[i] == el)
            cnt1++;
    }
    if(cnt1 > n/2)
        return el;
    return -1; // return -1 if no majority element is found
}



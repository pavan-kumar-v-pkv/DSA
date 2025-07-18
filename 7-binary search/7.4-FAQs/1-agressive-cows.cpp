// Given an array nums of size n, which denotes the positions of stalls, and an 
// integer k, which denotes the number of aggressive cows, assign stalls to k 
// cows such that the minimum distance between any two cows is the maximum possible.
// Find the maximum possible minimum distance.
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(nlogn) + O(n*(max(nums[])-min(nums[])))
// space: O(1)
bool canWePlaceCows(vector<int>& stalls, int d, int k){
    int n = stalls.size();
    int cntCows = 1; // place the first cow in the first stall
    int lastPlacedCow = stalls[0]; // position of the last placed cow
    for(int i=0;i<n;i++){
        if(stalls[i] - lastPlacedCow >= d){
            cntCows++; // place a cow in the current stall
            lastPlacedCow = stalls[i]; // update the position of the last placed cow
        }
        if(cntCows == k) // if we have placed all cows
            return true; // return true if we can place all cows with at least distance d
    }
    return false;
}
int aggressiveCows(vector<int>& stalls, int k){
    int n = stalls.size();
    // sort the stalls to make it easier to find the distance
    sort(stalls.begin(), stalls.end());

    int limit = stalls[n-1] - stalls[0]; // maximum possible distance
    for(int d=1;d<=limit;d++){
        if(canWePlaceCows(stalls, d, k) == false){
            return d - 1; // return the maximum distance where cows can be placed
        }
    }
    return limit; // if all cows can be placed at the maximum distance
}

// binary search approach
// time: O(nlogn) + O(nlog(max(nums[])-min(nums[])))
// space: O(1)
bool canWePlaceCows2(vector<int>& stalls, int d, int k){
    int n = stalls.size();
    int cntCows = 1;
    int lastPlacedCow = stalls[0];
    for(int i=1;i<n;i++){
        if(stalls[i] - lastPlacedCow >= d){
            cntCows++;
            lastPlacedCow = stalls[i];
        }
        if(cntCows == k) // if we have placed all cows
            return true; // return true if we can place all cows with at least distance d   
    }
    return false;
}

int aggressiveCows2(vector<int>& stalls, int k){
    int n = stalls.size();
    // sort the stalls to make it easier to find the distance
    sort(stalls.begin(), stalls.end());
    int low = 1; // minimum distance
    int high = stalls[n-1] - stalls[0]; // maximum possible distance
    
    while(low <= high){
        int mid = low + (high-low)/2; // mid distance
        if(canWePlaceCows2(stalls, mid, k)){
            // if we can place cows with at least mid distance
            // we can try for a larger distance
            low = mid + 1; // search in the right half for a larger distance
        }
        else{
            high = mid - 1; // search in the left half for a smaller distance
        }
    }
    return high; // return the maximum distance where cows can be placed
}

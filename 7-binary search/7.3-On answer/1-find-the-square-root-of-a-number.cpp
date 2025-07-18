// Given a positive integer n. Find and return its square root. 
// If n is not a perfect square, then return the floor value of sqrt(n).

#include <bits/stdc++.h>
using namespace std;

// brute force approach
// Time Complexity: O(N)
// Space Complexity: O(1)
int floorSqrt(int n){
    int ans = 0;
    for(long long i=0;i<n;i++){
        long long square = i*i;
        if(square <= n*1LL){
            ans = i;
        }
        else{
            break;
        }
    }
    return ans;
}

// binary search approach
// Time Complexity: O(log N)
// Space Complexity: O(1)
int floorSqrt2(int n){
    int low = 1, high = n;
    int ans = 0;
    if(n == 0 || n == 1) return n; // handle edge cases
    if(n < 0) return -1; // negative numbers don't have real square roots
    
    while(low <= high){
        long long mid = low + (high - low)/2;
        long long val = mid * mid;
        if(val <= (long long)n){
            ans = mid; // update ans if mid^2 is less than or equal to n
            low = mid + 1; // search in the right half
        }
        else{
            high = mid - 1; // search in the left half
        }
    }
    return ans;
}



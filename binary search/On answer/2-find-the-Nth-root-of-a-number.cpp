// Given two numbers N and M, find the Nth root of M. The Nth root of a number M
// is defined as a number X such that when X is raised to the power of N, it 
// equals M. If the Nth root is not an integer, return -1.
#include <bits/stdc++.h>
using namespace std;    

// brute force approach
// Time Complexity: O(M^(1/N))
// Space Complexity: O(1)
long long func(int b, int exp){
    long long ans = 1;
    long long base = b;
    while(exp > 0){
        if(exp % 2){
            exp--; // if exp is odd, reduce it by 1
            ans *= base; // multiply the base to the answer 
        }
        else{
            exp /= 2; // if exp is even, divide it by 2
            base = base * base;
        }
    }
    return ans; // return the final answer
}
int findNthRoot(int n, int m) {
    for(int i=1;i<=m;i++){
        long long val = func(i, n);
        if(val == m * 1LL) return i; // if i^n equals m, return i
        if(val > m * 1LL) return -1; // if i^n
    }
    return -1; // if no integer root found
}

// binary search appproach
// time: O(log(M))
// space : O(1)

// return 1, if mid^n == m
// return 0, if mid^n < m
// return 2, if mid^n > m
int func2(int mid, int n, int m){
    long long ans = 1;
    for(int i=1;i<=n;i++){
        ans *= mid;
        if(ans > m) return 2;
    }
    if(ans == m) return 1;
    return 0;
}
int NthRoot(int n, int m){
    int low = 1, high = m;
    while(low <= high){
        int mid = low + (high - low)/2;
        int midPower = func2(mid, n, m);
        if(midPower == 1)
            return mid;
        else if(midPower == 0)
            low = mid + 1; // search in the right half
        else
            high = mid - 1;
    }
    return -1;
}
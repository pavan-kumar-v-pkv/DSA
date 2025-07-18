// Given an integer r, return all the values in the rth row (1-indexed) in Pascal's Triangle in correct order.
// In Pascal's triangle:
// The first row has one element with a value of 1.
// Each row has one more element in it than its previous row.
// The value of each element is equal to the sum of the elements directly above it when arranged in a triangle format.
#include <bits/stdc++.h>
using namespace std;

class Solution{
    vector<int> pascalTraingle(int r){
        vector<int> ans(r);
        ans[0] = 1; // first element is always 1
        for(int i=1;i<r;i++){
            ans[i] = (ans[i-1]*(r-i))/i;
        }
        return ans;
    }
};
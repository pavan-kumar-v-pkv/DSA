// Given two integers r and c, return the value at the rth row and cth column (1-indexed) in a Pascal's Triangle.
// In Pascal's triangle:

// The first row has one element with a value of 1.
// Each row has one more element in it than its previous row.
// The value of each element is equal to the sum of the elements directly above it when arranged in a triangle format.
#include <bits/stdc++.h>
using namespace std;    

class Solution{
    public:
    // time: O(C), where C is the number of columns in the row
    // space: O(1)
    int nCr(int n, int r){
        if(r > n-r) return 0; // nCr is not defined for r > n
        if(r == 1) return n;
        int res = 1;
        for(int i=0;i<r;i++){
            res = res * (n-i);
            res = res / (i+1);
        }
        return res;
    }
    int pascalTriangle(int r, int c){
        return nCr(r-1, c-1);
    }
};
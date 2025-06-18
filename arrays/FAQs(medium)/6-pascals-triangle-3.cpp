// Given an integer n, return the first n (1-Indexed) rows of Pascal's triangle.
// In Pascal's triangle:
// The first row has one element with a value of 1.
// Each row has one more element in it than its previous row.
// The value of each element is equal to the sum of the elements directly above it when arranged in a triangle format.
#include <bits/stdc++.h>
using namespace std;    

class Solution{
    // time: O(N^2), where N is the number of rows in Pascal's triangle
    // space: O(N^2), where N is the number of rows in Pascal's
    public:
    vector<int> generateRow(int row){
        long long ans = 1;
        vector<int> res;
        res.push_back(1); // first element is always 1
        for(int col=1;col<row;col++){
            ans = ans*(row-col);
            ans = ans/col;
            res.push_back(ans);
        }
        return res;
    }
    vector<vector<int> > pascalTriangle(int N){
        vector<vector<int> > ans;
        for(int i=1;i<=N;i++){
            vector<int> temp = generateRow(i);
            ans.push_back(temp);
        }
        return ans;
    }
};

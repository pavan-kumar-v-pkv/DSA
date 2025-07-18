// Given a 2D array matrix that is row-wise sorted. The task is to find the 
// median of the given matrix.
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(n*m) + O(n*m*log(n*m))
// space: O(n*m)
int median(vector<vector<int> >& matrix, int m , int n){
    vector<int> lst;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            lst.push_back(matrix[i][j]);
        }
    }
    sort(lst.begin(), lst.end());
    return lst[(m*n)/2];
}

// better approach: binary search
// time: O(n*log(max-min)) + O(n*m)
// space: O(1)
int countLessEqual(vector<vector<int> >& matrix,int m, int n, int x){
    int cnt = 0;
    for(int i=0;i<m;i++){
        cnt += upper_bound(matrix[i].begin(), matrix[i].end(), x) - matrix[i].begin();
    }
    return cnt;
}
int median2(vector<vector<int> >& matrix, int m, int n){
    int low = INT_MAX, high = INT_MIN;
    // point low and high to the minimum and maximum elements in the matrix
    for(int i=0;i<m;i++){
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n-1]);
    }

    int req = (n * m)/2; // required number of elements to find the median
    while(low <= high){
        int mid = low + (high - low)/2;
        int smallEqual = countLessEqual(matrix, m, n, mid);
        if(smallEqual <= req){
            low = mid + 1; // move to the right half, because the median has equal elements on both sides;
            // that equal elements is calulated by required number of elements, we need to find the next greater element
        }
        else{
            high = mid - 1; // move to the left half
        }
    }
    return low; // low will be the median
}
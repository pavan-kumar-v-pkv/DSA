// Given a non-empty grid mat consisting of only 0s and 1s, where all the rows
// are sorted in ascending order, find the index of the row with the maximum 
// number of ones.
// If two rows have the same number of ones, consider the one with a smaller 
// index. If no 1 exists in the matrix, return -1.
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(m * n)
// space: O(1)
int rowWithMax1s(vector<vector<int> >& matrix, int n, int m){
    int cnt_max = 0; // to store the maximum count of 1s
    int row_index = -1; // to store the index of the row with maximum 1s
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<m;j++){
            cnt += matrix[i][j];
        }
        if(cnt > cnt_max){
            cnt_max = cnt;
            row_index = i;
        }
    }
    return row_index;
}

// binary search approach
// time: O(m * log(n))
// space: O(1)
int lowerBound(vector<int>& arr, int n, int x){
    int low = 0, high = n-1;
    int ans = n; // default answer is size of the array
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] >= x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}
int rowWithMax1s2(vector<vector<int> >& matrix, int n, int m){
    int cnt_max = 0; // to store the maximum count of 1s
    int row_index = -1; // to store the index of the row with maximum
    for(int i=0;i<n;i++){
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if(cnt_ones > cnt_max){
            cnt_max = cnt_ones;
            row_index = i;
        }
    }
    return row_index;
}
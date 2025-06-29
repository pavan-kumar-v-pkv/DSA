// Given a 2D array matrix where each row is sorted in ascending order from 
// left to right and each column is sorted in ascending order from top to bottom,
// write an efficient algorithm to search for a specific integer target in the 
// matrix.
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(m * n)
// space: O(1)
bool searchElement(vector<vector<int> >& matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == target)
                return true;
        }
    }
    return false;
}

// better approach: binary search
// time: O(n + log(m))
// space: O(1)
bool binarySearch(vector<int>& arr, int target){
    int n = arr.size();
    int low = 0, high = n-1;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == target){
            return true;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return false;
}
bool searchElement2(vector<vector<int> >& matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0;i<n;i++){
        bool flag = binarySearch(matrix[i], target);
        if(flag)
            return true;
    }
    return false;
}

// optimal approach: binary search in 2D matrix
// time: O(log(m * n))
// space: O(1)
bool searchElement3(vector<vector<int> >& matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0, col = m - 1; // start from the top-right corner
    while(row < n && col >= 0){
        if(matrix[row][col] == target){
            return true;
        }
        else if(matrix[row][col] < target){
            row++; // move down if the current element is less than target
        }
        else {
            col--; // move left if the current element is greater than target
        }
    }
    return false;
}
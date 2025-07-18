// Given a 2-D array mat where the elements of each row are sorted in non-decreasing
// order, and the first element of a row is greater than the last element of the
// previous row (if it exists), and an integer target, determine if the target 
// exists in the given mat or not.
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(m * n)
// space: O(1)
bool searchMatrix(vector<vector<int> >& matrix, int target){
    int n = matrix.size(), m = matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == target)
                return true;
        }
    }
    return false;
}

// better approach: binary search
// time: O(N + log(M))
//space: O(1)
bool binarySearch(vector<int>& arr, int target){
    int n = arr.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == target){
            return true;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
}
bool searchMatrix2(vector<vector<int> >& matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i=0;i<n;i++){
        if(matrix[i][0] <= target && target <= matrix[i][m-1]){
            // return binary_search(matrix[i].begin(), matrix[i].end(), target);
            return binarySearch(matrix[i], target);
        }
    }
    return false;
}

// optimal approach: binary search in 2D matrix
// time: O(log(m * n))
// space: O(1)
bool searchMatrix3(vector<vector<int> >& matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0, high = n*m-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        int row = mid / m; // row index
        int col = mid % m; // column index
        if(matrix[row][col] == target){
            return true;
        }
        else if(matrix[row][col] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return false;
}
// Given a 0-indexed n x m matrix mat where no two adjacent cells are equal, 
// find any peak element mat[i][j] and return the array [i, j].A peak element 
// in a 2D grid is an element that is strictly greater than all of its adjacent 
// neighbours to the left, right, top, and bottom.
// Assume that the entire matrix is surrounded by an outer perimeter with the 
// value -1 in each cell.
// Note: As there can be many peak values, 1 is given as output if the returned 
// index is a peak number, otherwise 0.
#include <bits/stdc++.h>
using namespace std;

// binary search approach
// time: O(n * log(m))
// space: O(1)
int maxElement(vector<vector<int> >& mat, int col){
    int n = mat.size();
    int max_val = INT_MIN;
    int index = -1;
    for(int i=0;i<n;i++){
        if(mat[i][col] > max_val){
            max_val = mat[i][col];
            index = i;
        }
    }
    return index;
}
vector<int> findPeakElement(vector<vector<int> >& mat){
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = m - 1;

    while(low <= high){
        int mid = low + (high - low)/2;
        // find the index of the row with maximum element in the mid column
        int maxRowIndex= maxElement(mat, mid);

        // determine the elements to the left and right of middle element
        int left = mid - 1 >= 0 ? mat[maxRowIndex][mid - 1] : INT_MIN;
        int right = mid + 1 < m ? mat[maxRowIndex][mid + 1] : INT_MIN;

        // check if the middle element is greate than its neighbours
        if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right){
            vector<int> temp = {maxRowIndex, mid};
            return temp;
        }
        else if(left > mat[maxRowIndex][mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    vector<int> temp = {-1, -1}; // return -1 if no peak element found
    return temp;
}

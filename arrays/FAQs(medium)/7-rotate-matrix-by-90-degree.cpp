// Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise.
// The rotation must be done in place, meaning the input 2D matrix must be modified directly.
#include <bits/stdc++.h>
using namespace std;    

class Solution {
    public:
    // brute force approach
    // time: O(N^2)+O(N^2), where N is the number of rows/columns in the matrix
    // space: O(N^2), where N is the number of rows/columns in the matrix
    void rotateMatrix(vector<vector<int> >& matrix) {
        int n = matrix.size();
        vector<vector<int> > rotated(n, vector<int>(n, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                rotated[j][n-i-1] = matrix[i][j];
            }
        }

        // copy the rotated matrix back to the original matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                matrix[i][j] = rotated[i][j]; 
            }
        }
    }
    // optimized approach
    // time: O(N^2), where N is the number of rows/columns in the matrix
    // space: O(1), no extra space is used
    void rotateMatrixOptimized(vector<vector<int> >& matrix) {
        int n = matrix.size();
        // transpose the matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // reverse each row
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

};
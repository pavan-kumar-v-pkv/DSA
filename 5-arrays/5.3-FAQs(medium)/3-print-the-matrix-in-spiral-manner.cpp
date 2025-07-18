// Given an M * N matrix, print the elements in a clockwise spiral manner.
// Return an array with the elements in the order of their appearance when
// printed in a spiral manner.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix)
    {
        vector<int> ans;
        // number of rows
        int row = matrix.size();
        // number of columns
        int col = matrix[0].size();
        int top = 0, left = 0, bottom = row - 1, right = col - 1;

        // traverse the matrix in spiral order
        while (top <= bottom && left <= right)
        {
            // traverse from left to right
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++; // move the top boundary down
            // traverse from top to bottom
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--; // move the right boundary left
            // check if there are still rows left to traverse
            if (top <= bottom)
            {
                // traverse from right to left
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--; // move the bottom boundary up
            }
            // check if there are still columns left to traverse
            if (left <= right)
            {
                // traverse from bottom to top
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++; // move the left boundary right
            }
        }
        return ans;
    }
};

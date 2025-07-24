// Given a m x n binary matrix filled with 0's and 1's, find the largest 
// rectangle containing only 1's and return its area.
#include<bits/stdc++.h>
using namespace std;

// A clever way to approach this problem is by breaking the problem into smaller
//  subproblems using the concept discussed in the problem Largest rectangle in 
//  a histogram. The given matrix can be seen from different ground levels. Each 
//  ground can be treated as a histogram, and the columns of 1s attached from 
//  the ground represent the heights of the bars for the current histogram. 
//  This way the problem boils down to finding the largest rectangle in all the 
//  histograms.

// Now, to find the height of bars for a particular ground level (histogram), 
// traversing the matrix again and again will be inefficient. Instead, the 
// heights of bars can be determined by traversing the matrix only once by 
// using the concept of Prefix Sum.

// Understanding:
// Since the heights of the bars are the main concern, the prefix sum must be 
// calculated column-wise. This will make sure that while traversing in a 
// column-order fashion, the heights are added up. But if in any place, a zero 
// is found, the height of 1s above it will not be considered as there is no 
// contact of continuous 1s with the ground for that particular histogram.

// Time Complexity: O(N*M) (where N and M are the dimensions of the given matrix)
// Filling the prefix sum matrix takes O(N*M) time.
// Every row (of length M) is treated as a histogram for which the largest histogram is found in linear(O(2*M)) time taking overall O(N*M) time.

// Space Complexity: O(N*M)
// The prefix sum array takes up O(N*M) space.
// Finding the largest rectangle in each histogram (of length M) takes O(M) space due to stack.
int largestRectangleArea(vector<int>& heights){
    int n = heights.size();
    stack<int> st;
    int nse, pse;
    int area;
    int maxArea = 0;

    for(int i=0;i<n;i++){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            int ind = st.top();
            st.pop();

            pse = st.empty() ? -1 : st.top();
            nse = i;
            area = heights[ind] * (nse-pse-1);
            maxArea = max(maxArea, area);
        }
        st.push(i);
    }

    while(!st.empty()){
        int ind = st.top();
        st.pop();

        nse = n;
        pse = st.empty() ? -1 : st.top();
        area = heights[ind] * (nse-pse-1);
        maxArea = max(maxArea, area);  
    }
    return maxArea;
}
int maximalAreaOfSubMatrixOfAll(vector<vector<int> >& matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int> > prefixSum(n, vector<int>(m));
    // fill up the prefix sum matrix column wise
    for(int j=0;j<m;j++){
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += matrix[i][j];

            // if there is no base present
            if(matrix[i][j] == 0){
                prefixSum[i][j] = 0;
                sum = 0;
            }
            else{// store the height
                prefixSum[i][j] = sum; 
            }
        }
    }

    int maxArea = 0;
    // traverse different levels of ground (i.e. rows)
    for(int i=0;i<n;i++){
        int area = largestRectangleArea(prefixSum[i]);
        maxArea = max(area, maxArea);
    }

    return maxArea;
}
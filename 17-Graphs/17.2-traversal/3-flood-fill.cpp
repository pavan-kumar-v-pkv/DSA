// An image is represented by a 2-D array of integers, each integer 
// representing the pixel value of the image. Given a coordinate (sr, sc) 
// representing the starting pixel (row and column) of the flood fill, and a 
// pixel value newColor, "flood fill" the image.
// To perform a flood fill, consider the starting pixel, plus any pixels 
// connected 4-directionally to the starting pixel of the same colour as the 
// starting pixel, plus any pixels connected 4-directionally to those pixels 
// (also with the same colour as the starting pixel), and so on. Replace the 
// colour of all of the aforementioned pixels with the newColor.
#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    vector<int> delRow = {-1, 0, +1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    void dfs(int row, int col, vector<vector<int> >& ans, vector<vector<int> >& image, int newColor, int iniColor){
        ans[row][col] = newColor;

        int n = image.size();
        int m = image[0].size();

        for(int i=0;i<4;i++){
            int nr = row + delRow[i];
            int nc = col + delCol[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == iniColor && ans[nr][nc] != newColor){
                dfs(nr, nc, ans, image, newColor, iniColor);
            }
        }
    }
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor){
        // store the initial colour
        int iniColor = image[sr][sc];
        // to store the updated image
        vector<vector<int> > ans = image;

        dfs(sr, sc, ans, image, newColor, iniColor);

        return ans;
    }
};
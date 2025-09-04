// Given a binary grid of N x M. Find the distance of the nearest 1 in the grid
// for each cell.
// The distance is calculated as |i1 - i2| + |j1 - j2|, where i1, j1 are the 
// row number and column number of the current cell, and i2, j2 are the row 
// number and column number of the nearest cell having value 1.

#include<bits/stdc++.h>
using namespace std;

// BFS approach
// time: O(N*M)where N and M are the dimensions of grid
// Space : O(N*M) The visited array and distance matrix will take O(N*M) space each, 
// and the queue will store at maximum of O(N*M) cells (in case of grid 
// having all cells as 1).

class Solution{
    private:
    vector<int> delRow = {-1, 0, +1, 0};
    vector<int> delCol = {0, +1, 0, -1};
    public:
    vector<vector<int> > nearest(vector<vector<int> >& grid){
        // dimensions
        int n = grid.size();
        int m = grid[0].size();

        // visited and distance matrix
        vector<vector<int> > vis(n, vector<int>(m, 0));
        vector<vector<int> > dist(n, vector<int>(m, 0));

        // queue to store the pair, {coordinates, steps}
        queue<pair<pair<int, int>, int> > q;
        
        // traverse the matrix to get initial 1s
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // start BFS if cell contains 1
                if(grid[i][j] == 1){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        // BFS traversal
        // traverse till queue becomes empty
        while(!q.empty()){
            // determine the top of queue
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            // update the distance matrix
            dist[row][col] = steps;

            // traverse the 4 neighbours
            for(int i=0;i<4;i++){
                int nr = row + delRow[i];
                int nc = col + delCol[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0){
                    vis[nr][nc] = 1;
                    q.push({{nr, nc}, steps+1});
                }
            }
        }

        return dist;
    }
};
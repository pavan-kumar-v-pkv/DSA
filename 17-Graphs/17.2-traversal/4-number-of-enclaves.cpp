// Given an N x M binary matrix grid, where 0 represents a sea cell and 1 
// represents a land cell. A move consists of walking from one land cell to 
// another adjacent (4-directionally) land cell or walking off the boundary of 
// the grid. Find the number of land cells in the grid for which we cannot walk 
// off the boundary of the grid in any number of moves.
#include<bits/stdc++.h>
using namespace std;

// time: O(N*M)
// space: O(N*M)
class Solution{
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    void bfs(vector<vector<int> >& grid, queue<pair<int, int> >& q, vector<vector<bool> >& vis){
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr = row + delRow[i];
                int nc = col + delCol[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && !vis[nr][nc]){
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
    int numberOfEnclaves(vector<vector<int> >& grid){
        int n = grid.size();
        int m = grid[0].size();

        // queue for BFS traversal
        queue<pair<int, int> > q;
        // visited array
        vector<vector<bool> > vis(n, vector<bool>(m, false));

        // traverse the grid and add the border land cell to queue
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // if the land cell is at border, add it to queue
                if((i == 0 || i == n- 1 || j == 0 || j == m-1) && grid[i][j] == 1){
                    vis[i][j] = true;
                    q.push({i, j});
                }
            }
        }

        // perform bfs traversal from border land cells
        bfs(grid, q, vis);

        // count to store number of enclaves
        int count = 0;

        // traverse the grid
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // if the cell is a land cell and unvisited, update the count
                if(grid[i][j] == 1 && !vis[i][j])
                    count++;
            }
        }
        return count;
    }
};
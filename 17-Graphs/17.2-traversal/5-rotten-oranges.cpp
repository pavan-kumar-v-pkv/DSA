// Given an n x m grid, where each cell has the following values : 
// 2 - represents a rotten orange
// 1 - represents a Fresh orange
// 0 - represents an Empty Cell
// Every minute, if a fresh orange is adjacent to a rotten orange in 
// 4-direction ( upward, downwards, right, and left ) it becomes rotten. 
// Return the minimum number of minutes required such that none of the cells 
// has a Fresh Orange. If it's not possible, return -1.
#include<bits/stdc++.h>
using namespace std;

class Solution{
    vector<int> delRow = {-1, 0, +1, 0};
    vector<int> delCol = {0, +1, 0, -1};
    int orangesRotting(vector<vector<int> >& grid){
        int n = grid.size();
        int m = grid[0].size();
        /// variable to store time taken to get all oranges rotten
        int time = 0;
        // variable to store total count of oranges
        int total = 0;
        // variable to store count of oranges that are rotten
        int count = 0;
        // queue to perform BFS
        queue<pair<int, int> > q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // if cell contains orage, increment total
                if(grid[i][j] != 0)
                    total++;
                // if cell contains rotten orange, push in queue
                if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        // perform BFS
        while(!q.empty()){
            int k = q.size();
            // update the count of rotten oranges
            count += k;
            // perform BFS
            while(k--){
                int row = q.front().first;
                int col = q.front().second;

                for(int i=0;i<4;i++){
                    int nr = row + delRow[i];
                    int nc = col + delCol[i];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
                        // mark the oranges as rotten, then the time must be incremented
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }

            // if the new oranges are rotten, then the time must be incremented
            if(!q.empty()) time++;
        }

        // if all the oranges are rotten, return the time taken
        if(total == count) return time;

        return -1;
    
    }
};
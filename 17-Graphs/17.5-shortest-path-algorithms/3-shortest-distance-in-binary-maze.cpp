// Given an n x m matrix grid where each cell contains either 0 or 1, 
// determine the shortest distance between a source cell and a destination 
// cell. You can move to an adjacent cell (up, down, left, or right) if that 
// adjacent cell has a value of 1. The path can only be created out of cells 
// containing 1. If the destination cell is not reachable from the source cell, 
// return -1.
#include<bits/stdc++.h>
using namespace std;

// The problem includes finding the shortest path from the source to 
// destination which gives the idea of using a Dijsktra's Algorithm. But 
// since, all the edges are of unit weight, instead of using Dijsktra's 
// algorithm, a simple BFS traversal will get the job done.

// time: O(N*M)
// space: O(N*M)
class Solution{
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, -1, 0, 1};

    int shortestPath(vector<vector<int>>& grid, pair<int, int> source, pair<int, int> destination){
        // edge case
        if(source.first == destination.first && source.second == destination.second)
            return 0;

        // queue => {dist, {coordinates of cell}}
        queue<pair<int, pair<int, int>>> q;

        // dimension of grid
        int n = grid.size();
        int m = grid[0].size();

        // distnace matrix
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;

        q.push({0, {source.first, source.second}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for(int i=0;i<4;i++){
                int nr = row + delrow[i];
                int nc = col + delcol[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && dis + 1 < dist[nr][nc]){
                    dist[nr][nc] = 1 + dis;

                    if(nr == destination.first && nc == destination.second)
                        return dis + 1;

                    q.push({1+dis, {nr, nc}});
                }
            }
        }
        return -1;
    }
};

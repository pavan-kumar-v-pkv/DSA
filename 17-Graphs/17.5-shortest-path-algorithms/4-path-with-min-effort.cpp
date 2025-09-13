// A hiker is preparing for an upcoming hike. Given heights, a 2D array of size 
// rows x columns, where heights[row][col] represents the height of the cell 
// (row, col). The hiker is situated in the top-left cell, (0, 0), and hopes to 
// travel to the bottom-right cell, (rows-1, columns-1) (i.e.,0-indexed). He 
// can move up, down, left, or right. He wishes to find a route that requires 
// the minimum effort.
// A route's effort is the maximum absolute difference in heights between two 
// consecutive cells of the route.
#include<bits/stdc++.h>
using namespace std;

# define P pair<int, pair<int, int> >

// The problem resembles a pathfinding problem in a weighted graph, where we 
// need to find a path with minimal maximum effort. We already know, 
// traditional shortest path algorithms like Dijkstra's Algorithm are used to 
// find the path with the minimum total cost. This gives an idea of using 
// Dijkstra's algorithm to get to the solution. But there will be definitely 
// some modifications needed.

// Adapting Dijkstra's algorithm:
// * By slightly modifying the algorithm, it can be adapted to minimize the 
// maximum effort:
// * Instead of accumulating total distances, the maximum effort encountered so 
// far can be tracked.
// * And the priority queue (min-heap) can be used to store the pair 
// {difference, {row of cell, column of cell}} which will help to always 
// expand the least difference (effort) path first.

// time: O(ElogV) ~ O(N*Mlog(N*M))
// space: O(N*M)
class Solution {
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, -1, 0, 1};

    int minimumEffort(vector<vector<int>>& heights){
        int n = heights.size();
        int m = heights[0].size();

        // to store the maximum difference
        vector<vector<int> > maxDiff(n, vector<int>(m, 1e9));

        // min-heap: {diff, {row, col}}
        priority_queue<P, vector<P>, greater<P>> pq;

        maxDiff[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            // if the target cell is reached, return the difference
            if(row == n-1 && col == m-1)
                return diff;

            // traverse it's neighbours
            for(int i=0;i<4;i++){
                int nr = row + delrow[i];
                int nc = col + delcol[i];

                if(nr >= 0 && nr < n && nc >= 0 & nc < m){
                    int currDiff = abs(heights[nr][nc] - heights[row][col]);
                    if(max(currDiff, diff) < maxDiff[nr][nc]){
                        maxDiff[nr][nc] = max(currDiff, diff);
                        pq.push({max(currDiff, diff), {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};
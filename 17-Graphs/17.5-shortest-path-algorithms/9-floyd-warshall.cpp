// Given a graph of V vertices numbered from 0 to V-1. Find the shortest 
// distances between every pair of vertices in a given edge-weighted directed 
// graph. The graph is represented as an adjacency matrix of size n x n. 
// Matrix[i][j] denotes the weight of the edge from i to j. If matrix[i][j]=-1, 
// it means there is no edge from i to j.
#include<bits/stdc++.h>
using namespace std;

// In the problem, it is required to find the shortest distance between every 
// pair of vertices which can be seen as finding the shortest distance of 
// every node from all nodes (multiple sources). There are already algorithms 
// namely Dijkstra's Algorithm and Bellman Ford Algorithm but they are 
// single-source shortest path algorithms. But here since multiple sources are 
// considered, the FLoyd Warshall algorithm will come into picture.

// The Floyd Warshall algorithm is a multi-source shortest path algorithm and 
// it helps to detect negative cycles (a cycle where sum of all weights is 
// negative) as well. The shortest path between node u and v means the 
// path(from u to v) for which the sum of the edge weights is minimum.

// The Floyd Warshall algorithm is nothing but the brute force approach of 
// checking every possible path from node u to node v (via some node k) to 
// figure out the shortest path from node u to node v.

// time: O(N^3)
// space: O(N^2)
class Solution{
    public:
    void shortest_distance(vector<vector<int>> &matrix){
        int n = matrix.size();

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    // if k not an intermediate node, skip the iteratipn
                    if(matrix[i][j] == -1 || matrix[k][j] == -1)
                        continue;

                    // if no direct edge from i to j is present
                    if(matrix[i][j] == -1){
                        // update the distance
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                    // else update the distance to minimum of both paths
                    else{
                        matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
                    }
                }
            }
        }
    }
};


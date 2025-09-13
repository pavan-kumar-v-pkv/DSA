// Given a weighted and directed graph of V vertices and E edges. An edge is 
// represented as [ai, bi, wi], meaning there is a directed edge from ai to bi 
// having weight wi. Find the shortest distance of all the vertices from the 
// source vertex S. If a vertex can't be reached from the S then mark the 
// distance as 109.

// If the graph contains a negative cycle then return -1 in a list.
#include<bits/stdc++.h>
using namespace std;

// Intuition:
// The first thing that comes to mind when the requirement is to find shortest 
// distance of all vertices from the source vertex S is Dijkstra's Algorithm. 
// But this problem suggests that graphs can contain negative edges for which 
// the Dijkstra's algorithm will fail.

// To solve such issue, the Bellman Ford Algorithm will come in picture. It 
// not only works when the graph contains negative edges, but also helps 
// identify if the graph contains negative cycle (a cycle where sum of all 
// weights is negative). The algorithm finds the minimum distance to reach 
// any node by performing N-1 times Edge Relaxation (where N is the number 
// of nodes in the graph). Though Bellman Ford Algorithm is more versatile, 
// it is slower when compared to Dijkstra's Algorithm.

// time: O(V*E)
// space: O(V)

class Solution{
    public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S){
        // to store the distance
        vector<int> dist(V, 1e9);
        // distance of source from itself is zero
        dist[S] = 0;
        // repeat for V-1 time
        for(int i=0;i<V-1;i++){
            for(auto it: edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                // edge relaxation
                if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // an extra relaxation to check if the graph consists of a negative cycle
        for(auto it: edges){
            int u = it[0];
            int v = it[v];
            int wt = it[2];
            if(dist[u] != 1e9 && dist[u]+wt < dist[v]){
                return {-1};
            }
        }
        return dist;
    }
};
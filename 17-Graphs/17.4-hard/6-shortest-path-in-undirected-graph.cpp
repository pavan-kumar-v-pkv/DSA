// Given a Undirected Graph of N vertices from 0 to N-1 and M edges and a 2D 
// Integer array edges, where there is a edge from vertex edges[i][0] to vertex 
// edges[i][1] of unit weight.

// Find the shortest path from the source to all other nodes in this graph. 
// In this problem statement, we have assumed the source vertex to be ‘0’. If 
// a vertex is unreachable from the source node, then return -1 for that vertex.
#include<bits/stdc++.h>
using namespace std;

// Since the question is asking for shortest path to every node, let's 
// try using simple BFS traversal starting from source node (node 0) for the 
// given graph:
// time: O(N+M)
// space: O(N+M)
class Solution{
    void bfs(int src, vector<int> adj[], vector<int>& dist){
        dist[src] = 0;
        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: adj[node]){
                // if a shorted distance is found
                if(dist[node] + 1< dist[it]){
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
            }
        }
    }
    vector<int> shortestpath(vector<vector<int>>& edges, int N, int M){
        vector<int> adj[N];
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(N, 1e9);
        bfs(0, adj, dist);

        for(int i=0;i<N;i++){
            if(dist[i] == 1e9)
                dist[i] = -1;
        }

        return dist;
    }
};
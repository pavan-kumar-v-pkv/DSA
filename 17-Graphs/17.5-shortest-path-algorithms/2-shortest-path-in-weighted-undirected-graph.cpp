// Given a weighted undirected graph having n vertices numbered from 1 to n and 
// m edges describing there are edges, where edges[i]=[ai,bi,wi], representing 
// an edge from vertex ai to bi with weight wi.

// Find the shortest path between the vertex 1 and the vertex n and if path 
// does not exist then return a list consisting of only -1.

// If there exists a path, then return a list whose first element is the weight 
// of the path and the remaining elements represent the shortest path from 
// vertex 1 to vertex n.
#include<bits/stdc++.h>
using namespace std;

#define P pair<int, int>

// Intuition:
// Since the problem requires the shortest path from source node(node 1) to 
// node n, the first thought that must come to the mind is to use Dijkstra's
// Algorithm.

// Modification:
// Since the shortest path needs from source node(node 1) to node n is 
// required, for every node possible, its parent node must be stored via which 
// the node is reachable through minimum distance. Hence, in the Dijkstra's 
// Algorithm, a slight modification can be done where whenever an edge 
// relaxation happens for a particular node, it's parent node is stored in an 
// array.

// time: O((N+M)*logN)
// space: O(N)
class Solution{
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges){
        // adjacecy list to store graph
        vector<pair<int, int>> adj[n+1];
        // adding the edges to the graph
        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // priority queue to implement Dijkstra algo
        priority_queue<P, vector<P>, greater<P>> pq;
        // distance array
        vector<int> dist(n+1, 1e9);
        // parent array
        vector<int> parent(n+1);
        // marking each node as its own parent initially
        for(int i=1;i<=n;i++)
            parent[i] = i;

        // distance of source node to itself is 0
        dist[1] = 0;
        pq.push({0, 1});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            int dis = it.first;

            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;

                if(dis + edgeWt < dist[adjNode]){
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                    // update the parent of the adjNode to the recent node where it came from
                    parent[adjNode] = node;
                }
            }
        }
        // if distance to the node could not be found, return an array containing -1
        if(dist[n] == 1e9){
            return {-1};
        }

        vector<int> path;
        int node = n;
        // iterate backwards from destination to source through the parent array
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);

        reverse(path.begin(), path.end());
        // add the path weight in the beginning
        path.insert(path.begin(), dist[n]);

        return path;
    }
};

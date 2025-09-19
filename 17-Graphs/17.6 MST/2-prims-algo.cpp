// You are given a weighted, undirected, and connected graph with V vertices numbered from 0 to V-1.
// The graph is provided in the form of an adjacency list, where each entry adj[u] contains a list of pairs [v, w], representing an edge between vertex u and vertex v with weight w.
// Find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. 
// A minimum spanning tree (MST) or minimum weight spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.
// Note : The input to the function in code editor is giving in form of adjacency list.
#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(ElogE) (where E is the number of edges in the graph)
// In the worst case, the min-heap will store all the E edges, and insertion operation on the min-heap takes O(logE) time taking overall O(ElogE) time.

// Space Complexity: O(E + V) (where V is the number of nodes in the graph)
// The min-heap will store all edges in worst-case taking O(E) space and the visited array takes O(V) space.

#define P pair<int, int>

class Solution{
public:
    int minSpanningTree(int V, vector<vector<int>> adj[]){
        // min heap to store pair of {edge-weight, node}
        priority_queue<P, vector<P>, greater<P>> pq;
        // visited array
        vector<int> visited(V, 0);
        // push any arbitrary initial node
        pq.push({0, 0});
        // to store the weight of MST
        int sum = 0;
        // until the priority queue is not empty
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int node = p.second;
            int wt = p.first;

            // if the node is already visited, skip the iteration
            if(visited[node] == 1) continue;
            // otherwise, mark the node as visited
            visited[node] = 1;
            // update the weight
            sum += wt;
            // traverse all the edges of the node
            for(auto it: adj[node]){
                // get the adjacent node
                int adjNode = it[0];
                int edgeWt = it[1];
                // add the pair to min-heap if the node is not visited already
                if(visited[adjNode] == 0){
                    pq.push({edgeWt, adjNode});
                }
            }
        }
        return sum;
        
    }
};
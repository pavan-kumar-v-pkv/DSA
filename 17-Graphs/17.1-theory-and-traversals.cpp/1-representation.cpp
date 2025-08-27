#include<bits/stdc++.h>
using namespace std;

int main(){
    // taking the input
    int n, m;
    cin >> n >> m;

    // 1. adjacency matrix to store the graph
    int adj[n+1][n+1];

    // add all the edges in the graph
    for(int i=0;i<m;i++){
        // taking the input
        int u, v;
        cin >> u >> v;
        // adding the edges, in case of undirected graph
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // 2. adjacency list for undirected graph
    // space: O(2*E)
    vector<int> adjList[n+1];
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        // adding the edges
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return 0;
}
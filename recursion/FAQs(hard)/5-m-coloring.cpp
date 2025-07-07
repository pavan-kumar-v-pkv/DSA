// Given an integer M and an undirected graph with N vertices and E edges. The
// goal is to determine whether the graph can be coloured with a maximum of M 
// colors so that no two of its adjacent vertices have the same colour applied 
// to them.
// In this context, colouring a graph refers to giving each vertex a different 
// colour. If the colouring of vertices is possible then return true, otherwise 
// return false.
#include <bits/stdc++.h>
using namespace std;

// Function to check if the graph can be coloured with M colours
// time: O(M^N * N) where M is the number of colours and N is the number of vertices
// space: O(N) for adjacency list and recursion stack
bool isSafe(int color, int node, vector<int>& colors, vector<int> adj[]){
    // check adjacent nodes to see if any of them have the same colour
    for(int i=0;i<adj[node].size();i++){
        // if adjacent node is coloured with the same colour, return false
        if(colors[adj[node][i]] == color)
            return false;   
    }
    return true;
}
bool solve(int node, int m, int n, vector<int>& colors, vector<int> adj[]){
    if(node == n){
        return true; // all nodes are coloured successfully
    }

    // try to colour the current node with each colour from 1 to m
    for(int color = 1;color<=m;color++){
        // check if it is safe to colour the node with colour i
        if(isSafe(color, node, colors, adj)){
            colors[node] = color; // colour the node
            // recursively try to colour the next node
            if(solve(node+1, m, n, colors, adj))
                return true; // if successful, return true
            colors[node] = 0; // backtrack: uncolour the node
        }
    }
    return false; // if no colour can be assigned, return false
}
bool graphColoring(vector<vector<int> >& edges, int m , int n){
    // adjacency list representation of the graph
    vector<int> adj[n];
    // build the graph from edges
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    // initialise the colours to 0 (uncolored)
    vector<int> colors(n, 0);
    // start solving from the first node
    return solve(0, m, n, colors, adj);
}


// You are given a directed graph with V vertices, numbered from 0 to V − 1, and its adjacency list Adj, where 
// Adj[i] contains all vertices j such that there is a directed edge from vertex i to vertex j.

// Your task is to find the number of strongly connected components (SCCs) in the graph.
#include<bits/stdc++.h>
using namespace std;

// What is meant by Strongly Connected Component (SCC)?
// A component is called a Strongly Connected Component(SCC) only if for every possible pair of vertices (u, v) 
// inside that component, u is reachable from v and v is reachable from u.
// Note: Strongly connected components(SCC) are only valid for directed graphs.

// Kosaraju's Algorithm:
// 1. Sort all the nodes according to their finishing time: Perform a DFS call to sort the nodes based on their 
// finishing time and store them in a stack.
// 2. Reverse all the edges of the entire graph: Create a new graph where all the edges of the original graph 
// will be reversed.
// 3. Perform the DFS and count the number of different DFS calls to get the number of SCC: Start DFS traversal 
// on the reversed graph from the node which is on the top of the stack and continue until the stack becomes empty. 
// For each DFS call, the counter representing the number of SCCs can be incremented by 1.
class Solution{
    // function to perform DFS for storing the nodes in stack based on their finishing time
    void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st){
        // mark the node as visited
        vis[node] = 1;

        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }
    // helper function to perform DFS for finding number of SCCs
    void helperDFS(int node, vector<int>& vis, vector<int> adjT[]){
        vis[node] = 1;

        for(auto it: adjT[node]){
            if(!vis[it]){
                helperDFS(it, vis, adjT);
            }
        }
    }
public:
    int kosaraju(int V, vector<int> adj[]){
        // visited array
        vector<int> vis(V, 0);
        // stack 
        stack<int> st;
        // 1. perform initial DFS to store the nodes in stack based on their finishing time
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        // 2. to store the reversed graph
        vector<int> adjT[V];
        // reverse all the edges of orginal graph to the reversed graph
        for(int i=0;i<V;i++){
            // mark the node as unvisited
            vis[i] = 0;
            // add the reverse edge
            for(auto it: adj[i]){
                adjT[it].push_back(i);
            }
        }

        
        // 3. start DFS call from every unvisted node based on their finishing time
        // to store count of the SCCs
        int cnt = 0;
        while(!st.empty()){
            // get the node
            int node = st.top();
            st.pop();

            // if not visited
            if(!vis[node]){
                cnt += 1;
                helperDFS(node, vis, adjT);
            }
        }

        return cnt;
    }
};
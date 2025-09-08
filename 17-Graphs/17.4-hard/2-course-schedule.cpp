// There are a total of N tasks, labeled from 0 to N-1. Given an array arr 
// where arr[i] = [a, b] indicates that you must take course b first if you 
// want to take course a. Find if it is possible to finish all tasks.
#include<bits/stdc++.h>
using namespace std;

// The problem suggests that some courses must be completed before other 
// courses. This is analogous to Topological Sort Algorithm in graph which 
// helps to find a ordering where a node must come come before other nodes 
// in the ordering.
// Hence, the courses can be represented as nodes of graphs and dependencies 
// of courses can be shown as edges.

// Now, For the graph formed, if the Topological sort can be found containing 
// all the nodes (courses), all the courses can be completed in the order 
// returned by topological sort. Else it is not possible to complete all the 
// courses.

// time: O(V+E)
// space: O(V+E)
class Solution {
private:
    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int> indegree(V, 0);
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        // to store the result
        vector<int> ans;
        queue<int> q;

        for(int i=0;i<V;i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }

        return ans;
    }
public:
    bool canFinish(int N, vector<vector<int>> arr){
        // to store the graph
        vector<int> adj[N];
        // for the graph
        for(auto it: arr){
            int u = it[0];
            int v = it[1];
            // v->u
            adj[v].push_back(u);
        }

        // get the topological ordering of graph
        vector<int> topo = topoSort(N, adj);
        // if it doesn't contain all nodes, return false
        if(topo.size() < N) return false;

        return true;
    }
};
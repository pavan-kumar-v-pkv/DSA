// There are a total of N tasks, labeled from 0 to N-1. Given an array arr 
// where arr[i] = [a, b] indicates that you must take course b first if you 
// want to take course a. Find the order of tasks you should pick to finish 
// all tasks.

// If no such ordering exists, return an empty array.

// Since multiple valid answers are possible, the final output will be 1 if 
// your solution is correct, otherwise 0.
#include<bits/stdc++.h>
using namespace std;

// This problem is a continuation of the problem Course Schedule-I. Just the
// only difference here is that instead of determining whether the tasks can 
// be finished or not, the problem requires us to find out the ordering of 
// tasks so that all the tasks can be finished. If no such ordering is 
// possible, an empty list can be returned.

// time: O(V+E)
// space: O(V+E)
class Solution {
    vector<int> topoSort(int V, vector<int> adj[]){
        
        vector<int> indegree(V, 0);
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        vector<int> ans;
        queue<int> q;
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        
        return ans;
    }
    public: vector < int > findOrder(int n, vector < vector < int >> arr) {
        vector<int> adj[n];
        for(auto it: arr){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        
        vector<int> result = topoSort(n, adj);
        if(result.size() < n)
            return {};
            
        return result;
        
    }
};


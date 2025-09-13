// A city consists of n intersections numbered from 0 to n - 1 with 
// bi-directional roads between some intersections. The inputs are generated 
// such that one can reach any intersection from any other intersection and 
// that there is at most one road between any two intersections.

// Given an integer n and a 2D integer array ‘roads’ where 
// roads[i] = [ui, vi, timei] means that there is a road between intersections 
// ui and vi that takes timei minutes to travel. Determine the number of ways 
// to travel from intersection 0 to intersection n - 1 in the shortest amount 
// of time.

// Since the answer may be large, return it modulo 109 + 7.
#include<bits/stdc++.h>
using namespace std;

// We are already aware of Dijkstra's algorithm which can help us find the 
// shortest path (path taking shortest time) from source to destination node. 
// The only change required to get to the answer will be to add up the number 
// of ways to reach a node (in shortest time).

// time:O(M*logN) A simple Dijkstra's algorithm is used which takes 
// O(E*logV) time (where V and E represents the number of nodes and edges in 
// the graph respectively).
// Space Complexity: O(N)
#define P pair<long long, int>

class Solution{
    int countPaths(int n, vector<vector<int>>& roads){
        int mod = 1e9+7;

        // to store the graph
        vector<pair<int, int>> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});   
        }

        // array to store the minimum time to get to nodes
        vector<long long> minTime(n, LLONG_MAX);
        // to store the number of ways to reach nodes
        vector<int> ways(n, 0);
        // priority queue: {time, node}
        priority_queue<P, vector<P>, greater<P>> pq;

        minTime[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            long long time = p.first;
            int node = p.second;

            // traverse its neighbours
            for(auto it: adj[node]){
                int adjNode = it.first;
                int travelTime = it.second;

                // if the current time taken is less than earlier known time to reach adjacent node
                if(time + travelTime < minTime[adjNode]){
                    // update
                    minTime[adjNode] = time + travelTime;
                    // update the number of ways
                    ways[adjNode] = ways[node];
                    // add the new element in pq
                    pq.push({minTime[adjNode], adjNode});
                }
                // else if the current time take is same as earlier known time to reach the adjacent node
                else if(minTime[adjNode] == time + travelTime){
                    // update the number of ways to reach the adjacent nodes
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};


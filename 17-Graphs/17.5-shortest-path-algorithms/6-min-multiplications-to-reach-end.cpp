// Given start, end, and an array arr of n numbers. At each step, the start is 
// multiplied by any number in the array and then a mod operation with 100000 
// is done to get the new start.

// Find the minimum steps in which the end can be achieved starting from the 
// start. If it is not possible to reach the end, then return -1.
#include<bits/stdc++.h>
using namespace std;

// Intuition:

// How to identify this as a problem on Graphs?
// When dealing with problems that involve transforming one value to another 
// through a series of operations, it's helpful to think of the problem as a 
// graph because:
// * Node Representation: Each possible value of start can be considered a 
// node (or start) in a graph.
// * Transitions as Edges: The operations (multiplying by any number in the 
// array and taking modulo 100000) represent transitions (or edges) between 
// these states.
// * Path Finding: The goal is to find the shortest sequence of operations 
// (steps) that transform start into end. This is analogous to finding the 
// shortest path between two nodes in a graph.
// Once it is clear, this problem boils down to finding Shortest path in 
// undirected graph with unit weights.

// // time: O(100000*N) (where N is the length of given array)
// A simple BFS traversal is performed taking O(V+E) time, where V represents 
// nodes (which can be 100000 in the worst case) and E represents the number 
// of edges (transitions) (which can be 100000*N, since for every value, N 
// edges are formed). This makes the overall time complexity as O(100000*N).
// space:O(100000*N)
// Queue space will store all the transitions possible in worst-case resulting 
// in O(100000*N) space.

#define P pair<int, int>

class Solution{
    public:
    int minimumMultiplications(vector<int>& arr, int start, int end){
        // base case
        if(start == end) return 0;

        int n = arr.size();
        int mod = 100000;
        // array to store the minimum steps (distance array)
        vector<int> minSteps(1e5, INT_MAX);

        // dijkstra's algo
        // {steps, val}
        queue<P> q;
        q.push({0, start});
        minSteps[start] = 0;

        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int steps = p.first;
            int val = p.second;

            for(int i=0;i<n;i++){
                // valur of neighbouring node
                int num = (val * arr[i]) % mod;
                // if end is reached, return steps taken
                if(num == end) return steps+1;
                // check if the current steps taken is less than earlier known steps
                if(steps + 1 < minSteps[num]){
                    // update it
                    minSteps[num] = steps+1;
                    // insert the pair in queue
                    q.push({steps+1, num});
                }
            }
        }
        return -1;
    }
};





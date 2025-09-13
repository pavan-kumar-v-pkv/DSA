// There are n cities and m edges connected by some number of flights. Given an 
// array of flights where flights[i] = [ fromi, toi, pricei] indicates that 
// there is a flight from city fromi to city toi with cost pricei. Given three 
// integers src, dst, and k, and return the cheapest price from src to dst with 
// at most k stops. If there is no such route, return -1.
#include<bits/stdc++.h>
using namespace std;
# define P pair<int, pair<int, int>>

//Intuition:
// Since the problem includes finding the cheapest flight to reach from source 
// to destination, the first thought that must come to the mind is to use 
// Dijkstra's Algorithm. But there is a restriction mentioned on the number of 
// stops taken to reach the destination, due to which some modifications need 
// to be done in Dijkstra's algorithm to obtain the result.
// It is known that Dijkstra's algorithm is implemented using Min-heap 
// (priority queue) data structure. For current problem, there are two things 
// related to a node that must be stored in priority queue:

// * Distance to reach the node.
// * Stops taken to reach the node.

// Now the question arises which one must be given priority in the priority 
// queue.

// Understanding how to store elements in priority queue:
// * While storing the elements, if priority is given to minimum distance 
// first then after a few iterations, it can be seen that the algorithm will 
// halt when number of stops could not exceed.
// * It may result in a wrong answer as it will prevent the algorithm to 
// explore those paths which have more cost but fewer stops that the current 
// answer.
// * To prevent this issue, the elements can be stored in terms of the 
// minimum number of stops in the priority queue so that when the algorithm 
// halts, it gives the minimum cost within limits.

// Choosing better data structure to improve complexity:
// * It was clear till now that everything will be stored/ordered in terms of 
// number of stops. But the stops will always increase monotonically 
// (increasing by 1). So the actual significance of using a Min-heap data 
// strucute here in Dijkstra's algorithm fades away. Hence, a simple Queue 
// data structure can be used to avoid the additional logarithmic factor in 
// the complexity (caused by the insertion/deletion operation in Min-Heap data 
// structure).

// time: O((N+M)*K)
// space: O(M+N*K)
class Solution {
public:
    int cheapestFlight(int n, vector<vector<int>>& flights, int src, int dest, int k){
        // to store the graph
        vector<pair<int, int>> adj[n];
        // adding edges to the graph
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        // to store the minimum distance
        vector<int> minDist(n, 1e9);
        minDist[src] = 0;
        // queue storing the elements of the form {stops, {node, dist}}
        queue<P> q;
        q.push({0, {src, 0}});

        while(!q.empty()){
            auto p = q.front();
            q.pop();


            int stops = p.first;
            int node = p.second.first;
            int dist = p.second.second;

            // if the number of stops exceed k, skip and move to the next element
            if(stops > k) continue;

            // traverse all the neighbours
            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;

                // if the tentative distance to reach the adjacent node is smallet than the known distance
                // and number of stops doesn't exceed k
                if(dist + edgeWt < minDist[adjNode] && stops <= k){
                    minDist[adjNode] = dist + edgeWt;
                    q.push({stops+1, {adjNode, dist+edgeWt}});
                }
            }
        }

        // if the destination is unreachable, return -1
        if(minDist[dest] == 1e9)
            return -1;

        return minDist[dest];
    }
};
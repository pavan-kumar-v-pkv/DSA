// There are n cities numbered from 0 to n-1. Given the 
// array edges where edges[i] = [fromi, toi,weighti] represents a bidirectional 
// and weighted edge between cities fromi and toi, and given the integer 
// distance Threshold. Find out a city with the smallest number of cities that 
// are reachable through some path and whose distance is at most Threshold 
// Distance.

// If there are multiple such cities, our answer will be the city with the 
// greatest number.
#include<bits/stdc++.h>
using namespace std;

// using floyd warshall algo
// time: O(N^3)
// space: O(N^2)

int findCity(int n, int m, vector<vector<int>>& edges, int threshold){
    // adjacency matrix
    vector<vector<int>> adjMat(n, vector<int>(n, 1e9));
    for(auto it: edges){
        adjMat[it[0]][it[1]] = it[2];
        adjMat[it[1]][it[0]] = it[2];
    }

    // using floyd warshall algo
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k]+adjMat[k][j]);
            }
        }
    }

    // to store the min count of neighbours
    int minCount = 1e9;
    // to store the answer city
    int ans;
    for(int city=0;city<n;city++){
        int cnt = 0;
        for(int adjCity=0;adjCity<n;adjCity++){
            if(city != adjCity && adjMat[city][adjCity] <= threshold){
                cnt++;
            }
        }

        if(cnt < minCount){
            minCount = cnt;
            ans = city;
        }
        else if(cnt == minCount){
            ans = city;
        }
    }
    return ans;
}
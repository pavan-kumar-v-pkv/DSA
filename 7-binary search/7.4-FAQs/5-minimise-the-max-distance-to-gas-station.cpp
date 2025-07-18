// Given a sorted array arr of size n, containing integer positions of n gas 
// stations on the X-axis, and an integer k, place k new gas stations on the 
// X-axis. The new gas stations can be placed anywhere on the non-negative side 
// of the X-axis, including non-integer positions. Let dist be the maximum 
// distance between adjacent gas stations after adding the k new gas stations. 
// Find the minimum value of dist.
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(n * k) + O(n)
// space: O(n-1)
long double minimiseMaxDistance(vector<int>& arr, int k){
    int n = arr.size();
    vector<int> howMany(n-1, 0);
    //pick and place k gas stations
    for(int gasStations=1;gasStations<=k;gasStations++){
        // find the maximum distance between adjacent gas stations and insert a new gas station
        long double maxSection = -1;
        int maxIndex = -1;
        for(int i=0;i<n-1;i++){
            long double diff = arr[i+1] - arr[i];
            long double sectionLength = diff / (long double) (howMany[i] + 1);
            if(sectionLength > maxSection){
                maxSection = sectionLength;
                maxIndex = i;
            }
        }
        howMany[maxIndex]++;
    }
    // find the maximum distance between adjacent gas stations
    long double maxDistance = -1;
    for(int i=0;i<n-1;i++){
        long double diff = arr[i+1] - arr[i];
        long double sectionLength = diff / (long double) (howMany[i] + 1);
        maxDistance = max(maxDistance, sectionLength);  
    }
    return maxDistance;
}

// better approach: using heap
// time: O(n * log(n)) + O(k * log(n))
// space: O(n-1) + O(n-1)
long double minimiseMaxDistance2(vector<int>& arr, int k){
    int n = arr.size();
    vector<int> howMany(n-1, 0);
    priority_queue<pair<long double, int> > pq; // max heap
    // initialize the heap with the distances between adjacent gas stations
    for(int i=0;i<n-1;i++){
        long double diff = arr[i+1] - arr[i];
        pq.push(make_pair(diff, i));
    }
    
    // pick and place k gas stations
    for(int gasStations=1;gasStations<=k;gasStations++){
        auto [maxSection, maxIndex] = pq.top();
        pq.pop();
        // insert a new gas station in the section with the maximum distance
        howMany[maxIndex]++;
        long double iniDiff = arr[maxIndex+1] - arr[maxIndex];
        long double newSectionLength = iniDiff / (long double) (howMany[maxIndex] + 1);
        pq.push(make_pair(newSectionLength, maxIndex));
    }
    
    // find the maximum distance between adjacent gas stations
    return pq.top().first;
}
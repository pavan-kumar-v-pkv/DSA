// Given the arrival and departure times of all trains reaching a particular 
// railway station, determine the minimum number of platforms required so that 
// no train is kept waiting. Consider all trains arrive and depart on the same 
// day.
// In any particular instance, the same platform cannot be used for both the 
// departure of one train and the arrival of another train, necessitating the 
// use of different platforms in such cases.
#include<bits/stdc++.h>
using namespace std;    

// time: O(NlogN) where N is the number of trains
// space: O(1) for constant space usage
int findPlatforms(vector<int>& arrival, vector<int>& departure){
    int n = arrival.size();
    // sort the arrival and departure times
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int ans = 1;
    int count = 1; // count of platforms needed
    int i=1, j=0; // pointers for arrival and departure arrays

    while(i<n && j<n){
        if(arrival[i] <= departure[j]){
            count++; // a new train arrives, increment platform count
            ans = max(count, ans); // update the maximum platforms needed
            i++; // move to the next arrival
        }
        else{
            count--; // a train departs, decrement platform count
            j++; // move to the next departure
        }
    }
    return ans; // return the maximum number of platforms needed    
}  


// A software engineer is tasked with using the shortest job first (SJF) policy 
// to calculate the average waiting time for each process. The shortest job 
// first also known as shortest job next (SJN) scheduling policy selects the 
// waiting process with the least execution time to run next.
// Given an array of n integers representing the burst times of processes, 
// determine the average waiting time for all processes and return the closest 
// whole number that is less than or equal to the result.
#include<bits/stdc++.h>
using namespace std;    

// time: O(NlogN + N) where N is the length of the processes array
// space: O(1) since we are using a constant amount of extra space
long long solve(vector<int>& bt){
    // sort jobs in ascending order
    sort(bt.begin(), bt.end());
    // initialize waiting time and total waiting time
    long long waitingTime = 0;
    // initialize total time taken
    long long totalTime = 0;
    int n = bt.size();

    for(int i=0;i<n;i++){
        waitingTime += totalTime;
        totalTime += bt[i]; // add the burst time of the current process
    }

    return waitingTime / n; // return the average waiting time
}

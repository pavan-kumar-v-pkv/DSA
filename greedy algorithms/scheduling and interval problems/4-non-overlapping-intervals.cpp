// Given an array of N intervals in the form of (start[i], end[i]), where 
// start[i] is the starting point of the interval and end[i] is the ending 
// point of the interval, return the minimum number of intervals that need to 
// be removed to make the remaining intervals non-overlapping.
#include<bits/stdc++.h>
using namespace std;

// time: O(NlogN) where N is the number of intervals
// space: O(1) for constant space usage
bool static comp(vector<int>& a, vector<int>& b){
    // sort based on end time
    return a[1] < b[1];
}
int maximumNonOverlappingIntervals(vector<vector<int> >& intervals){
    // sort the intervals based on their ending time
    sort(intervals.begin(), intervals.end(), comp);
    // get total number of intervals
    int n = intervals.size();
    // initialise counter
    int cnt = 1;
    // keep track of the previous interval's end time
    int prevEnd = intervals[0][1];
    // iterate through the intervals starting from the second one
    for(int i=1;i<n;i++){
        // if the current interval's start time is greater than or equal to 
        // the previous interval's end time, it means they do not overlap
        if(intervals[i][0] >= prevEnd){
            cnt++; // increment the count of non-overlapping intervals
            prevEnd = intervals[i][1]; // update the previous end time
        }
    }
    // return the total number of intervals minus the count of non-overlapping
    // intervals to get the minimum number of intervals that need to be removed
    return n - cnt;
}
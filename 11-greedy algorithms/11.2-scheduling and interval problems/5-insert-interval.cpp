// Given a 2D array Intervals, where Intervals[i] = [start[i], end[i]] 
// represents the start and end of the ith interval, the array represents 
// non-overlapping intervals sorted in ascending order by start[i]. 
// Given another array newInterval, where newInterval = [start, end] represents 
// the start and end of another interval, insert newInterval into Intervals 
// such that Intervals remain non-overlapping and sorted in ascending order by 
// start[i].
// Return Intervals after the insertion of newInterval.
#include<bits/stdc++.h>
using namespace std;    

// time: O(N) where N is the number of intervals
// space: O(N) for storing the result in a new vector
vector<vector<int> > insertNewInterval(vector<vector<int> >& intervals, vector<int>& newInterval){
    vector<vector<int> > res;
    int i=0;
    int n = intervals.size();

    // insert intervals before newInterval
    while(i < n && intervals[i][1] < newInterval[0]){
        res.push_back(intervals[i]);
        i++;
    }

    // merge overlapping intervals
    while(i < n && intervals[i][0] <= newInterval[1]){
        //update the start time of newInterval to the minimum of
        // the current interval's start time and newInterval's start time
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        //update the end time of newInterval to the maximum of
        // the current interval's end time and newInterval's end time
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push_back(newInterval); // add the merged newInterval

    // insert remaining intervals after newInterval
    while(i < n){
        res.push_back(intervals[i]);
        i++;    
    }

    return res; // return the result with newInterval inserted
}
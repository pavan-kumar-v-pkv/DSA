// Given one meeting room and N meetings represented by two arrays, start and 
// end, where start[i] represents the start time of the ith meeting and end[i] 
// represents the end time of the ith meeting, determine the maximum number of 
// meetings that can be accommodated in the meeting room if only one meeting 
// can be held at a time.
#include<bits/stdc++.h>
using namespace std;

// time: O(NlogN) where N is the number of meetings
// space: O(N) for storing the meetings in a vector of pairs
bool static compare(pair<int, int>& a, pair<int, int>& b){
    // sort based on end time
    return a.second < b.second;
}
int maxMeetings(vector<int>& start, vector<int>& end){
    int n = start.size();
    // vector to store the meetings as pairs of (end time, start time)
    vector<pair<int, int> > meetings;

    // fill the meetings vector with pairs of end and start times
    for(int i=0;i<n;i++){
        meetings.push_back({start[i], end[i]});
    }

    // sort the meetings based on end time
    sort(meetings.begin(), meetings.end(), compare);

    // the end time of the previous meeting
    int prevEndTime = meetings[0].second;
    int count = 1; // count of meetings that can be accommodated

    for(int i=1;i<n;i++){
        if(meetings[i].first > prevEndTime){
            prevEndTime = meetings[i].second;
            count++; // increment the count of meetings
        }
    }
    return count; // return the count of meetings that can be accommodated
}

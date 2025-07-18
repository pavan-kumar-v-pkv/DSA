// Given an 2D array Jobs of size Nx3, where Jobs[i][0] represents JobID , 
// Jobs[i][1] represents Deadline , Jobs[i][2] represents Profit associated 
// with that job. Each Job takes 1 unit of time to complete and only one job 
// can be scheduled at a time.
// The profit associated with a job is earned only if it is completed by its 
// deadline. Find the number of jobs and maximum profit.
#include<bits/stdc++.h>
using namespace std;    

// time: O(nLogn + n^2), worst case is O(n^2) where n is the number of jobs`)
// space: O(n) for storing the jobs in a priority queue
bool static compare(vector<int>& a, vector<int>& b){
    return a[2] > b[2]; // sort jobs based on profit in descending order
}
vector<int> jobScheduling(vector<vector<int> >& jobs){
    // sort jobs vased on profit in descending order
    sort(jobs.begin(), jobs.end(), compare);
    int n = jobs.size();

    // get the maximum deadline to complete the job
    int maxDeadline = -1;
    for(int i=0;i<n;i++){
        maxDeadline = max(maxDeadline, jobs[i][1]);
    }

    // initialise a hash table to store the selected jobs
    vector<int> hash(maxDeadline+1, -1);

    int count = 0; // count of jobs done
    int profit = 0; // total profit earned
    for(int i=0;i<n;i++){
        // iterate over each deadline slot strting from the current job's deadline
        for(int j=jobs[i][1];j>0;j--){
            // if the current slot is empty, assign the job to this slot
            if(hash[j] == -1){
                count++; // cnt of selected jobs
                profit += jobs[i][2];
                hash[j] = jobs[i][0]; // assign job id to the slot
                break; // break the loop as we have assigned the job
            }
        }
    }
    return {count,profit}; // return the count of jobs done and total profit earned

}
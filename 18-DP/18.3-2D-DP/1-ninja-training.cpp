// A ninja has planned a n-day training schedule. Each day he has to perform one of three activities - running, stealth training, or fighting 
// practice. The same activity cannot be done on two consecutive days and the ninja earns a specific number of merit points, based on the activity 
// and the given day.

// Given a n x 3-sized matrix, where matrix[i][0], matrix[i][1], and matrix[i][2], represent the merit points associated with running, stealth and 
// fighting practice, on the (i+1)th day respectively. Return the maximum possible merit points that the ninja can earn.
#include<bits/stdc++.h>
using namespace std;

// recursion
// time: O(3^N)
// space: O(N)
int func(int day, int last, vector<vector<int>>& points){
    // base case
    if(day == 0){
        int maxi = 0;
        // calculate the maximum points for the first day by choosing an activity different from prev day
        for(int i=0;i<=2;i++){
            if(i != last)
                maxi = max(maxi, points[0][i]);
        }
        // return the maximum points
        return maxi;
    }
    int maxi = 0;
    // iterate through activites for the current day
    for(int i=0;i<=2;i++){
        if(i != last){
            int activity = points[day][i] + func(day-1, i, points);
            maxi = max(maxi, activity);
        }
    }
    return maxi;
}
int ninjaTraining(vector<vector<int>>& matrix){
    int day = matrix.size()-1;
    int last = 3;
    return func(day, last, matrix);
}

// memoization
// time: O(N*4*3).There are N*4 states and for every state we are running a for loop iterating 3 times
// space: O(N)
int func2(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp){
    // if the result for this day and last activity is already calculated, return it
    if(dp[day][last] != -1) return dp[day][last];

    // base case
    if(day == 0){
        int maxi = 0;
        for(int i=0;i<=2;i++){
            if(i != last)
                maxi = max(maxi, points[0][i]);
        }
        return dp[day][last] = maxi;
    }
    int maxi = 0;
    for(int i=0;i<=2;i++){
        if(i != last){
            int activity = points[day][i] + func2(day-1, i, points, dp);
            maxi = max(maxi, activity);
        }
    }

    return dp[day][last] = maxi;
}
int ninjajaTraining2(vector<vector<int>>& matrix){
    int day = matrix.size();
    // create a memoization table to store intermediate results
    vector<vector<int>> dp(day, vector<int>(4, -1));
    int last = 3;
    return func2(day-1, last, matrix, dp);
}

// tabulation
// time: O(N*4*3)
// space: O(N*4)
int ninjaTraining3(vector<vector<int>>& matrix){
    int n = matrix.size();
    // create a 2D Dp table to store the maximum points
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // initialise the DP table for the first day (day 0)
    dp[0][0] = max(matrix[0][1], matrix[0][2]);
    dp[0][1] = max(matrix[0][0], matrix[0][2]);
    dp[0][2] = max(matrix[0][0], matrix[0][1]);
    dp[0][3] = max(matrix[0][1], max(matrix[0][2], matrix[0][0]));

    // iterate through the days starting from day 1
    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            dp[day][last] = 0;
            // iterate through the tasks for the current data
            for(int task=0;task<=2;task++){
                if(task != last){
                    int activity = matrix[day][task] + dp[day-1][task];

                    // update the maximum points for the current day and last activity
                    dp[day][last] = max(dp[day][last], activity);
                }
            }
        }
    }
    // the maximum points for the lastday with any activity can be found in dp[n-1][3]
    return dp[n-1][3];
}

// space optimization
// time: O(N*4*3)
// space: O(4)
int ninjaTraining4(vector<vector<int>>& matrix){
    int n = matrix.size();
    // initialise a vector to store the maximum points for the previous day's activities
    vector<int> prev(4, 0);

    // initialise the prev array for the day (day 0)
    prev[0] = max(matrix[0][1], matrix[0][2]);
    prev[1] = max(matrix[0][0], matrix[0][2]);
    prev[2] = max(matrix[0][1], matrix[0][0]);
    prev[3] = max(matrix[0][0], max(matrix[0][1], matrix[0][2]));

    // iterate through the days starting from day 1
    for(int day = 0;day<n;day++){
        // create a temporary vector to store the maximum points for the current day's activities
        vector<int> temp(4, 0);
        for(int last=0;last<4;last++){
            temp[last] = 0;
            // iterate through the tasks for the current day
            for(int task=0;task<=2;task++){
                if(task != last){
                    temp[last] = max(temp[last], matrix[day][task]+prev[task]);
                }
            }
        }
        // update prev with maximum points for the current day
        prev = temp;
    }

    return prev[3];
}
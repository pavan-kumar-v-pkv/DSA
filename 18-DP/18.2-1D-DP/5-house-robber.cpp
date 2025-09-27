// A robber is targeting to rob houses from a street. Each house has security measures that alert the police when two adjacent houses are robbed. 
// The houses are arranged in a circular manner, thus the first and last houses are adjacent to each other.

// Given an integer array money, where money[i] represents the amount of money that can be looted from the (i+1)th house. Return the maximum amount 
// of money that the robber can loot without alerting the police.
#include<bits/stdc++.h>
using namespace std;

// recursive solution
// time: O(2^N)
// space: O(N)
int func(int ind, vector<int>& a){
    // base case
    if(ind == 0)
        return a[ind];
    if(ind < 0)
        return 0;

    // choosing the current element
    int pick = a[ind] + func(ind-2, a);
    // skipping the current element
    int nonPick = 0 + func(ind-1, a);

    // return the maximum
    return max(pick, nonPick);

}
int houseRobber(vector<int>& money){
    int n = money.size();
    vector<int> a1;
    vector<int> a2;

    // if array has only one element, return that
    if(n==1)
        return money[0];

    for(int i=0;i<n;i++){
        // store every element in a1 execept the first element
        if(i != 0) a1.push_back(money[i]);
        // store every element in a1 execept the first element
        if(i != n-1) a2.push_back(money[i]);
    }

    int ans1 = func(a1.size()-1, a1);
    int ans2 = func(a2.size()-1, a2);

    return max(ans1, ans2);
}

// memoization
// time: O(N)
// space: O(N)
int func2(int ind, vector<int>& a, vector<int>& dp){
    // base case
    if(ind == 0)
        return a[ind];
    if(ind < 0)
        return 0;

    if(dp[ind] != -1)
        return dp[ind];

    // choosing the current element
    int pick = a[ind] + func2(ind-2, a, dp);
    // skipping the current element
    int nonPick = 0 + func2(ind-1, a, dp);

    // return the maximum
    return dp[ind] = max(pick, nonPick);

}
int houseRobber2(vector<int>& money){
    int n = money.size();
    vector<int> a1;
    vector<int> a2;

    // if array has only one element, return that
    if(n==1)
        return money[0];

    for(int i=0;i<n;i++){
        // store every element in a1 execept the first element
        if(i != 0) a1.push_back(money[i]);
        // store every element in a1 execept the first element
        if(i != n-1) a2.push_back(money[i]);
    }
    vector<int> dp1(n, -1);
    int ans1 = func2(a1.size()-1, a1, dp1);
    vector<int> dp2(n, -1);
    int ans2 = func2(a2.size()-1, a2, dp2);

    return max(ans1, ans2);
}

// tabulation
// time: O(N)
// space: O(N)
int func3(vector<int>& nums){
    int ind = nums.size();
    vector<int> dp(ind, 0);

    // base case
    dp[0] = nums[0];

    // interate through the elements of the array
    for(int i=1;i<ind;i++){
        int pick = nums[i];
        if(i > 1){
            pick += dp[i-2];
        }
        int nonPick = 0 + dp[i-2];

        dp[i] = max(pick, nonPick);
    }

    return dp[ind-1];
}
int houseRobber3(vector<int>& money){
    int n = money.size();
    vector<int> a1;
    vector<int> a2;

    // if array has only one element, return that
    if(n==1)
        return money[0];

    for(int i=0;i<n;i++){
        // store every element in a1 execept the first element
        if(i != 0) a1.push_back(money[i]);
        // store every element in a1 execept the first element
        if(i != n-1) a2.push_back(money[i]);
    }

    int ans1 = func3(a1);
    int ans2 = func3(a2);

    return max(ans1, ans2);
}

// space optimization
// time: O(N)
// space: O(N)
int func4(vector<int>& nums){
    int ind = nums.size();
    int prev2 = 0;
    int prev = nums[0];

    for(int i=1;i<ind;i++){
        int pick = nums[i];
        if(i > 1){
            pick += prev2;
        }

        int nonPick = 0 + prev;

        int curr = max(pick, nonPick);
        prev2 = prev;
        prev = curr;
    }
    return prev;

}
int houseRobber4(vector<int>& money){
    int n = money.size();
    vector<int> a1;
    vector<int> a2;

    // if array has only one element, return that
    if(n==1)
        return money[0];

    for(int i=0;i<n;i++){
        // store every element in a1 execept the first element
        if(i != 0) a1.push_back(money[i]);
        // store every element in a1 execept the first element
        if(i != n-1) a2.push_back(money[i]);
    }

    int ans1 = func4(a1);
    int ans2 = func4(a2);

    return max(ans1, ans2);
}
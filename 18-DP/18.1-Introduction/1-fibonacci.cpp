#include<bits/stdc++.h>
using namespace std;

// Memoization: "top-down" dynamic programming
// involves solving the problem by recursively breaking it down from the main problem to the base cases and 
// storing the results of these sub-problems in a table 
// Steps to Memoize a Recursive Solution
// 1. Create a dp[n+1] array initialized to -1.
// 2. Check if the answer is already calculated using the dp array (dp[n] != -1). If yes, return the value.
// 3. If not, compute the value and store it in the dp array before returning.

// Time Complexity: O(N) Overlapping subproblems return answers in constant time O(1).
//  Therefore, only 'n' new subproblems are solved, resulting in O(N) complexity.

// Space Complexity: O(N) Using recursion stack space and an array, 
// the total space complexity is O(N) + O(N) ≈ O(N).

int f(int n, vector<int>& dp){
    // base case: return n if n is 0 or 1
    if(n <= 1) return n;
    // if the value if already calculated, return it
    if(dp[n] != -1) return dp[n];

    // calculate the value and store it in dp array
    return dp[n] = f(n-1, dp) + f(n-2, dp);
}

// Tabulation, also known as "bottom-up" dynamic programming, 
// involves solving the problem by iteratively solving all possible sub-problems, starting from the base cases 
// and building up to the solution of the main problem
// steps:
// 1. Declare a dp[] array of size n+1.
// 2. Initialize base condition values, i.e., i=0 and i=1 of the dp array as 0 and 1 respectively.
// 3. Use an iterative loop to traverse the array (from index 2 to n) and set each value as dp[i-1] + dp[i-2].
int main(){
        int n = 5; // Fibonacci number to find

    // Edge case: if n is 0, the result is 0
    if (n == 0) {
        cout << 0;
        return 0;
    }

    // Edge case: if n is 1, the result is 1
    if (n == 1) {
        cout << 1;
        return 0;
    }

    int prev2 = 0; // Fibonacci number for n-2
    int prev = 1;  // Fibonacci number for n-1

    // Iterate from 2 to n to find the nth Fibonacci number
    for (int i = 2; i <= n; i++) {
        int cur_i = prev2 + prev; // Current Fibonacci number
        prev2 = prev;             // Update prev2 to the previous Fibonacci number
        prev = cur_i;             // Update prev to the current Fibonacci number
    }

    // Print the nth Fibonacci number
    cout << prev;
    return 0;
    
    // int n = 5;
    // vector<int> dp(n+1);

    // // base cases
    // dp[0] = 0;
    // dp[1] = 1;

    // for(int i=2;i<=n;i++){
    //     dp[i] = dp[i-1] + dp[i-2];
    // }

    // cout<<dp[n]<<endl;

    // return 0;
    
}

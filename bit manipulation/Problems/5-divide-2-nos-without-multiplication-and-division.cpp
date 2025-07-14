// Given the two integers, dividend and divisor. Divide without using the mod, 
// division, or multiplication operators and return the quotient.
// The fractional portion of the integer division should be lost as it truncates
// toward zero.
// As an illustration, 8.345 and -2.7335 would be reduced to 8 and -2 respectively.
// Note: Assume we are dealing with an environment that could only store integers 
// within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, 
// if the quotient is strictly greater than 231 - 1, then return 231 - 1, and 
// if the quotient is strictly less than -231, then return -231.
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(divided), in the worst case when the divisor is 1, the number of iterations taken will be O(dividend)
// space: O(1) since we are using a single integer to store the result
int divide(int dividend, int divisor) {
    // base case
    if(dividend == divisor) return 1;
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;
    if(divisor == 1) return dividend;
    // variable to store the sign of result;
    bool isPositive = true;

    if(dividend >= 0 && divisor < 0)
        isPositive = false; // if dividend is positive and divisor is negative, result will be negative
    else if(dividend < 0 && divisor > 0)
        isPositive = false; // if dividend is negative and divisor is positive, result will be negative

    long long n = dividend;
    long long d = divisor;
    n = abs(n); // take absolute value of dividend
    d = abs(d); // take absolute value of divisor

    long long ans = 0, sum = 0;

    while(sum + d <= n){
        // increment the count
        ans++;
        // update the sum
        sum += d;
    }

    // handling overflow conditions
    if(ans > INT_MAX && isPositive)
        return INT_MAX; // if the result is greater than INT_MAX, return INT_MAX
    if(ans > INT_MAX && !isPositive)
        return INT_MIN; // if the result is less than INT_MIN, return INT_MIN

    return isPositive ? ans : -ans; // return the result with the correct sign
}

// optimized approach using bit manipulation
// time: O((logN)^2)   
// space: O(1) since we are using a single integer to store the result
int divideOptimized(int dividend, int divisor) {
    // edge cases
    if(dividend == divisor) return 1;
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;
    if(divisor == 1) return dividend;

    bool isPositive = true;

    if(dividend >= 0 && divisor < 0)
        isPositive = false;
    else if(dividend <= 0 && divisor > 0)
        isPositive = false;

    long n = dividend;
    long d = divisor;
    n = abs(n);
    d = abs(d);
    int ans = 0;
    while(n >= d){
        int cnt = 0;
        // find the required largest power of 2
        while(n >= (d<<(cnt+1))){
            cnt++;
        }
        ans += 1<<cnt;
        n -= d<<cnt; // subtract the largest power of 2 from dividend
    }

    // handling overflow conditions
    if(ans == (1<<31) && isPositive)
        return INT_MAX; // if the result is greater than INT_MAX, return INT_MAX
    if(ans == (1<<31) && !isPositive)
        return INT_MIN; // if the result is less than INT_MIN, return INT_MIN

    return isPositive ? ans : -1*ans; // return the result with the correct sign
}
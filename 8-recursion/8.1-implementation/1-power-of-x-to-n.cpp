// Implement the power function pow(x, n) , which calculates the x raised to n i.e. xn.
#include<bits/stdc++.h>
using namespace std;

// brute force approach
// Time complexity: O(n)
// Space complexity: O(1)
double pow(double x, int n){
    if(n == 0 || x == 1.0)
        return 1.0;
    long long temp = n; // to avoid integer overflow

    // handle negative exponents
    if(n < 0){
        x = 1/x;
        temp = -1*1ll*n;
    }
    double ans = 1;
    for(long long i=0;i<temp;i++){
        ans *= x;
    }
    return ans;
}

// optimal approach
// Time complexity: O(log n)
// Space complexity: O(1)
double pow2(double x, int n){
    if(n == 0 || x == 1)
        return 1.0;
    long long temp = n; // to avoid integer overflow
    if(n < 0){
        x = 1/x;
        temp = -1*1ll*n;
    }
    double ans = 1;
    while(temp > 0){
        if(temp % 2 == 1) // if n is odd
            ans = ans * x;
        x = x * x; // square the base
        temp /= 2; // divide n by 2
    }
    return ans;
}

// optimal approach using recursion
// Time complexity: O(log n)
// Space complexity: O(log n) due to recursion stack
double power(double x, int n){
    if(n == 0 || x == 1)
        return 1;
    if(n == 1)
        return x;

    if(n % 2 == 0){ // if n is even
        // recursive call: x * x, n/2
        return power(x*x, n/2);
    }
    // if n is odd
    // recursive call: x * power(x, n-1)
    return x * power(x, n-1);
}
double myPower(double x, int n){
    int num = n;
    if(num < 0){
        return (1/power(x, -1*num));
    }
    return power(x, num);
}
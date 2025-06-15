#include<bits/stdc++.h>
using namespace std;

// time complexity O(2^N) — The function makes two recursive calls for each non-base case, leading to an exponential growth in the number of calls as N increases.
// space complexity O(N) — The maximum depth of the recursion stack is N, which occurs when the function reaches the base case.
class Solution {
public:
    int fib(int n) {
        //your code goes here
        if(n <= 1)
            return n;

        return fib(n-1) + fib(n-2);
    }
};  
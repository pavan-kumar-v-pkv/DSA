#include<bits/stdc++.h>
using namespace std;

// time: O(digits of n)
// space: O(1)
class Solution {
public:
    int countDigit(int n) {
        int cnt = 0;
        while(n > 0){
            n /= 10; // Remove the last digit
            cnt++;   // Increment the count
        }
        return cnt; // Return the total count of digits
    }

    int countDigit2(int n) {
        return log10(n) + 1; // Using logarithm to count digits
    }
};
#include<bits/stdc++.h>
using namespace std;
// Function to count the number of digits in a number
// Time Complexity: O(log10(N)) – In every iteration, N is divided by 10 (equivalent to the number of digits in N.)
// Space Complexity: O(1) – Using a couple of variables i.e., constant space.
class Solution {
public:
    int reverseNumber(int n) {
        int reversed = 0 ;
        while(n > 0){
            int lastDigit = n % 10;
            reversed = (reversed*10) + lastDigit;
            n /= 10;
        }
        return reversed;
    }
};
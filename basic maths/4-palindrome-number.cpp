#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(log10(N)) – In every iteration, N is divided by 10 (equivalent to the number of digits in N.)
// Space Complexity: O(1) – Using a couple of variables i.e., constant space.
class Solution {
public:
    bool isPalindrome(int n) {
        int reversed = 0 ;
        int temp = n;
        while(n > 0){
            int lastDigit = n % 10;
            reversed = (reversed*10) + lastDigit;
            n /= 10;
        }
        return reversed==temp;
    }
};
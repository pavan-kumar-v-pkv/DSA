#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(log10(N)) – In every iteration, N is divided by 10 (equivalent to the number of digits in N.)
// Space Complexity: O(1) – Using a couple of variables i.e., constant space.
class Solution {
public:
    int largestDigit(int n) {
        if(n == 0)
            return 0;
        int maxi = INT_MIN;
        while(n > 0){
            int lastDigit = n%10;
            maxi = max(maxi, lastDigit);
            n /= 10;
        }
        return maxi;
    }
};
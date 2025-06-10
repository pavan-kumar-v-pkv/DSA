#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N) – Running a loop from 1 to N.
// Space Complexity: O(1) – Using a couple of variables i.e., constant space, regardless of the size of input.
class Solution {
public:
    bool isPerfect(int n) {
        int sum = 0;
        for(int i=1;i<n;i++){
            if(n%i==0)
                sum += i;
        }
        return sum == n;
    }

    bool isPerfect2(int n){
        int sum = 1;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                sum += i;
                if(i != n/i) // Avoid adding the square root twice if n is a perfect square
                    sum += n/i;
            }
        }
        return n > 1 && sum == n; // Exclude 1 as a perfect number
    }
};
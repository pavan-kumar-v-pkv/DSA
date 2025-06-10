#include<bits/stdc++.h>
using namespace std;

//time: O(sqrt(N))
//space: O(1)
class Solution {
public:
    bool isPrime(int n) {
        if(n <= 1) return false; // 0 and 1 are not prime numbers
        //your code goes here
        for(int i=2;i*i<=n;i++){
            if(n%i == 0)
                return false;
        }
        return true;
    }
};
#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N) – Iterating once from 2 to N and checking if each number is prime.
// Space Complexity: O(1) – Using a couple of variables i.e., constant space.
class Solution {
public:
    bool isPrime(int n){
        if(n <= 1) return false;
        for(int i=2;i*i<=n;i++){
            if(n % i == 0)
                return false;
        }
        return true;
    }
    int primeUptoN(int n) {
        int cnt = 0;
        for(int i=2;i<=n;i++){
            if(isPrime(i)){
                cnt++;
            }
        }
        return cnt;

    }
};
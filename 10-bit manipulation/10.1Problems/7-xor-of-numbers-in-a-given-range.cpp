// Given two integers L and R. Find the XOR of the elements in the range [L , R].
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(N) where N is the size of the range [L, R]
// space: O(1) since we are using a single integer to store the result
int xorOfRange(int l, int r){
    int ans = 0;

    for(int i=l;i<=r;i++){
        ans ^= i;
    }
    return ans;
}

// optimal approach using properties of XOR
// time: O(1) since we are using a mathematical formula to calculate the result
// space: O(1) since we are using a single integer to store the result
int xorOfRangeOptimized(int l, int r) {
    // function to calculate XOR from 0 to n
    auto xorFromZeroToN = [](int n) {
        if(n % 4 == 0) return n;
        else if(n % 4 == 1) return 1;
        else if(n % 4 == 2) return n + 1;
        else return 0;
    };

    // XOR from l to r can be calculated as:
    // xor(0 to r) ^ xor(0 to l-1)
    return xorFromZeroToN(r) ^ xorFromZeroToN(l - 1);
}

int main() {
    int l, r;
    cout << "Enter the range (L R): ";
    cin >> l >> r;

    // Using brute force approach
    int resultBruteForce = xorOfRange(l, r);
    cout << "XOR of range [" << l << ", " << r << "] using brute force: " << resultBruteForce << endl;

    // Using optimized approach
    int resultOptimized = xorOfRangeOptimized(l, r);
    cout << "XOR of range [" << l << ", " << r << "] using optimized method: " << resultOptimized << endl;

    return 0;
}
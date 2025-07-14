// Given two integers start and goal. Flip the minimum number of bits of start 
// integer to convert it into goal integer.
// A bits flip in the number val is to choose any bit in binary representation 
// of val and flipping it from either 0 to 1 or 1 to 0.
#include<bits/stdc++.h>
using namespace std;

// time: O(1)
// space: O(1)
int minBitsFlip(int start, int goal){
    // variable to store bits that are different
    int diffBits = start ^ goal;
    // variable to count number of set bits
    int cnt = 0;
    // count the number of set bits in diffBits
    for(int i=0;i<32;i++){
        // update count if the rightmost bit is set
        cnt += (diffBits & 1);
        // right shift to check the next bit
        diffBits >>= 1; 
    }
    return cnt;
}
#include<bits/stdc++.h>
using namespace std;

// decimal to binary conversion
// time: O(logN) since the number is divided by 2 continuously
// space: O(logN) for the string to store the binary representation
string decimalToBinary(int n){
    string result = "";

    while(n != 1){
        if(n % 2 == 1) result += '1';
        else result += '0';
        n /= 2;
    }

    reverse(result.begin(), result.end());
    return result;
}

// binary to decimal conversion
// time: O(N) where N is the number of bits in the binary representation
// space: O(1) since we are using a single integer to store the result
int binaryTodecimal(string str){
    int len = str.length();
    int num = 0;
    int val = 1;

    for(int i=len-1;i>=0;i--){
        if(str[i] == '1'){
            num += val;
        }
        val *= 2; // double the value for the next bit
    }

    return num;
}

// Bit Manipulation Tricks and Techniques
// 1. Swapping two number withour a third variable
// time: O(1)
// space: O(1)
void swap(int& a, int& b){
    a = a ^ b; // Step 1: a now hold a XOR b
    b = a ^ b; // step 2: b now holds the original value of a
    a = a ^ b; // step 3: a now holds the original value of
}

// 2. Checking if the i-th Bit is set
// using left shift operator and right shift operator
// time: O(1)
// space: O(1)
bool isIthBitSet(int n, int i){
    // left shift 1 by i positions to create a mask
    // then use bitwise AND to check if the i-th bit is set
    return (n & (1 << i)) != 0; // check if the i-th bit is set
}

bool isIthBitSetUsingRightShift(int n, int i){
    // right shift n by i positions and check if the least significant bit is set
    return (n >> i) & 1; // check if the i-th bit is set
}

// 3. Setting the i-th Bit
// using OR operator
// time: O(1)
// space: O(1)
int setIthBit(int& n, int i){
    return n | (1<<i); // set the i-th bit to 1
}

// 4. Clearing the i-th Bit
// using AND operator with negation
// time: O(1)
// space: O(1)
int clearIthBit(int& n, int i){
    return n & ~(1<<i); // clear the i-th bit (set it to 0)
}

// 5. Toggling the i-th Bit
// using XOR operator
// time: O(1)
// space: O(1)
int toggleIthBit(int& n, int i){
    return n ^ (1<<i); // toggle the i-th bit
}

// 6. removing the last set bit
// using AND operator with N-1
// time: O(1)
// space: O(1)
int removeLastSetBit(int n){
    return n & (n-1); // clear the last set bit
}

// 7. Checking if a number is a power of 2
// using bitwise AND operator with N-1, if the result is 0, the number is a power of 2
// time: O(1)
// space: O(1)
bool isPowerOfTwo(int n){
    return n > 0 && (n & (n-1)) == 0;
}

// 8. Counting the number of set bits
// a loop can be used along with the bitwise operator
// time: O(logN) since we are dividing the number by 2 continuously
// space: O(1) since we are using a single integer to store the count
int countSetBits(int n){
    int cnt = 0;
    while(n > 0){
        cnt += (n & 1);
        n >>= 1; // right shift to check the next bit
    }
    return cnt;
}

// optimized approach, involed repeatedly turning off the rightmidt bit using n & (n-1)
// time: O(set bits) since we are only iterating through the set bits
// space: O(1) since we are using a single integer to store the count
int countSetBitsOptimized(int n){
    int cnt = 0;
    while(n > 0){
        cnt++;
        n = n & (n-1); // turn off the rightmost set bit
    }
    return cnt;
}
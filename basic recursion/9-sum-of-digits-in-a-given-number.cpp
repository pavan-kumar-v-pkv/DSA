// Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
#include<bits/stdc++.h>
using namespace std;

// Input : num = 529
// Output : 7
// Explanation : In first iteration the digits sum will be = 5 + 2 + 9 => 16
// In second iteration the digits sum will be 1 + 6 => 7.
// Now single digit is remaining , so we return it.

// time complexity O(log(N)) — The number of digits in the number decreases with each iteration, so the time complexity is proportional to the logarithm of the number.
// space complexity O(1) — The function uses a constant amount of space for the recursive calls and does not use any additional data structures.
class Solution{
public:
	int addDigits(int num){
		// Base case: if the number is a single digit, return it
        if(num < 10)
            return num;
        // recursive case: sum the digits and continue;
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return addDigits(sum);
	}
};
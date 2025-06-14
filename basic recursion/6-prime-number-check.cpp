#include<bits/stdc++.h>
using namespace std;

// time complexity O(sqrt(N)) — The function checks divisibility from 2 to sqrt(N), 
// so the time complexity is proportional to the square root of the number.
// space complexity O(1) — The function uses a constant amount of space for the recursive calls and does not use any additional data structures.
class Solution{	
	public:
        bool prime(int num, int x){
            if(x > sqrt(num))
                return true;

            if(num % x == 0)
                return false;

            return prime(num, x+1);
        }
		bool checkPrime(int num){
			//your code goes here
            if(num <= 1)
                return false;

            return prime(num, 2);
		}
};
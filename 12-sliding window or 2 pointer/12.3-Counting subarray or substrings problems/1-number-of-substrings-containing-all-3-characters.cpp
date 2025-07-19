// Given a string s , consisting only of characters 'a' , 'b' , 'c'.Find the 
// number of substrings that contain at least one occurrence of all these 
// characters 'a' , 'b' , 'c'.
#include<bits/stdc++.h>
using namespace std;

// brute forace approach
// time: O(N^2), where N is the size of the string.
// space: O(1), as no significant amount of extra space is used
int numberOfStrings(string s){
    int cnt = 0;

    for(int i=0;i<s.size();i++){
        // array to track presence of 'a', 'b', 'c'
        int hash[3] = {0};

        for(int j=i;j<s.size();j++){
            // mark current character in hash
            hash[s[j]-'a']=1;
            // check if all 3 characters are present
            if(hash[0] + hash[1] + hash[2] == 3){
                cnt += 1;
            }
        }
    }
    return cnt;
}

// optimal approach using sliding window
// time: O(N), where N is the size of the string
// space: O(1), as no significant amount of extra space is used
// Intuition:
// The idea here is to use a for loop to iterate through the array, as moving
//forward in the array update the last seen of 'a', 'b', 'c' in the hash array.
// Now, check if the current substring has atleast one of each 'a', 'b', 'c', 
// if so, then the previous substrings must be having these characters too, 
// so add all such substrings in the count varaible and return it.

// Approach:
// 1. First, initialize few variables: An arraylastSeen of size 3 ({-1, -1, -1})
// to store the last seen index of characters 'a', 'b', 'c' respectively, count
// to 0 to keep track of the number of valid substrings found.
// 2. Use a loop to iterate through each character in the string. Update the 
// lastSeen array for the current character. After updating lastSeen, check if 
// all characters 'a', 'b', 'c' have been seen at least once.
// 3. Add the calculated count to count. After iterating through all characters 
// in string, return count.

int numberOfSubstrings(string s){
    // array to store the last seen index of characters 'a', 'b', 'c'
    int lastSeen[3] = {-1, -1, -1};

    int count = 0;

    for(int i=0;i<s.size();i++){
        // update the last seen index for
        lastSeen[s[i]-'a'] = i;
        // check if all 3 characters are seen
        if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
            count += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
        }
    }
    return count;
}


// Given an array of integers asteroids, where each integer represents an 
// asteroid in a row, determine the state of the asteroids after all collisions.
// In this array, the absolute value represents the size of the asteroid, and 
// the sign represents its direction (positive meaning right and negative 
// meaning left). All asteroids move at the same speed.
// When two asteroids meet, the smaller one will explode. If they are the same 
// size, both will explode. Asteroids moving in the same direction will never 
// meet.
#include<bits/stdc++.h>
using namespace std;

// time: O(N), where N is the size of the array
// space: O(N)

vector<int> asetroidCollision(vector<int>& asteroids){
    int n = asteroids.size();
    // vector implementation of stack
    vector<int> st;

    for(int i=0;i<n;i++){
        // push the asteroid in stack if a right moving (positive) is seen
        if(asteroids[i] > 0){
            st.push_back(asteroids[i]);
        }
        // else if the asteroid is moving from left to right (negative), 
        // perform the collisions
        else{
            // until the right moving(positive) asteroids are smaller in size
            // keep on destroying them
            while(!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])){
                st.pop_back();
            }
            // if there is right moving asteroid which is same size
            if(!st.empty() && st.back() == abs(asteroids[i]))
                st.pop_back();

            // otherwise, if there is no left moving asteroid, the right moving asteroid will not be destroyed
            else if(st.empty() || st.back() < 0){
                st.push_back(asteroids[i]);
            }
        }
    }
    return st;
}


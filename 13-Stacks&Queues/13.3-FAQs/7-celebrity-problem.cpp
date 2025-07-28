// A celebrity is a person who is known by everyone else at the party but does 
// not know anyone in return. Given a square matrix M of size N x N where 
// M[i][j] is 1 if person i knows person j, and 0 otherwise, determine if there 
// is a celebrity at the party. Return the index of the celebrity or -1 if no 
// such person exists.

// Note that M[i][i] is always 0.
#include<bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(N^2) where N is the size of square matrix
// Traversing the given square matrix to populate the two lists takes O(N2) time.
// Traversing on the lists to identify the celebrity takes O(N) time.

// Space Complexity: O(N)
// The two lists to store the count of how many people each person knows and how many people know each person takes O(N) space each.
int celebrity(vector<vector<int> >& M){
    int n = M.size();
    // to store the count of people who know person of index i
    vector<int> knowMe(n, 0);
    // to store the count of people who the person of index i knows
    vector<int> Iknow(n, 0);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // if person i knows person j
            if(M[i][j] == 1){
                knowMe[j]++;
                Iknow[i]++;
            }
        }
    }

    // traverse for all person to find the celebrity
    for(int i=0;i<n;i++){
        // return the index of celebrity
        if(knowMe[i] == n-1 && Iknow[i] == 0){
            return i;
        }
    }

    // return -1 if no celebrity is found
    return -1;
}


// optimal approach:
// Intuition:
// Since there can be only one celebrity, instead of finding the celebrity, the people that are not celebrity can be determined. If all such people are found, any person left (if it exists) will be the celebrity.
// The two conditions to identify the celebrity is:
// -> The celebrity should be known by every person.
// -> There should be no person that celebrity knows.

// Approach:
// 1. Set up two pointers, one at the top of the matrix and one at the bottom.
// 2. Use the pointers to compare individuals:
//      If the person at the top pointer knows the person at the bottom pointer, move the top pointer down (as it cannot be the celebrity).
//      If the person at the bottom pointer knows the person at the top pointer, move the bottom pointer up (as it cannot be the celebrity).
//      If neither knows the other, increment both pointers (as they both cannot be the celebrity).
// 3. After the traversal, check if the remaining candidate pointed by the top pointer is a valid celebrity by ensuring that everyone knows this person and this person knows no one.
// 4. If a valid celebrity is found, return the index; otherwise, return -1 indicating there is no celebrity. 
int celebrity2(vector<vector<int> >& M){
    int n = M.size();
    // top and down pointers
    int top = 0, down = n-1;

    while(top < down){
        // if top knows down, top cannot be a celebrity
        if(M[top][down] == 1){
            top = top+1;
        }
        // if down knows top, it cannot be a celebrity
        else if(M[down][top] == 1){
            down = down-1;
        }
        // if both does not know each other, both cannot be celebrity
        else{
            top++;
            down--;
        }
    }
    // now the top and down will be pointing to same single person, 
    // who maybe a celebrity
    // return -1 if no celebrity is found
    if(top > down)
        return -1;

    // check if the person pointed by top and down is celebrity
    for(int i=0;i<n;i++){
        if(i == top) continue;
        if(M[top][i] == 1 || M[i][top] == 0)
            return -1;
    }
    // return index of celebrity
    return top;
}
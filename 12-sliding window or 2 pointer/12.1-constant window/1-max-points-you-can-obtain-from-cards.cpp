// Given N cards arranged in a row, each card has an associated score denoted 
// by the cardScore array. Choose exactly k cards. In each step, a card can be 
// chosen either from the beginning or the end of the row. The score is the sum 
// of the scores of the chosen cards.
// Return the maximum score that can be obtained.
#include<bits/stdc++.h>
using namespace std;

// time: O(2*k) where k i sthe size of the window
// space: O(1) for constant space usage
int maxPoints(vector<int>& cardScore, int k){
    int n = cardScore.size();
    if(k >= n) return accumulate(cardScore.begin(), cardScore.end(), 0); // if k is greater than or equal to n, return the sum of all elements in cardScore
    int leftSum = 0, rightSum = 0, maxSum = 0;
    // calculate the sum of the first k elements from the left
    for(int i=0;i<k;i++){
        leftSum += cardScore[i];
    }
    maxSum = leftSum; // initialize maxSum with the left sum
    // calculate the sum of the last k elements from the right
    int right = n-1;
    for(int i=k-1;i>=0;i--){
        leftSum -= cardScore[i];
        rightSum += cardScore[right];
        maxSum = max(maxSum, leftSum+rightSum);
        right--; 
    }
    return maxSum; // return the maximum sum obtained
}



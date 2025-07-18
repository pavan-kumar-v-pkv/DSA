// A line of N kids is standing there. The rating values listed in the 
// integer array ratings are assigned to each kid.
// These kids are receiving candy, according to the following criteria:
// There must be at least one candy for every child.
// Kids whose scores are higher than their neighbours receive more candies than
// their neighbours.
// Return the minimum number of candies needed to distribute among children.
#include<bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(3N) where N is the number of kids
// space: O(2N) for storing the left and right arrays
int candy(vector<int>& ratings){
    int n= ratings.size();
    if(n== 0) return 0;
    vector<int> left(n, 1);
    vector<int> right(n, 1);

    // left to right pass
    for(int i=1;i<n;i++){
        if(ratings[i] > ratings[i-1]){
            left[i] = left[i-1] + 1; // increment candy count for current kid
        }
    }
    // right to left pass
    for(int i=n-2;i>=0;i--){
        if(ratings[i] > ratings[i+1]){
            ratings[i] = max(ratings[i], ratings[i+1]);
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += max(left[i], right[i]);
    }
    return ans;
}

// better approach
// time: O(2N) where N is the number of kids
// space: O(N) for storing the left and right arrays
int candy2(vector<int>& ratings){
    int n = ratings.size();
    if(n == 0) return 0;
    vector<int> left(n, 1);

    for(int i=1;i<n;i++){
        if(ratings[i] > ratings[i-1]){
            left[i] = left[i-1] + 1;
        }
    }

    int cur = 1;
    int right = 1; // right candy count;
    int sum = max(1, left[n-1]); // start with the last kid's candy count
    for(int i=n-2;i>=0;i--){
        if(ratings[i] > ratings[i+1]){
            cur = right+1; // increment candy count for current kid
        }
        else{
            cur = 1; // reset candy count for current kid
        }
        right = cur; // update right candy count
        sum += max(left[i], cur); // add the maximum of left and right candy counts
    }
    return sum; // return the total candy count
}

// optimal approach
// time: O(N) where N is the number of kids
// space: O(1) for constant space usage
// Approach
// 1. Start by initializing the total number of candies to 1 and set the current
//   slope to stable.
// 2. Begin iterating through the ratings array from the second child to the 
//  last.
// 3. If the current child's rating is equal to the previous one, give the 
//   current child one more candy than the previous child and move to the 
//   next child.
// 4. If the ratings are not equal, identify an increasing trend. Assign more 
//   candies to each child in this trend, incrementing as the ratings increase.
// 5. After the increasing trend, identify a decreasing trend. Assign more 
//   candies to each child in this trend, incrementing as the ratings decrease.
// 6. Compare the candy counts from the increasing and decreasing trends. If 
//   the decreasing trend exceeds the peak from the increasing trend, adjust 
//   the total number of candies to ensure children with higher ratings get 
//   more candies than their neighbors.
// 7. After processing all children, return the total number of candies 
//   distributed.
int candy3(vector<int>& ratings){
    int n = ratings.size();
    int i = 1;
    int sum = 1; // total candies, starting with 1 for the first child

    while(i < n){
        if(ratings[i] == ratings[i-1]){
            sum += 1; // if ratings are equal
            i++; // move to the next child
            continue; // skip the rest of the loop and move to the next iteration
        }
        int peak = 1; // peak candy count for the increasing trend
        while(i < n && ratings[i] > ratings[i-1]){
            peak++; // increment peak for increasing ratings
            sum += peak; // add to total candies
            i++; // move to the next child
        }
        int down = 1; // candy count for the decreasing trend
        while(i < n && ratings[i] < ratings[i-1]){
            sum += down; // add to total candies
            down++; // increment for decreasing ratings
            i++; // move to the next child
        }
        if(down > peak){
            sum += (down-peak);
        }
    }
    return sum; // return the total candies distributed
}  



// Given a sorted array nums and an integer x. Find the floor and ceil of x 
// in nums. The floor of x is the largest element in the array which is smaller 
// than or equal to x. The ceiling of x is the smallest element in the array 
// greater than or equal to x. If no floor or ceil exists, output -1.

#include <bits/stdc++.h>
using namespace std;    

// using binary search to find the floor(binary search) and ceil (lower bound)
int findFloor(int arr[], int n, int x){
    int low = 0, high = n-1;
    int ans = -1; // default answer is -1, if no floor exists
    while(low <= high){
        int mid = low + (high-low)/2;
        // maybe an answer
        if(arr[mid] <= x){
            ans = arr[mid];
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int findCeil(int arr[], int n, int x){
    int low = 0, high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] >= x){
            ans = arr[mid];
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x){
    int f = findFloor(arr, n, x);
    int c = findCeil(arr, n, x);
    return make_pair(f, c);
}
// Given an array nums of n integers, where nums[i] represents the number of pages
// in the i-th book, and an integer m representing the number of students, allocate
// all the books to the students so that each student gets at least one book, 
// each book is allocated to only one student, and the allocation is contiguous.
// Allocate the books to m students in such a way that the maximum number of pages
// assigned to a student is minimized. If the allocation of books is not possible,
// return -1.
#include <bits/stdc++.h>
using namespace std;    

// brute force approach
// time: O(sum(arr[]) * (max(nums[]) - min(nums[])))
// space: O(1)
int cntStudents(vector<int>& arr, int pages){
    int n = arr.size();
    int students = 1; // start with one student
    long long pagesPerStudent = 0; // pages assigned to the current student
    for(int i=0;i<n;i++){
        if(pagesPerStudent + arr[i] <= pages){
            pagesPerStudent += arr[i]; // add pages to current student
        }
        else{
            students++; // assign a new student
            pagesPerStudent = arr[i]; // assign the current book to the new student
        }
    }
    return students; // return the number of students required for the allocation
}
int findPages(vector<int>& arr, int n, int m){
    // book allocation is not possible
    if(n < m) return -1; // if number of books is less than number of students, return -1
    int low = *max_element(arr.begin(), arr.end()); // minimum pages a student can read
    int high = accumulate(arr.begin(), arr.end(), 0); // maximum pages a student

    for(int pages=low;pages<=high;pages++){
        if(cntStudents(arr, pages) == m)
            return pages; // return the minimum pages a student can read
    }
    return low; // if no allocation is possible
}

// binary search approach
// time: O(sum(arr[]) * log(max(nums[]) - min(nums[])))
// space: O(1)
int cntStudents2(vector<int>& arr, int pages){
    int n = arr.size();
    int students = 1; // start with one student
    long long pagesPerStudent = 0; // pages assigned to the current student
    for(int i=0;i<n;i++){
        if(pagesPerStudent + arr[i] <= pages){
            pagesPerStudent += arr[i]; // add pages to current student
        }
        else{
            students++; // assign a new student
            pagesPerStudent = arr[i]; // assign the current book to the new student
        }
    }
    return students; // return the number of students required for the allocation
}
int findPages2(vector<int>& arr, int n, int m){
    // book allocation is not possible
    if(n < m) return -1; // if number of books is less than number of students, return -1
    int low = *max_element(arr.begin(), arr.end()); // minimum pages a student can read
    int high = accumulate(arr.begin(), arr.end(), 0); // maximum pages a student can read
    int ans = -1; // to store the answer
    while(low <= high){
        int mid = low + (high - low)/2; // mid is the maximum pages a student can read
        int students = cntStudents2(arr, mid); // count the number of students required for the
        if(students <= m){ // if the number of students required is less than or equal to m
            ans = mid; // update the answer
            high = mid - 1; // search in the left half
        }
        else{
            low = mid + 1; // search in the right half
        }
    }
    return ans; // return the answer
}
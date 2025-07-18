// C. I Will Definitely Make It
// time limit per test1 second
// memory limit per test256 megabytes
// You are given 𝑛
//  towers, numbered from 1
//  to 𝑛
// . Tower 𝑖
//  has a height of ℎ𝑖
// . At time 0
// , you are on the tower with index 𝑘
// , and the current water level is 1
// .

// Every second, the water level rises by 1
//  unit. At any moment, if the water level becomes strictly greater than the height of the tower you are on, you perish.

// You have a magical ability: at moment 𝑥
// , you can start teleporting from tower 𝑖
//  to tower 𝑗
// , which will take |ℎ𝑖−ℎ𝑗|
//  seconds. That is, until moment 𝑥+|ℎ𝑖−ℎ𝑗|
// , you will be on tower 𝑖
// , and at moment 𝑥+|ℎ𝑖−ℎ𝑗|
// , you will move to tower 𝑗
// . You can start a new teleportation at the same moment you just arrived at tower 𝑗
// .

// For example, if 𝑛=𝑘=4
// , ℎ=[4,4,4,2]
// , then if you start teleporting from tower 4
//  to tower 1
//  at moment 0
// , the movement will look as follows:


// Note that if the height of tower 1
//  were 5
// , you would not be able to teleport to it immediately, as you would be submerged at moment 2
// .

// Your goal is to reach any tower with the maximum height before the water covers you.

// Determine if this is possible.

// Input
// Each test consists of several test cases. The first line contains a single integer 𝑡
//  (1≤𝑡≤104
// ) — the number of test cases. The description of the test cases follows.

// The first line of each test case contains two integers 𝑛
//  and 𝑘
//  (1≤𝑘≤𝑛≤105
// ) — the number of towers and the index of the tower you are initially on.

// The second line contains 𝑛
//  integers ℎ1,ℎ2,…,ℎ𝑛
//  (1≤ℎ𝑖≤109
// ) — the heights of the towers.

// It is guaranteed that the sum of all 𝑛
//  across all test cases does not exceed 105
// .

// Output
// For each test case, output one line: "YES", if you can reach the tower with the maximum height before the water covers you, or "NO" otherwise.

// You may output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.

// Example
// InputCopy
// 5
// 5 3
// 3 2 1 4 5
// 3 1
// 1 3 4
// 4 4
// 4 4 4 2
// 6 2
// 2 3 6 9 1 2
// 4 2
// 1 2 5 6
// OutputCopy
// YES
// NO
// YES
// YES
// NO
// Note
// In the first test case, the only possible path is: 3→2→1→4→5
// .

// In the second test case, regardless of the order, it will not be possible to reach the tallest tower.

// In the third test case, one of the possible paths is: 4→1
// .




#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < n; i++)

const int MOD = 1e9 + 7;

bool solve(vi& h, int n, int k){
    int max_height = *max_element(h.begin(), h.end());
    
    // If we start at max height, we're already done
    if(h[k-1] == max_height) return true;
    
    // BFS with state (tower_index, arrival_time)
    queue<pair<int, int>> q;
    vector<int> best_time(n, INT_MAX); // best arrival time for each tower
    
    q.push({k-1, 0});
    best_time[k-1] = 0;
    
    while(!q.empty()){
        auto [curr_tower, curr_time] = q.front();
        q.pop();
        
        // Skip if we've found a better path to this tower
        if(curr_time > best_time[curr_tower]) continue;
        
        // Try teleporting to all other towers
        for(int next_tower = 0; next_tower < n; next_tower++){
            if(next_tower == curr_tower) continue;
            
            int travel_time = abs(h[curr_tower] - h[next_tower]);
            int arrival_time = curr_time + travel_time;
            
            // Check if we can survive the teleportation:
            // 1. We must survive on current tower until we start teleporting
            // 2. We must arrive at next tower before water level exceeds its height
            if(curr_time + 1 <= h[curr_tower] && arrival_time + 1 <= h[next_tower]){
                // If this is a better path to next_tower, update it
                if(arrival_time < best_time[next_tower]){
                    best_time[next_tower] = arrival_time;
                    q.push({next_tower, arrival_time});
                    
                    // Early termination if we reached max height
                    if(h[next_tower] == max_height) return true;
                }
            }
        }
    }
    
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        vi h(n);
        rep(i, n){
            cin >> h[i];
        }
        cout << (solve(h, n, k) ? "YES" : "NO") << endl;
    }
    
    return 0;
}
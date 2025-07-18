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
#include<bits/stdc++.h>
using namespace std;

bool matchesPattern(const vector<int>& a, int startBlock, int n){
    int m = a.size();
    int k = startBlock; // current block length
    int cur = a[0]; // current value inside block
    int idx = 0; // index in pattern a

    while(idx < m){
        if(a[idx] != cur)
            return false;

        idx++;

        if(idx == m) break; // matched the whole pattern
        // move to next position
        if(cur == k){
            k++;
            cur = 1;
        }
        else{
            cur++;
        }

        if(k > n) return false; // ran out of blocks
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for(int i=0;i<m;i++)
            cin >> a[i];

        int ans = 0;
        // the patten can only start in blocks >= a[0]
        for(int startBlock=a[0];startBlock<=n;startBlock++){
            if(matchesPattern(a, startBlock, n)){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
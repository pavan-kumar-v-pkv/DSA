#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        
        long long maxDiff = 0;
        // Pair adjacent elements: (a[0], a[1]), (a[2], a[3]), ..., (a[n-2], a[n-1])
        for(int i = 0; i < n; i += 2){
            maxDiff = max(maxDiff, a[i+1] - a[i]);
        }
        
        cout << maxDiff << "\n";
    }
    return 0;
}
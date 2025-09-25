// Here’s how I understood the problem in simple words 👇

// We are building a big sequence b by writing numbers like this:

// 1
// 1 2
// 1 2 3
// ...
// 1 2 3 ... n


// and then joining them all together into one long array.

// Example for n = 4:

// b = [1, 1 2, 1 2 3, 1 2 3 4]
//   = [1, 1,2, 1,2,3, 1,2,3,4]


// James has a favorite sequence of numbers a = [a1, a2, …, am].
// He wants to know: how many times does this sequence appear as a contiguous subarray inside b?

// Important notes:

// James is sure that a appears at least once (so answer ≥ 1).

// Subarray = continuous slice of b.

// We should not actually build the huge array b (because n can be up to 100,000, and b’s length can be ~n²/2, which is enormous). Instead, we must reason about the structure of b.

// Key idea of structure:

// b is made up of blocks:

// Block 1 = [1]

// Block 2 = [1,2]

// Block 3 = [1,2,3]

// …

// Block k = [1,2,3,…,k]

// When looking for a sequence a inside b, it must either:

// Lie completely inside one block (like [2,3] inside block [1,2,3,4]), or

// Cross the boundary between blocks (for example [3,1,2] at the end of block 3 and start of block 4).

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
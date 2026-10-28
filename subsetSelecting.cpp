#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Checks if we can form valid groups to achieve a MEX of X
bool check(int X, int n, int k, const vector<int>& original_cnt) {
    vector<int> c = original_cnt;
    
    // We need to form groups with maximums 0, 1, ..., X - 1
    for (int v = 0; v < X; ++v) {
        // We need at least one element of value v to act as the maximum
        if (c[v] <= 0) return false;
        c[v]--; // Consume one element for the maximum
        
        // We need k - 1 additional fillers which can be any elements <= v
        int needed = k - 1;
        for (int i = 0; i <= v && needed > 0; ++i) {
            int take = min(c[i], needed);
            c[i] -= take;
            needed -= take;
        }
        
        // If we couldn't find enough fillers, this X is impossible
        if (needed > 0) return false;
    }
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a <= n) {
            cnt[a]++;
        }
    }

    // Binary search for the maximum possible MEX value
    int low = 0, high = n + 1;
    int ans = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid, n, k, cnt)) {
            ans = mid;
            low = mid + 1; // Try for a larger MEX
        } else {
            high = mid - 1; // Try a smaller MEX
        }
    }
    
    cout << ans << "\n";
}

int main() {
    // Optimize standard input/output streams for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
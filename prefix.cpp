#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Base case after index 0 (1-based index 1)
    long long mn = a[0];
    long long mx = a[0];
    long long ans = a[0];

    for (int i = 1; i < n; ++i) {
        // Maximum possible value for current element a[i] using extreme prefix sums
        long long max_abs_s = max(abs(mn), abs(mx));
        ans = max(ans, a[i] + max_abs_s);

        // Next prefix sum S_i can be: a[i], a[i] + S_{i-1}, or a[i] + 2 * S_{i-1}
        // Since coefficients of S_{i-1} (0, 1, 2) are >= 0, extremes come from mn and mx
        long long next_mn = min({a[i], a[i] + mn, a[i] + 2 * mn});
        long long next_mx = max({a[i], a[i] + mx, a[i] + 2 * mx});

        mn = next_mn;
        mx = next_mx;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
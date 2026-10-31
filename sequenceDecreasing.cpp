#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int min_val = 2e9; // Start with a value larger than max possible a_i
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        min_val = min(min_val, x);
    }
    
    if (min_val <= n - 1) {
        cout << n << "\n";
    } else {
        cout << 0 << "\n";
    }
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
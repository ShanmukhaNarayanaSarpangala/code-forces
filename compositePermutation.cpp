#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    // For n <= 3, there are no composite numbers available for p[1]
    if (n <= 3) {
        cout << -1 << "\n";
        return;
    }

    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }

    // Swap 1 and 4 so that 1*p[1] = 4 and 4*p[4] = 4 (both composite)
    swap(p[1], p[4]);

    for (int i = 1; i <= n; ++i) {
        cout << p[i] << (i == n ? "" : " ");
    }
    cout << "\n";
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
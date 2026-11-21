#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    long long c0 = 0, c1 = 0;
    for (char ch : s) {
        if (ch == '0') c0++;
        else c1++;
    }

    long long a = min(n, max(c0, c1) + k);
    long long b = n - a;

    long long ans = 1 + (a * (a + 1)) / 2 + (b * (b + 1)) / 2;
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
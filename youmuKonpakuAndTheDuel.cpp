#include <iostream>

using namespace std;

void solve() {
    long long x;
    cin >> x;

    for (long long m = 1; ; ++m) {
        long long a = (m + 2) / 3;
        long long c = m - a;
        long long max_damage = a * (c + 1) - a * (a - 1) / 2;

        if (max_damage >= x) {
            cout << m << "\n";
            return;
        }
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
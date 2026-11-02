#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string p, q;
    cin >> p >> q;

    // The length of the remaining numerator must be exactly 3 ("six")
    if (n - m != 3) {
        cout << "NO\n";
        return;
    }

    vector<int> countP(26, 0), countQ(26, 0);
    for (char c : p) countP[c - 'a']++;
    for (char c : q) countQ[c - 'a']++;

    // Check if 's', 'i', and 'x' have exactly 1 extra occurrence in p
    if (countP['s' - 'a'] - countQ['s' - 'a'] != 1 ||
        countP['i' - 'a'] - countQ['i' - 'a'] != 1 ||
        countP['x' - 'a'] - countQ['x' - 'a'] != 1) {
        cout << "NO\n";
        return;
    }

    // Check all other characters to ensure they cancel out completely
    for (int i = 0; i < 26; ++i) {
        if (i == 's' - 'a' || i == 'i' - 'a' || i == 'x' - 'a') continue;
        if (countP[i] != countQ[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
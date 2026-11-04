#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int x, y, z;
    cin >> x >> y >> z;
    int n = x + y + z;

    // Iterate through all possible counts of Bob's moves
    // a: Rock, b: Scissors, c: Paper
    for (int a = 0; a <= n; ++a) {
        for (int b = 0; b <= n - a; ++b) {
            int c = n - a - b;

            // Alice greedily takes all possible wins
            int wa = min(x, b) + min(y, c) + min(z, a);

            // Remaining moves for Alice
            int rem_x = x - min(x, b);
            int rem_y = y - min(y, c);
            int rem_z = z - min(z, a);

            // Remaining moves for Bob
            int rem_a = a - min(z, a);
            int rem_b = b - min(x, b);
            int rem_c = c - min(y, c);

            // Alice greedily forces draws with the remaining moves
            int draws = min(rem_x, rem_a) + min(rem_y, rem_b) + min(rem_z, rem_c);

            // Bob's wins are whatever is left over
            int wb = n - wa - draws;

            // If condition is met, print the sequence and return
            if (wb >= wa) {
                string ans = string(a, 'R') + string(b, 'S') + string(c, 'P');
                cout << ans << "\n";
                return;
            }
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
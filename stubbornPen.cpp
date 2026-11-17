#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    char current = 'R';
    int switches = 0;

    for (char target : s) {
        // Manual switch needed if the pen isn't on the target color
        if (current != target) {
            switches++;
            current = target;
        }
        // Pen automatically switches color after writing a letter
        current = (current == 'R') ? 'B' : 'R';
    }

    cout << switches << "\n";
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
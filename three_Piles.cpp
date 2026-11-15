#include <iostream>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    
    // Check if the middle pile equals the average, 
    // and the largest pile is exactly 1 greater than the middle pile.
    if (b - a == 1 && c - b == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
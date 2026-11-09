#include <iostream>
 
using namespace std;
 
void solve() {
    long long n;
    cin >> n;
    long long half = n / 2;
    long long ans = half * (n - half);
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
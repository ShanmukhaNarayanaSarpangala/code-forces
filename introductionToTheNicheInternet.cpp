#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the donations in ascending order
    sort(a.begin(), a.end());
    
    // Find the maximum element and its frequency
    int max_val = a.back();
    int count_max = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == max_val) {
            count_max++;
        } else {
            break;
        }
    }
    
    // If the maximum element appears more than k times, it's impossible 
    // because all instances of the maximum element will ALWAYS be very pleasant.
    if (count_max > k) {
        cout << "NO\n";
        return;
    }
    
    cout << "YES\n";
    
    // 1. Print the largest k elements in ASCENDING order.
    // This guarantees exactly k very pleasant donations.
    for (int i = n - k; i < n; ++i) {
        cout << a[i] << " ";
    }
    
    // 2. Print the remaining n-k elements in DESCENDING order.
    // Since they are strictly smaller than the prefix average and decreasing,
    // none of them will be very pleasant.
    for (int i = n - k - 1; i >= 0; --i) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
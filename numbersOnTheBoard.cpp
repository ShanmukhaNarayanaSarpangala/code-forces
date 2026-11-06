#include <iostream>
#include <algorithm>

void solve() {
    int l, r;
    std::cin >> l >> r;

    int total_numbers = r - l + 1;

    // Case 1: 0 is not in the range [l, r]
    // All numbers have the same sign; the only way to have sum 0 
    // for the remaining elements is to keep exactly 1 number.
    if (l > 0 || r < 0) {
        std::cout << total_numbers - 1 << "\n";
        return;
    }

    // Case 2: 0 is in the range [l, r]
    int k = std::min(-l, r);

    int max_kept;
    if (-l == r) {
        // Entire range is symmetric: [-k, k]
        max_kept = 2 * k + 1;
    } else {
        // Range has extra elements outside [-k, k].
        // We can keep all numbers in [-k, k] (sum = 0) plus one extra element x.
        max_kept = 2 * k + 2;
    }

    std::cout << total_numbers - max_kept << "\n";
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
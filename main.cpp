#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    map<int,int> mp; // start -> end, disjoint intervals
    for (int i = 0; i < n; ++i) {
        char op;
        cin >> op;
        if (op == 'A') {
            int l, r;
            cin >> l >> r;
            // find first with start >= l
            auto it = mp.lower_bound(l);
            // extend to previous if it overlaps
            if (it != mp.begin()) {
                auto pit = prev(it);
                if (pit->second >= l) it = pit; // include previous overlapping interval
            }
            // find end exclusive: first with start > r
            auto it2 = mp.upper_bound(r);
            // count to delete
            long long del = 0;
            for (auto x = it; x != it2; ++x) ++del;
            // erase range if valid (ensure iterators in order)
            if (del > 0) mp.erase(it, it2);
            mp.emplace(l, r);
            cout << del << "\n";
        } else if (op == 'B') {
            cout << mp.size() << "\n";
        } else {
            // consume rest of line if unexpected
            string rest;
            getline(cin, rest);
            cout << 0 << "\n";
        }
    }
    return 0;
}

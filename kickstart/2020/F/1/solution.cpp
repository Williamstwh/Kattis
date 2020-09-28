#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, x, arr[N];

string solve() {
    set<pair<int, int>> s;

    for (int i = 1; i <= n; i++) {
        int amount = arr[i] / x;
        if (arr[i] % x > 0) amount++;

        s.insert(pair<int, int>{ amount, i });
    }

    stringstream ss;
    for (auto p : s) {
        ss << ' ';
        ss << p.second;
    }

    return ss.str();
}

int main() {
    int t;
    cin >> t;

    int tc = 0;

    while (t--) {

        cin >> n >> x;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        cout << "Case #" << ++tc << ":" << solve() << '\n';
    }
}
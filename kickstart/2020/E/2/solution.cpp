#include <bits/stdc++.h>

using namespace std;

int n, a, b, c;

string solve() {
    vector<int> res;

    if (a + b - c > n) {
        return "IMPOSSIBLE";
    }
}

int main() {
    int t;
    cin >> t;

    int tc = 0;

    while (t--) {
        cin >> n >> a >> b >> c;

        cout << "Case #" << ++tc << ": " << solve() << '\n';
    }
}
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, k, sArr[N], eArr[N];

int solve() {
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        s.insert(pair<int, int>{sArr[i], eArr[i]});
    }

    int count = 0;
    int start = -k;
    for (auto& p : s) {
        if (p.first > (start + k)) {
            start = p.first;
            count++;
        }

        if (p.second > (start + k)) {
            int diff = p.second - (start + k);
            int c = diff / k;
            if (diff % k > 0) c++;

            start = start + c * k;
            count += c;
        }
//        cout << '\n' << '[' << start << ',' << start + k << "] : " << '(' << p.first << ',' << p.second << ')' << '\n';
    }

    return count;
}

int main() {
    int t;
    cin >> t;

    int tc = 0;

    while (t--) {

        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            cin >> sArr[i] >> eArr[i];
        }

        cout << "Case #" << ++tc << ": " << solve() << '\n';
    }
}
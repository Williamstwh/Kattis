#define INPUT "1.in"
#define DEBUG 1

#include <bits/stdc++.h>

using namespace std;

#ifndef ENABLE_DEBUG
#define DEBUG 0
#endif
#if DEBUG == 1
#define DE(x) x;
#else
#define DE(x)
#endif

#define IOSBASE ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define umap unordered_map
#define uset unordered_set
#define mst(a,b) memset((a),(b),sizeof(a))
#define mp(a,b) make_pair(a,b)
#define pi acos(-1)
#define pii pair<int,int>
#define pb push_back
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const ll mod = 1e9 + 7;

const ll N = 1e9;

pair<ll, ll> rec(string s, int& i) {
    if (i == s.size() || s[i] == ')') {
        return {0ll, 0ll};
    }

    char c = s[i];

    int n = c - 48;

    ll x = 0ll, y = 0ll;
    if (2 <= n && n <= 9) {
        // Opening bracket
        i++;

        // Start of inner string
        i++;
        auto p = rec(s, i);

        x = (((p.first + N) % N) * n) % N;
        y = (((p.second + N) % N) * n) % N;
    } else {
        if (c == 'N') {
            y = -1;
        }

        if (c == 'S') {
            y = 1;
        }

        if (c == 'W') {
            x = -1;
        }

        if (c == 'E') {
            x = 1;
        }
    }

    i++;
    auto p = rec(s, i);

    return { (x + p.first + N) % N, (y + p.second + N) % N };
}

void solve() {
    string s;
    cin >> s;

    int i = 0;
    auto p = rec(s, i);
    cout << p.first + 1 << ' ' << p.second + 1;
}

int main() {
#ifdef READ_STDIN_FROM_FILE
    freopen(INPUT, "r", stdin);
#endif
    IOSBASE;
    int t, tc = 0;
    cin >> t;

    while (t--) {
        cout << "Case #" << ++tc << ": ";
        solve();
        cout << '\n';
    }
    return 0;
}

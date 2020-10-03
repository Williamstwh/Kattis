#define INPUT "2.in"
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
#define mst(a,b) memset((a),(b),sizeof(a))
#define mp(a,b) make_pair(a,b)
#define pi acos(-1)
#define pii pair<int,int>
#define pb push_back
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const ll mod = 1e9 + 7;

void solve() {
    int n, q, a, b;
    cin >> n >> q;

    string s;

    int time = 0;
    int current = 0;
    vector<int> val(n);
    vector<int> timestamp(n, 0);

    while (q--) {
        cin >> s;

        if (s == "RESTART") {
            cin >> current;
            time++;
        } else if (s == "SET") {
            cin >> a >> b;
            val[a] = b;
            timestamp[a] = time;
        } else {
            cin >> a;
            if (timestamp[a] == time) {
                cout << val[a] << '\n';
            } else {
                val[a] = current;
                timestamp[a] = time;
                cout << current << '\n';
            }
        }
    }
}

int main() {
#ifdef READ_STDIN_FROM_FILE
    freopen(INPUT, "r", stdin);
#endif
    IOSBASE;
    solve();
    return 0;
}

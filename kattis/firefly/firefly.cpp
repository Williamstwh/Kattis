#define INPUT "3.in"
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

const int N = 200000 + 5, H = 500000 + 5;

void solve() {
    int n, h;
    cin >> n >> h;

    vector<int> fb(h + 1, 0), ft(h + 1, 0);

    for (int i = 1; i <= n / 2; i++) {
        int x, y;
        cin >> x >> y;
        fb[x]++;
        ft[y]++;
    }

    for (int i = h - 1; i >= 1; i--) {
        fb[i] += fb[i + 1];
        ft[i] += ft[i + 1];
    }

    int m = INT_MAX;
    int count = 0;

    for (int i = 1; i <= h; i++) {
        auto o = fb[i] + ft[h - i + 1];
        DE(cout << "====\ni: " <<  i << '\n');
        DE(cout << "fb: " <<  fb[i] << '\n');
        DE(cout << "ft: " <<  ft[h - i + 1] << '\n');
        if (o < m) {
            m = o;
            count = 1;
        } else if (o == m) {
            count++;
        }
    }
    cout << m << " " << count << '\n';
}

int main() {
#ifdef READ_STDIN_FROM_FILE
    freopen(INPUT, "r", stdin);
#endif
    IOSBASE;
    solve();
    return 0;
}

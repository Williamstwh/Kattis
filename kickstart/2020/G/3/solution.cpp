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

const int W = 1e5 + 5;

unsigned long long arr[W];

int w, n;

ull cost(ull x) {
    ull c = 0;

    for (int i = 0; i < w; i++){
        if (arr[i] > x) {
            c += min(arr[i] - x, x + n - arr[i]);
        } else {
            c += min(x - arr[i], arr[i] + n - x);
        }
    }

    return c;
}

void solve() {
    cin >> w >> n;

    for (int i = 0; i < w; i++) {
        cin >> arr[i];
        arr[i]--;
    }

    ull m = 1e9;
    for (ull x = 0; x < n; x++) {
        m = min(m, cost(x));
    }

    cout << m;
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

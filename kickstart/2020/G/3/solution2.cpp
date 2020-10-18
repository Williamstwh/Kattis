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

vector<pii> getOverlapping(vector<pii> v1, vector<pii> v2) {
    vector<pii> res;

    for (auto p1 : v1) {
        for (auto p2 : v2) {
            if (p1.second < p2.first || p2.second < p1.first) {
                continue;
            }

            res.push_back({ max(p1.first, p2.first), min(p1.second, p2.second) });
        }
    }

    return res;
}

bool can(int d) {
    vector<pii> v;

    int x = arr[0];
    int l = x - d;
    int u = x + d;

    for (int i = 1; i < w; i++) {
        int x = arr[i];
        int l = x - d;
        int u = x + d;
        if (l < 0) {

        } else if (u > 0) {

        } else {

        }
    }
}

void solve() {
    cin >> w >> n;

    for (int i = 0; i < w; i++) {
        cin >> arr[i];
        arr[i]--;
    }

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

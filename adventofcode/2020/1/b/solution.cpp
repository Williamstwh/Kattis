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
#define mst(a,b) memset((a),(b),sizeof(a))
#define mp(a,b) make_pair(a,b)
#define pi acos(-1)
#define pii pair<int,int>
#define pb push_back
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const ll mod = 1e9 + 7;

void solve() {
    int x;

    vector<int> v;
    while (cin >> x) {
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    for (int k = 0; k < v.size() - 2; k++) {
        int i = k + 1;
        int j = v.size() - 1;
        while (i < j) {
            int s = v[k] + v[i] + v[j];
            if (s > 2020) {
                j--;
            } else if (s < 2020) {
                i++;
            } else {
                cout << v[k] << '\n';
                cout << v[i] << '\n';
                cout << v[j] << '\n';
                cout << v[i] * v[j] * v[k] << '\n';
                break;
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

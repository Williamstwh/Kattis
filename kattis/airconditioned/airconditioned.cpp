#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define mst(a,b) memset((a),(b),sizeof(a))
#define mp(a,b) make_pair(a,b)
#define pi acos(-1)
#define pii pair<int,int>
#define pb push_back
#define IOSBASE ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const ll mod = 1e9 + 7;

pii arr[101];

int n;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = mp(a, b);
    }

    sort(arr, arr + n, [](pii& x, pii& y) {
        if (x.second == y.second) {
            return x.first < y.first;
        }

        return x.second < y.second;
    });

    int count = 0, e = 0;
    for (int i = 0; i < n; i++) {
        pii& p = arr[i];
        if (p.first > e) {
            e = p.second;
            count++;
        }
    }
    cout << count << '\n';
}

int main() {
#ifdef READ_STDIN_FROM_FILE
    freopen("1.in", "r", stdin);
#endif
    IOSBASE;
    solve();
    return 0;
}

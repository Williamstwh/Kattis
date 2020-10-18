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

ull total;
int c;

vector<int> merge(vector<int> v, int i) {
    int s = v[i] + v[i + 1];
//    DE(cout << s << '\n');
    total += s;
    v[i] += v[i + 1];
    v.erase(v.begin() + i + 1);
    return v;
}

void pvector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

void rec(vector<int> v) {
    DE(pvector(v));
    if (v.size() == 1) {
        c++;
        return;
    }

    for (int i = 0; i < v.size() - 1; i++) {
        rec(merge(v, i));
    }
}

int fact(int n) {
    if (n <= 1) {
        return 1;
    }

    return n * fact(n - 1);
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    total = 0;
    c = 0;
    rec(v);
    cout << setprecision(9) << fixed << (double) (total) / (double) (c);
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

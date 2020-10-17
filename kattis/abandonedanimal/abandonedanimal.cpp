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

int n, k, m;
vector<unordered_set<string>> storeItems;
vector<string> listItems;
unordered_map<int, unordered_map<int, int>> stored;

int count() {
    // Number of paths up to and including m
    vector<int> paths(m + 1, 0);

    for (auto& store : storeItems) {
        if (store.find(listItems[0]) != store.end()) {
            paths[0]++;
        }
    }

    return paths[m];
}

void solve() {
    int i;
    string s, t;

    cin >> n;
    cin >> k;

    storeItems = vector<unordered_set<string>>(n, unordered_set<string>());

    for (int j = 0; j < k; j++) {
        cin >> i >> s;
        storeItems[i].insert(s);
    }

    cin >> m;

    for (int j = 0; j < m; j++) {
        cin >> t;
        listItems.push_back(t);
    }

    int res = count();
    DE(cout << res << '\n')
    if (res == 0) {
        cout << "impossible";
    } else if (res == 1) {
        cout << "unique";
    } else {
        cout << "ambiguous";
    }
    cout << '\n';
}

int main() {
#ifdef READ_STDIN_FROM_FILE
    freopen(INPUT, "r", stdin);
#endif
    IOSBASE;
    vector<int> v{1, 2, 3, 4};
    solve();
    return 0;
}

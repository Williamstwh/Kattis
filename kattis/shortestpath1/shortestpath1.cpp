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
#define pii pair<ll,ll>
#define pb push_back
const ll INF = 0x3f3f3f3f;
const double eps = 1e-6;
const ll mod = 1e9 + 7;

ll n, m, q, s;

void solve() {
    while (true) {
        cin >> n >> m >> q >> s;
        if (n + m + q + s == 0) break;

        vector<vector<pair<ll, ll>>> graph(n);
        vector<ll> d(n, INF);

        for(ll i = 0; i < m; i++) {
            ll u, v, w;
            cin >> u >> v >> w;

            graph[u].push_back({v, w });
        }

        queue<ll> next;
        next.push(s);
        d[s] = 0;

        while(!next.empty()) {
            ll curr = next.front();
            next.pop();

            for(auto p : graph[curr]) {
                ll dest = p.first;
                ll weight = p.second;
                if(d[curr] + weight < d[dest]) {
                    d[dest] = d[curr] + weight;
                    next.push(dest);
                }
            }
        }

        for(ll i = 0; i < q; i++) {
            ll query;
            cin >> query;
            ll val = d[query];

            if(val == INF) {
                cout << "Impossible" << endl;
            }
            else {
                cout << val << endl;
            }
        }

        cout << '\n';
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

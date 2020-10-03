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

int n;

map<int, array<int, 3>> tree;
map<int, ull> favStories;

ull dfs(int p) {
    if (favStories.find(p) != favStories.end()) {
        return favStories[p];
    }

    auto& vertices = tree[p];
    ull count = 0;
    for (int v : vertices) {
        count += dfs(v);
    }

    favStories[p] = count;
    return count;
}

void solve() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            int a, b, c;
            string s;

            cin >> x;

            cin >> s;
            if (s == "favourably") {
                favStories[x] = 1;
            } else if (s == "catastrophically") {
                favStories[x] = 0;
            } else {
                a = stoi(s);
                cin >> b;
                cin >> c;
                tree[x] = array<int, 3>{ a, b, c };
            }
        }

        cout << dfs(1) << '\n';

        tree.clear();
        favStories.clear();
    }
}

int main() {
#ifdef READ_STDIN_FROM_FILE
    freopen("1.in", "r", stdin);
#endif
    IOSBASE;
    solve();
    return 0;
}

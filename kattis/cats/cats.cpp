#define INPUT "1.in"
#define DEBUG 1

#include <bits/stdc++.h>

using namespace std;

#ifndef ENABLE_DEBUG
#define DEBUG 0
#endif
#if DEBUG == 1
#define DE(x) (x);
#else
#define DE(x)
#endif

#define IOSBASE ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define mst(a, b) memset((a),(b),sizeof(a))
#define mp(a, b) make_pair(a,b)
#define pi acos(-1)
#define pii pair<int,int>
#define pb push_back
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const ll mod = 1e9 + 7;

class UFDS {
private:
    vector<int> p, rank, setSizes;
    int numSets;
public:
    UFDS(int N) {
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
        setSizes.assign(N, 1);
    }

    int findSet(int i) {
        return (p[i] == i) ? i : p[i] = findSet(p[i]);
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) {
                setSizes[findSet(x)] += setSizes[findSet(y)];
                p[y] = x;
            } else {
                setSizes[findSet(y)] += setSizes[findSet(x)];
                p[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
            }
            numSets--;
        }
    }

    int setSize(int i) {
        return setSizes[findSet(i)];
    }

    int numDisjointSets() {
        return numSets;
    }
};

int n;

int MST(UFDS &vertices, multimap<int, pair<int, int>> &edges) {
    int res = 0;

    for (auto &edge : edges) {
        int d = edge.first;
        auto &p = edge.second;

        DE(cout << "(" << p.first << ", " << p.second << "): " << d);
        if (!vertices.isSameSet(p.first, p.second)) {
            DE(cout << " SELECTED");
            vertices.unionSet(p.first, p.second);
            res += d;
        }
        DE(cout << "\n");
        if (vertices.numDisjointSets() == 1) {
            return res;
        }
    }

    return res;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int m, c;
        cin >> m >> c;

        UFDS vertices(c);
        multimap<int, pair<int, int>> edges;

        int i, j, d;
        for (int k = 0, l = c * (c - 1) / 2; k < l; k++) {
            cin >> i >> j >> d;
            edges.insert({d, {i, j}});
        }

        cout << (MST(vertices, edges) + c <= m ? "yes" : "no") << '\n';
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

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

map<int, int> f{
    {1, 1},
    {2, 2},
    {3, -1},
    {4, -1},
    {5, 5},
    {6, 9},
    {7, -1},
    {8, 8},
    {9, 6},
    {0, 0},
};

int flip(int x) {
    int res = 0;
    while (x != 0) {
        int d = f[x % 10];
        if (d == -1) return -1;
        res = 10 * res + d;
        x /= 10;
    }
    return res;
}

void solve() {
    int n, s, c, v;
    cin >> n >> s;

    unordered_map<int, vector<int>> m;

    for (int i = 0; i < n; i++) {
        cin >> c;
        v = flip(c);

        if (m.find(c) != m.end()) {
            m[c].push_back(i);
        } else {
            m.insert({ c, { i } });
        }

        if (v != -1) {
            if (m.find(v) != m.end()) {
                m[v].push_back(i);
            } else {
                m.insert({ v, { i } });
            }
        }
    }

    DE(for (auto& p : m) { cout << p.first << '\n'; })

    for (const auto& p1 : m) {
        int a = p1.first;
        int b = s - a;

        if (m.find(b) != m.end()) {
            const auto& p2 = m[b];

            for (int x : p1.second) {
                for (int y : p2) {
                    if (x != y) {
                        DE(cout << a << ", " << b << '\n');
                        cout << "YES\n";
                        return;
                    }
                }
            }
        }
    }

    cout << "NO\n";
}

int main() {
#ifdef READ_STDIN_FROM_FILE
    freopen(INPUT, "r", stdin);
#endif
    IOSBASE;
    solve();
    return 0;
}

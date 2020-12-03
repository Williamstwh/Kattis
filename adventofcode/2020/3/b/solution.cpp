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

vector<string> grid;
int rows, cols;

int t(int dc, int dr) {
    int r = 0, c = 0, count = 0;
    while (r < rows) {
        if (grid[r][c] == '#') {
            count++;
        }

        r += dr;
        c = (c + dc) % cols;
    }
    cout << count << '\n';
    return count;
}

void solve() {
    string s;
    while (cin >> s) {
        grid.push_back(s);
    }
    rows = grid.size(), cols = grid[0].size();
    int ans = t(1, 1) * t(3, 1) * t(5, 1) * t(7, 1) * t(1, 2);
    cout << ans << '\n';
}

int main() {
#ifdef READ_STDIN_FROM_FILE
    freopen(INPUT, "r", stdin);
#endif
    IOSBASE;
    solve();
    return 0;
}

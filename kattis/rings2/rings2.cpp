#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define mst(a, b) memset((a),(b),sizeof(a))
#define mp(a, b) make_pair(a,b)
#define pi acos(-1)
#define pii pair<int,int>
#define pb push_back
#define IOSBASE ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const ll mod = 1e9 + 7;

const int N = 101, M = 101;

vector<string> grid;
int res[N][M];

int n, m;

void solve() {
    cin >> n >> m;

    int t = n;
    while (t--) {
        string s;
        cin >> s;
        grid.pb(s);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                res[i][j] = 0;
            } else if (i == 0 || j == 0) {
                res[i][j] = 1;
            } else {
                res[i][j] = min(res[i - 1][j], res[i][j - 1]) + 1;
            }
        }
    }

    int max_n = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (grid[i][j] == '.') {
                res[i][j] = 0;
            } else if (i == n - 1 || j == m - 1) {
                res[i][j] = 1;
            } else {
                res[i][j] = min(res[i][j], min(res[i + 1][j], res[i][j + 1]) + 1);
                max_n = max(max_n, res[i][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val = res[i][j];
            if (max_n < 10) {
                if (val == 0) {
                    cout << "..";
                } else {
                    cout << "." << val;
                }
            } else {
                if (val == 0) {
                    cout << "...";
                } else if (val < 10) {
                    cout << ".." << val;
                } else {
                    cout << "." << val;
                }
            }
        }
        cout << '\n';
    }
}

int main() {
#ifdef READ_STDIN_FROM_FILE
    freopen("3.in", "r", stdin);
#endif
    IOSBASE;
    solve();
    return 0;
}

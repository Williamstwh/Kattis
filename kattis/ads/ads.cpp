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

bool isLegalChar(char c) {
    string allowed = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ?!,. ";
    return allowed.find(c) != allowed.npos;
}

int h, w;

bool removeAdsAndCheckIfLegal(vector<string>& grid, vector<vector<bool>>& checked, int l, int u, int r, int d) {
    bool isLegal = true;
    for (int i = u; i <= d; i++) {
        for (int j = l; j <= r; j++) {
            if (checked[i][j]) {
                continue;
            }
            checked[i][j] = true;
            if (grid[i][j] == '+') {
                int a = i, b = j;
                while (b + 1 < w && grid[a][b + 1] == '+') {
                    b++;
                    checked[a][b] = true;
                }

                while (a + 1 < h && grid[a + 1][b] == '+') {
                    a++;
                    checked[a][b] = true;
                }

                a = i, b = j;
                while (a + 1 < h && grid[a + 1][b] == '+') {
                    a++;
                    checked[a][b] = true;
                }

                while (b + 1 < w && grid[a][b + 1] == '+') {
                    b++;
                    checked[a][b] = true;
                }

                if (!removeAdsAndCheckIfLegal(grid, checked, j + 1, i + 1, b - 1, a - 1)) {
                    for (int k = i; k <= a; k++) {
                        for (int m = j; m <= b; m++) {
                            grid[k][m] = ' ';
                        }
                    }
                }
            } else if (!isLegalChar(grid[i][j])) {
                isLegal = false;
            }
        }
    }
    return isLegal;
}

void solve() {
    cin >> h >> w;
    cin.ignore();

    vector<string> grid;
    string s;
    for (int i = 0; i < h; i++) {
        getline(cin, s);
        grid.push_back(s);
    }
    vector<vector<bool>> checked(h, vector<bool>(w, false));
    removeAdsAndCheckIfLegal(grid, checked,  0, 0, w - 1, h - 1);
    for (string s : grid) {
        cout << s << '\n';
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

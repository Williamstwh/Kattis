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

void solve() {
    int n, prev, t;
    double a;

    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        vector<double> amount(1440, -0.08);

        prev = 0;
        for (int i = 0; i < n; i++) {
            cin >> t >> a;
            amount[t] += a;
        }

        double maxTotal = -INFINITY;
        double total = -INFINITY;

        vector<pair<double, pii>> v;

        int start = 0;
        int end = 0;
        for (int i = 0; i < 1440; i++) {
            double x = amount[i];
            double y = total + x;


            total = max(x, y);
            if (total >= maxTotal) {
                if (x > y) {
                    start = i;
                    end = i;
                } else if (x < y) {
                    end = i;
                }
                maxTotal = max(maxTotal, total);

                v.push_back(pair<double, pii>{ maxTotal, pii{ start, end } });
            }
        }

        sort(v.begin(), v.end(), [](const pair<double, pii>& a, const pair<double, pii>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }

            const pii& ap = a.second;
            int aDiff = ap.second - ap.first;

            const pii& bp = b.second;
            int bDiff = bp.second - bp.first;

            if (aDiff < bDiff) {
                return true;
            } else if (aDiff > bDiff) {
                return false;
            }

            return ap.first < bp.first;
        });

        if (maxTotal <= 0.0) {
            cout << "no profit\n";
        } else {
            cout << fixed << setprecision(2);
            cout << v[0].first << ' ' << v[0].second.first << ' ' << v[0].second.second << '\n';
        }
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

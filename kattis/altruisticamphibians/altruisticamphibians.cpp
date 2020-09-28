#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define mst(a, b) memset((a),(b),sizeof(a ))
#define mp(a, b) make_pair(a,b)
#define pi acos(-1)
#define pii pair<int,int>
#define pb push_back
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int MAXN = 1e5 + 10;
const int MAXM = 1e8 + 10;
const ll mod = 1e9 + 7;

struct node {
    int l, w, h;
} a[MAXN];

bool cmp(node x, node y) {
    return x.w > y.w;
}

int dp[MAXM];

int main() {
#ifdef local
    freopen( "data.txt " , " r " , stdin);
//     freopen("data.txt", "w", stdout);
#endif
    mst(dp, 0);
    int n, d;
    scanf(" %d%d ", &n, &d);
    for (int i = 0; i < n; i++)
        scanf(" %d%d%d ", &a[i].l, &a[i].w, &a[i].h);
    sort(a, a + n, cmp);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dp[a[i].w] + a[i].l > d) ans++;
        int mx = min((int) 1e8 - a[i].w, a[i].w);
        for (int j = 1; j < mx; j++) {
            dp[j] = max(dp[j], dp[j + a[i].w] + a[i].h);
            if (dp[j] > MAXM) dp[j] = MAXM;
        }
    }
    printf(" %d\n", ans);
    return 0;
}
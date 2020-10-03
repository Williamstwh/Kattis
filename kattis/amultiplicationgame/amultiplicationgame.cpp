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

const ull STAN = 0;

ull n;
map<ull, bool> canWin;

ull next(ull c) {
    return (c + 1) % 2;
}

ull whoWins(ull p, ull c) {
    for (ull i = 2; i <= 9; i++) {
        // Can win in the current move
        if (p * i >= n) return c;

        // Check if can win in the current move
        if (canWin.find(p * i) != canWin.end()) {
            if (canWin[p * i]) return c;
            continue;
        }

        // check if the next move results in c's win
        canWin[p * i] = (whoWins(p * i, next(c)) == c);
        if (canWin[p * i]) return c;
    }

    return next(c);
}

void solve() {
    while (cin >> n) {
        canWin.clear();
        cout << (whoWins(1, STAN) == STAN ? "Stan" : "Ollie") << " wins.\n";
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

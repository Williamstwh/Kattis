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


void solve() {
    string s;
    cin >> s;

    ull n0s = 0;
    ull n1s = 0;
    ull nqs = 0;

    ull prev = 1;
    ull pow2 = 1;

    ull count = 0;

    for (auto c : s) {
        if (c == '1') {
            n1s++;
        }

        if (c == '0') {
            // There are 2^q sequences that end in 0
            // For each sequence, add the number of 1s seen so far
            count += (n1s * pow2 % mod);
            count %= mod;

            // There will be total of (q * 2^q) number of '?' for all sequences
            // Half of these will be 1s, so add q * 2^(q - 1)
            count += (nqs * prev % mod);
            count %= mod;

            n0s++;
        }

        if (c == '?') {
            // ? can be 1 or 0, so double previous count
            count *= 2;
            count %= mod;

            // There are 2^q sequences that end in 0
            // For each sequence, add the number of 1s seen so far
            count += (n1s * pow2 % mod);
            count %= mod;

            // There will be total of (q * 2^q) number of '?' for all sequences
            // Half of these will be 1s, so add q * 2^(q - 1)
            count += (nqs * prev % mod);
            count %= mod;

            // Double the power of q
            prev = pow2;
            pow2 *= 2;
            pow2 %= mod;

            nqs++;
        }
    }

    cout << count << '\n';
}

int main() {
#ifdef READ_STDIN_FROM_FILE
    freopen("2.in", "r", stdin);
#endif
    IOSBASE;
    solve();
    return 0;
}

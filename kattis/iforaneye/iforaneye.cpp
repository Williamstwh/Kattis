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

void solve() {
    int n;
    cin >> n;
    cin.ignore();

    unordered_map<string, string> m {
        { "at", "@" },
        { "and", "&" },
        { "one", "1" },
        { "won", "1" },
        { "to", "2" },
        { "too", "2" },
        { "two", "2" },
        { "for", "4" },
        { "four", "4" },
        { "bea", "b" },
        { "be", "b" },
        { "bee", "b" },
        { "sea", "c" },
        { "see", "c" },
        { "eye", "i" },
        { "oh", "o" },
        { "owe", "o" },
        { "are", "r" },
        { "you", "u" },
        { "why", "y" },
    };

    auto m2 = m;
    for (auto& p : m2) {
        stringstream ss;
        ss << (char) toupper(p.first[0]) << p.first.substr(1);
        string k = ss.str();

        stringstream ss2;
        ss2 << (char) toupper(p.second[0]);
        string v = ss2.str();
        m[k] = v;
    }

    for (int t = 0; t < n; t++) {
        string s;
        getline(cin, s);

        for (int i = 0; i < s.size(); i++) {
            bool found = false;
            for (int j = 4; j >= 2; j--) {
                string ss = s.substr(i, j);
//                DE(cout << ss << '\n');
                if (m.find(ss) != m.end()) {
                    cout << m[ss];
                    found = true;
                    i += j - 1;
                    break;
                }
            }

            if (!found) {
                cout << s[i];
            }
        }
        cout << '\n';
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

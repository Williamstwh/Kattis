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

void reset(map<string, bool>& m) {
    m["ecl"] = false;
    m["pid"] = false;
    m["eyr"] = false;
    m["hcl"] = false;
    m["byr"] = false;
    m["iyr"] = false;
    m["cid"] = false;
    m["hgt"] = false;
}

bool isValid(map<string, bool>& m) {
    return m["ecl"] &&
    m["pid"] &&
    m["eyr"] &&
    m["hcl"] &&
    m["byr"] &&
    m["iyr"] &&
    m["hgt"];
}

void solve() {
    map<string, bool> m;
    string s;
    reset(m);

    int count = 0;
    while (getline(cin, s)) {
        if (s == "") {
            if (isValid(m)) {
                count++;
            }
            cout << (isValid(m) ? "VALID" : "INVALID") << "\n\n";
            reset(m);
        } else {
            stringstream ss(s);
            string kvp;
            cout << s << ' ';
            while(ss >> kvp) {
                stringstream ss2(kvp);
                string key;
                getline(ss2, key, ':');
                m[key] = true;
            }
            cout << '\n';
        }
    }
    if (isValid(m)) {
        count++;
    }
    cout << (isValid(m) ? "VALID" : "INVALID") << "\n\n";
    cout << count << '\n';
}

int main() {
#ifdef READ_STDIN_FROM_FILE
    freopen(INPUT, "r", stdin);
#endif
    IOSBASE;
    solve();
    return 0;
}

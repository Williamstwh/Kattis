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


int priority(string seq) {
    vector<int> v;

    stringstream ss(seq);
    string token;
    while (getline(ss, token, '-')) {
        if (token == "upper") {
            v.push_back(2);
        } else if (token == "lower") {
            v.push_back(0);
        } else {
            v.push_back(1);
        }
    }
    reverse(v.begin(), v.end());
    while (v.size() < 10) {
        v.push_back(1);
    }
    reverse(v.begin(), v.end());

    int priority = 0;
    int f = 1;
    for (int j = 0; j < 10; j++) {
        priority += f * v[j];
        f *= 3;
    }
    return priority;
}

struct Cmp {
    bool operator() (const pair<int, string>& p1, const pair<int, string>& p2) const {
        if (p1.first == p2.first) {
            return p1.second < p2.second;
        }

        return p1.first > p2.first;
    }
};

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<pair<int, string>, Cmp> s;

        while (n--) {
            string person, seq, c;
            cin >> person >> seq >> c;
            person = person.substr(0, person.size() - 1);

            s.insert(pair<int, string>{ priority(seq), person });
        }

        for (auto& p : s) {
            cout << p.second << '\n';
        }

        cout << "==============================\n";
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

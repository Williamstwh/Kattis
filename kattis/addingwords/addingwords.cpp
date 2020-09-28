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

unordered_map<string, int> m1;
unordered_map<int, string> m2;

string evaluate(string query) {
    stringstream ss(query);
    string token;
    stack<int> stk;
    string operation = "";
    while (ss >> token) {
        if (token == "+") {
            int a, b;
            a = stk.top();
            stk.pop();

            ss >> token;
            if (m1.find(token) != m1.end()) {
                b = m1[token];
            } else {
                return "unknown";
            }

            stk.push(a + b);
        } else if (token == "-") {
            int a, b;
            a = stk.top();
            stk.pop();

            ss >> token;
            if (m1.find(token) != m1.end()) {
                b = m1[token];
            } else {
                return "unknown";
            }

            stk.push(a - b);
        } else if (token == "=") {
            if (m2.find(stk.top()) != m2.end()) {
                return m2[stk.top()];
            } else {
                return "unknown";
            }
        } else {
            if (m1.find(token) != m1.end()) {
                stk.push(m1[token]);
            } else {
                return "unknown";
            }
        }
    }

    return "unknown";
}

void solve() {
    string s;
    while (cin >> s) {
        if (s == "def") {
            string key;
            int val;
            cin >> key >> val;
            if (m1.find(key) != m1.end()) {
                m2.erase(m1[key]);
            }
            m1[key] = val;
            m2[val] = key;
        } else if (s == "calc") {
            string query;
            getline(cin, query);
            query = query.substr(1);
            cout << query << " " << evaluate(query) << '\n';
        } else {
            m1.clear();
            m2.clear();
        }
    }
}

int main() {
#ifdef READ_STDIN_FROM_FILE
    freopen("2.in", "r", stdin);
#endif
    IOSBASE;
    solve();
    return 0;
}

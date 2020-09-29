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
    int n;
    cin >> n;

    string name, sec, birth;
    int courses;
    while (n--) {
        cin >> name >> sec >> birth >> courses;
        int secyear = stoi(sec.substr(0, 4));
        int birthyear = stoi(birth.substr(0, 4));

        cout << name << ' ';

        if (secyear >= 2010 || birthyear >= 1991) {
            cout << "eligible";
        } else if (courses >= 41) {
            cout << "ineligible";
        } else {
            cout << "coach petitions";
        }
        cout << '\n';
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

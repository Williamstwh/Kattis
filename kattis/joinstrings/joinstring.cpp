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

struct Node {
    string word;
    Node *next;
};

struct Dll {
    Node *start;
    Node *end;
};

void solve() {
    int n;
    cin >> n;

    vector<Dll> v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        Node *node = new Node{ s, NULL };
        v.push_back(Dll{ node, node });
    }

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a--; b--;

        v[a].end->next = v[b].start;
        v[a].end = v[b].end;
    }

    Node* head = v[a].start;
    while (head != NULL) {
        cout << head->word;
        head = head->next;
    }
    cout << '\n';
    for (Dll & dll : v) {
        free(dll.start);
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

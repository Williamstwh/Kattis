#define INPUT "1.in"
#define DEBUG 0

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

map<string, int> m;

struct Node {
    string grid;
    int x;
    int y;
    int moves;
};

bool isValidMove(const Node* n, int x, int y) {
//    DE(cout << "x: " << x << ", y: " << y << '\n');
    if (n->moves + 1 > 10) {
        return false;
    }

    if (x < 0 || x >= 5 || y < 0 || y >= 5) return false;

    return true;
}

string move(string grid, int a, int b, int x, int y) {
    char t = grid[a * 5 + b];
    grid[a * 5 + b] = grid[x * 5 + y];
    grid[x* 5 + y] = t;
    return grid;
}

struct Diff {
    int x;
    int y;
};

void generate() {
    vector<Diff> D{
        {-2, -1},
        {-2, 1},
        {-1, -2},
        {-1, 2},
        {1, -2},
        {1, 2},
        {2, -1},
        {2, 1}
    };

    queue<Node *> q;

    q.push(new Node{
        "111110111100 110000100000",
        2,
        2,
        0
    });

    while (!q.empty()) {
        Node* n = q.front();
        q.pop();
        DE(if (n->moves <= 2) { for (int i = 0; i < 5; i++) { for (int j = 0; j < 5; j++) { cout << n->grid[i * 5 + j]; } cout << '\n'; } cout << "Moves: "<< n->moves << "\n=====\n"; });
        if (m.find(n->grid) != m.end()) {
            free(n);
            continue;
        }
        m[n->grid] = n->moves;

        for (const auto& d : D) {
            int x = n->x + d.x, y = n->y + d.y;
            if (isValidMove(n, x, y)) {
//                DE(cout << "TEST" << '\n');
                auto newGrid = move(n->grid, n->x, n->y, x, y);
                if (m.find(newGrid) != m.end()) {
                    continue;
                }
                q.push(new Node{
                    newGrid,
                    x,
                    y,
                    n->moves + 1,
                });
            }
//            DE(cout << "Queue size: " << q.size() << '\n');
        }
        free(n);
    }
}

void solve() {
    int n;
    cin >> n;
    cin.ignore();

    generate();

    DE(cout << m.size());
//    DE(for (auto& p : m) { for (auto& s: p.first) { cout << s << '\n'; } });

    while (n--) {
        string grid;
        string s;
        for (int i = 0; i < 5; i++) {
            getline(cin, s);
            grid += s;
        }

//        DE(for (auto& s: grid) { cout << s << '\n'; } cout << "=====\n"; );

        if (m.find(grid) != m.end()) {
            cout << "Solvable in " << m[grid] << " move(s)." << '\n';
        } else {
            cout << "Unsolvable in less than 11 move(s)." << '\n';
        }

        grid.clear();
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

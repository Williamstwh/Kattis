#include <bits/stdc++.h>

using namespace std;

using Int = long long;

int s, ax, ay, bx, by, c;

int pos(int r, int c) {
    return r * r + c;
}

Int encode(Int triangle, int r, int c) {
    return triangle | (1 << pos(r, c));
}

bool get(Int triangle, int r, int c) {
    return triangle & (1 << pos(r, c));
}

map<Int, int> dp[36][36];

int rec(Int triangle, int ax, int ay, int bx, int by, bool turn);

int tryout(Int triangle, int x, int y) {
    bool moved = 0;
    if (y & 1) {
        if (!get(triangle, x - 1, y - 1)) {

        }
    } else {
        if (!get(triangle, x + 1, y + 1)) {

        }
    }

    if (!get(triangle, x, y - 1)) {

    }

    if (!get(triangle, x, y + 1)) {

    }
}

int rec(Int triangle, int ax, int ay, int bx, int by, bool turn) {
    int best_score;
    if (!get(triangle, ax, ay)) {

    }
}

int solve() {
    cin >> s >> ax >> ay >> bx >> by >> c;

    Int triangle = 0ll;

    int start, end;
    for (int i = 0; i < c; i++) {
        cin >> start >> end;
        triangle = encode(triangle, start, end);
    }
}

int main() {
    int t;
    cin >> t;

    int tc = 0;

    while (t--) {
        cout << "Case #" << ++tc << ": " << solve() << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Frog {
    int l;
    int w;
    int h;
};

const int W = 2e8 + 5;

int n, d;

vector<Frog> frogs;
int height[W];

int solve() {
    memset(height, 0, sizeof(height));

    cin >> n >> d;

    for (int i = 0; i < n; i++) {
        int l, w, h;
        cin >> l >> w >> h;
        frogs.push_back(Frog{ l, w, h });
    }

    sort(frogs.begin(), frogs.end(), [](const Frog& a, const Frog& b) {
        return a.w > b.w;
    });

    int count = 0;
    for (const Frog& frog: frogs) {
        if (frog.l + height[frog.w] > d) count++;
        int mx = min((int) 1e8 - frog.w, frog.w);

        for (int w = 1; w <= mx; w++) {
            height[w] = max(height[w], height[frog.w + w] + frog.h);
            if (height[w] > 1e8 + 5) height[w] = 1e8 + 5;
        }
    }
    return count;
}

int main() {
    cout << solve() << '\n';
}

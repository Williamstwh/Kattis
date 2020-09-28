#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, arr[N];

int solve() {
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i] - arr[i + 1];
    }

    int longest = 1;
    int current = 1;

    for (int i = 1; i < n - 1; i++) {
        if (arr[i - 1] == arr[i]) {
            current++;
        } else {
            current = 1;
        }
        longest = max(longest, current);
    }

    return longest + 1;
}

int main() {
    int t;
    cin >> t;

    int tc = 0;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << "Case #" << ++tc << ": " << solve() << '\n';
    }
}
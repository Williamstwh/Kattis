#define INPUT "3.in"
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
    int n, k;
    cin >> n >> k;

    // Set up data structures
    umap<string, set<int>> itemStores;
    vector<string> items;

    // Read in first half of data
    for (int i = 0; i < k; i++) {
        int store;
        string item;
        cin >> store >> item;
        itemStores[item].insert(store);
    }

    // Keep track of input
    vector<string> input;

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string item;
        cin >> item;
        input.push_back(item);
    }

    // Get max from lo to hi
    int lastVisitedStore = 0;

    // For each item
    for (int i = 0; i < m; i++) {
        string item = input[i];
        vector<int> rem;

        // For each store that contains the item
        for (int store : itemStores[item]) {
            // If the store is before the last visited store, remove it
            if (store < lastVisitedStore) {
                rem.push_back(store);
            }
        }

        for (int store : rem) {
            itemStores[item].erase(store);
        }

        if (itemStores[item].size() > 0) {
            // First store that contains the item
            lastVisitedStore = max(*itemStores[item].begin(), lastVisitedStore);
        }
    }

    // Get min from hi to low
    lastVisitedStore = INF;
    for (int i = m - 1; i >= 0; i--) {
        string item = input[i];
        vector<int> rem;

        for (int store : itemStores[item]) {
            if (store > lastVisitedStore) {
                rem.push_back(store);
            }
        }

        for (int store : rem) {
            itemStores[item].erase(store);
        }

        if (itemStores[item].size() > 0) {
            lastVisitedStore = min(*itemStores[item].begin(), lastVisitedStore);
        }
    }

    bool works = true;
    bool ambig = false;
    for (string item : input) {
        if (itemStores[item].size() < 1) {
            works = false;
        }

        if (itemStores[item].size() > 1) {
            ambig = true;
        }
    }

    if (!works) {
        cout << "impossible" << '\n';
    } else if (ambig) {
        cout << "ambiguous" << '\n';
    } else {
        cout << "unique" << '\n';
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

#ifdef INCLUDE_HEADERS
#include <bits/stdc++.h>

using namespace std;

#endif

class Solution {
public:
    bool dp(int i, int j, string s, string p) {
        if (j >= p.size()) return i >= s.size();

        bool firstMatch = i != s.size() && (s[0] == p[0] || p[0] == '.');

        if (p.size() - j >= 2 && p[j + 1] == '*') {
            return dp(i, j + 2, s, p) || (firstMatch && dp(i + 1, j, s, p));
        }

        return firstMatch && dp(i + 1, j + 1, s, p);
    }

    bool isMatch(string s, string p) {
        return dp(0, 0, s, p);
    }
};

#ifdef INCLUDE_MAIN
int main() {
    Solution s;
    cout << (s.isMatch("aba", "aca") ? "yes" : "no") << '\n';
}
#endif

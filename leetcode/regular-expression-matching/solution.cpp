#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> visited(s.size() + 1, vector<bool>(p.size() + 1, false));
        vector<vector<bool>> matched(s.size() + 1, vector<bool>(p.size() + 1, false));
        return isMatch(s, p, visited, matched);
    }

    bool isMatch(string s, string p, vector<vector<bool>> & v, vector<vector<bool>> & m) {
        if (v[s.size()][p.size()]) {
            return v[s.size()][p.size()];
        }

        if (p == "") {
            return s.size() == 0;
        }

        if (p[0] == '.') {
            if (p.size() == 1) {
                return s.size() == 1;
            }

            if (p[1] == '*') {
                if (p.size() == 2) {
                    return true;
                }

                for (int i = 0; i < s.size(); i++) {
                    if (isMatch(s.substr(i), p.substr(2), v, m)) {
                        return true;
                    }
                }
                return false;
            }

            return isMatch(s.substr(1), p.substr(1));
        }

        if (p.size() == 1) {
            return s == p;
        }

        if (p[1] == '*') {
            if (s == "" && p.size() == 2) {
                return true;
            }

            if (s[0] == p[0]) {
                return isMatch(s.substr(1), p, v, m);
            }

            return isMatch(s, p.substr(2), v, m);
        }

        if (s[0] == p[0]) {
            return isMatch(s.substr(1), p.substr(1), v, m);
        }

        return false;
    }
};

int main() {
    Solution s;
    cout << (s.isMatch("aba", "a*a") ? "yes" : "no") << '\n';
}

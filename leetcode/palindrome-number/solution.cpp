#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        stringstream ss;
        ss << x;
        string s = ss.str();

        for (int i = 0, l = s.size(), n = l / 2; i < n; i++) {
            if (s[i] != s[l - i - 1]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    cout << (s.isPalindrome(1231) ? "yes" : "no") << '\n';
}

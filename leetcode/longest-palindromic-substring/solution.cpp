#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        string temp;
        for (int i = 0, l = s.size(); i < l; i++) {
            temp = lengthOfOddPalindromeCenteredAt(s, i);
            if (temp.size() > res.size()) {
                res = temp;
            }

            temp = lengthOfEvenPalindromeCenteredAt(s, i);
            if (temp.size() > res.size()) {
                res = temp;
            }
        }
        return res;
    }

    string lengthOfOddPalindromeCenteredAt(string s, int i) {
        int l = s.size();

        int high = i;
        int low = i;
        while (high + 1 < l && low - 1 >= 0 && s[high + 1] == s[low - 1]) {
            high++;
            low--;
        }
        return s.substr(low, high - low + 1);
    }

    string lengthOfEvenPalindromeCenteredAt(string s, int i) {
        int l = s.size();

        if (i + 1 >= l) {
            return "";
        }
        int high = i;
        int low = i + 1;
        while (high + 1 < l && low - 1 >= 0 && s[high + 1] == s[low - 1]) {
            high++;
            low--;
        }
        return s.substr(low, high - low + 1);
    }
};

int main() {
    Solution s;
    cout << s.longestPalindrome("abcddcbasd") << '\n';
}
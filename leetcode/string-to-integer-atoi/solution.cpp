#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        str = trimLeft(str);

        if (str == "") {
            return 0;
        }

        int sign = parseSign(str);

        if (str == "" || str == "0") {
            return 0;
        }

        int res = 0;
        for (int i = 0, l = str.size(); i < l; i++) {
            int n = str[i] - 48;

            if (n < 0 || n > 9) {
                if (i == 0) {
                    return 0;
                }
                return res;
            }

            if (!canAppend(sign, res, n)) {
                return sign > 0 ? 2147483647 : -2147483648;
            }

            res = res * 10 + sign * n;
        }
        return res;
    }

    string trimLeft(string str) {
        int i;
        for (i = 0; i <= str.size(); i++) {
            if (str[i] != ' ') {
                break;
            }
        }
        return str.substr(i);
    }

    int parseSign(string & str) {
        if (str[0] == '-') {
            str = str.substr(1);
            return -1;
        }

        if (str[0] == '+') {
            str = str.substr(1);
            return 1;
        }

        return 1;
    }

    bool canAppend(int sign, int res, int n) {
        if (sign > 0) {
            if ((2147483647 - n) / 10 < res) {
                return false;
            }
        }

        if (sign < 0) {
            if ((-2147483648 + n) / 10 > res) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
//    cout << s.myAtoi("   +123") << '\n';
    cout << s.myAtoi("4193 with words") << '\n';
}

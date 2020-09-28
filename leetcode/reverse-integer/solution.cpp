#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long y = (long) x;
        y = abs(y);

        long z = 0;
        while (y != 0) {
            z *= 10;
            z += y % 10;
            y /= 10;
        }

        if (z != ((long)((int) z))) {
            return 0;
        }

        return x >= 0 ? z : -z;
    }
};

int main() {
    Solution s;
    cout << s.reverse(2147483647) << '\n';
}

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int global_max = 0;

        int i = 0;
        for (int j = 0, len = s.length(); j < len; j++) {
            char c = s[j];
            // Does not contain c
            if (chars.find(c) == chars.end()) {
                // Insert into set
                chars.insert(c);
            } else {
                while (s[i] != c) {
                    chars.erase(s[i]);
                    i++;
                }
                i++;
            }
            // Set global max
            global_max = max(j - i + 1, global_max);
        }

        return global_max;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcabc") << '\n';
    cout << s.lengthOfLongestSubstring("aab") << '\n';
    cout << s.lengthOfLongestSubstring("pwwkew") << '\n';
    cout << s.lengthOfLongestSubstring("tmmuxzt") << '\n';
}
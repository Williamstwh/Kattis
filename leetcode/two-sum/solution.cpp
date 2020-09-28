#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;

        for (int i = 0, l = nums.size(); i < l; i++) {
            int x = target - nums[i];
            if (m.find(x) != m.end()) {
                res.insert(res.end(), m[x]);
                res.insert(res.end(), i);
                break;
            }
            m[nums[i]] = i;
        }

        return res;
    }
};

int main() {
    Solution s;

    vector<int> t1{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> a1 = s.twoSum(t1, 6);
    cout << a1[0] << ", " << a1[1]  << '\n';
}
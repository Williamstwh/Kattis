#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, l1 = nums1.size(), l2 = nums2.size();
        int l = l1 + l2;
        vector<int> nums;

        while (i < l1 || j < l2) {
            if (i >= l1) {
                nums.insert(nums.end(), nums2[j]);
                j++;
            } else if (j >= l2) {
                nums.insert(nums.end(), nums1[i]);
                i++;
            } else {
                int x = nums1[i];
                int y = nums2[j];
                if (x < y) {
                    nums.insert(nums.end(), x);
                    i++;
                } else {
                    nums.insert(nums.end(), y);
                    j++;
                }
            }
        }

        if (l % 2 == 0) {
            return ((double) (nums[l/2 - 1] + nums[l/2])) / 2.0;
        } else {
            return nums[l / 2];
        }
    }
};

int main() {
    Solution s;
    vector<int> v1{ 1, 3 };
    vector<int> v2{ 2, 4 };
    cout << s.findMedianSortedArrays(v1, v2) << '\n';
}

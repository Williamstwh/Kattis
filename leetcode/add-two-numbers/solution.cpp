#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* x = l1;
        ListNode* y = l2;
        ListNode* current = new ListNode();
        ListNode* result = current;
        int c = 0;

        while (x != NULL || y != NULL || c != 0) {

            int v = 0;

            v += (x == NULL ? 0 : x->val);
            v += (y == NULL ? 0 : y->val);
            v += c;
            c = v / 10;
            v %= 10;

            current->next = new ListNode(v);

            current = current->next;
            x = x == NULL ? NULL : x->next;
            y = y == NULL ? NULL : y->next;
        }

        current->next = NULL;
        return result->next;
    }
};

int main() {
    Solution s;

    ListNode n1(3);
    ListNode n2(4, &n1);
    ListNode n3(2, &n2);

    ListNode m1(4);
    ListNode m2(6, &m1);
    ListNode m3(5, &m2);

    ListNode* res = s.addTwoNumbers(&n3, &m3);
}

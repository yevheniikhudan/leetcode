#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

ListNode* build_list(const vector<int>& arr) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    for (int x : arr) {
        curr->next = new ListNode(x);
        curr = curr->next;
    }
    return dummy.next;
}

vector<int> list_to_array(ListNode* head) {
    vector<int> res;
    while (head) {
        res.push_back(head->val);
        head = head->next;
    }
    return res;
}

int main() {
    vector<pair<vector<int>, vector<int>>> tests = {{{1, 2, 3, 4, 5}, {3, 4, 5}},
                                                    {{1, 2, 3, 4, 5, 6}, {4, 5, 6}},
                                                    {{1}, {1}},
                                                    {{1, 2}, {2}},
                                                    {{1, 2, 3}, {2, 3}}};
    Solution sol;
    for (auto& [arr, expected] : tests) {
        ListNode* head = build_list(arr);
        vector<int> actual = list_to_array(sol.middleNode(head));
        cout << "[";
        for (size_t i = 0; i < actual.size(); ++i) {
            cout << actual[i];
            if (i + 1 < actual.size()) cout << ",";
        }
        cout << "] | [";
        for (size_t i = 0; i < expected.size(); ++i) {
            cout << expected[i];
            if (i + 1 < expected.size()) cout << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}

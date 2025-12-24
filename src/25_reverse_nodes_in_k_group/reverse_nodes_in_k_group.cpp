/**
 * 25. Reverse Nodes in k-Group
 *
 * Given the head of a linked list, reverse the nodes of the list k at a time,
 * and return the modified list.
 *
 * k is a positive integer and is less than or equal to the length of the linked list.
 * If the number of nodes is not a multiple of k then left-out nodes, in the end,
 * should remain as it is.
 *
 * You may not alter the values in the list's nodes, only nodes themselves may be changed.
 *
 * Difficulty: Hard
 */

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    /**
     * Reverse the nodes of the list k at a time.
     *
     * @param head Head of the linked list
     * @param k Number of nodes to reverse in each group
     * @return Head of the modified list
     *
     * Time Complexity: O(n) where n is number of nodes
     * Space Complexity: O(1) for iterative, O(n/k) for recursive
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prevGroup = dummy;

        while (true) {
            ListNode* kth = findKth(prevGroup, k);

            if (!kth) {
                ListNode* newHead = dummy->next;
                delete dummy;
                return newHead;
            }
            ListNode* nextGroup = kth->next;
            ListNode* startGroup = prevGroup->next;

            reverseGroup(startGroup, nextGroup);

            prevGroup->next = kth;
            startGroup->next = nextGroup;
            prevGroup = startGroup;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }

   private:
    ListNode* findKth(ListNode* curr, int k) {
        while (curr != nullptr && k > 0) {
            curr = curr->next;
            k -= 1;
        }

        return curr;
    }

    void reverseGroup(ListNode* curr, ListNode* end) {
        ListNode* prev = nullptr;

        while (curr != end) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }
};

// Helper functions for testing
vector<int> listToArray(ListNode* head) {
    vector<int> result;
    ListNode* curr = head;
    while (curr != nullptr) {
        result.push_back(curr->val);
        curr = curr->next;
    }
    return result;
}

ListNode* arrayToList(vector<int> arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

void printArray(vector<int> arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]";
}

void test_reverse_k_group() {
    Solution solution;

    // Test case 1: Example 1 - k=2
    ListNode* head1 = arrayToList({1, 2, 3, 4, 5});
    ListNode* result1 = solution.reverseKGroup(head1, 2);
    cout << "Test 1: ";
    printArray(listToArray(result1));
    cout << " (expected: [2, 1, 4, 3, 5])" << endl;

    // Test case 2: Example 2 - k=3
    ListNode* head2 = arrayToList({1, 2, 3, 4, 5});
    ListNode* result2 = solution.reverseKGroup(head2, 3);
    cout << "Test 2: ";
    printArray(listToArray(result2));
    cout << " (expected: [3, 2, 1, 4, 5])" << endl;

    // Test case 3: k=1 (no change)
    ListNode* head3 = arrayToList({1, 2, 3});
    ListNode* result3 = solution.reverseKGroup(head3, 1);
    cout << "Test 3: ";
    printArray(listToArray(result3));
    cout << " (expected: [1, 2, 3])" << endl;

    // Test case 4: k equals list length
    ListNode* head4 = arrayToList({1, 2, 3});
    ListNode* result4 = solution.reverseKGroup(head4, 3);
    cout << "Test 4: ";
    printArray(listToArray(result4));
    cout << " (expected: [3, 2, 1])" << endl;

    // Test case 5: Single node
    ListNode* head5 = arrayToList({1});
    ListNode* result5 = solution.reverseKGroup(head5, 1);
    cout << "Test 5: ";
    printArray(listToArray(result5));
    cout << " (expected: [1])" << endl;

    // Test case 6: Two nodes, k=2
    ListNode* head6 = arrayToList({1, 2});
    ListNode* result6 = solution.reverseKGroup(head6, 2);
    cout << "Test 6: ";
    printArray(listToArray(result6));
    cout << " (expected: [2, 1])" << endl;

    // Test case 7: Exact multiple of k
    ListNode* head7 = arrayToList({1, 2, 3, 4, 5, 6});
    ListNode* result7 = solution.reverseKGroup(head7, 3);
    cout << "Test 7: ";
    printArray(listToArray(result7));
    cout << " (expected: [3, 2, 1, 6, 5, 4])" << endl;

    // Test case 8: Large k
    ListNode* head8 = arrayToList({1, 2, 3});
    ListNode* result8 = solution.reverseKGroup(head8, 10);
    cout << "Test 8: ";
    printArray(listToArray(result8));
    cout << " (expected: [1, 2, 3])" << endl;
}

int main() {
    test_reverse_k_group();
    return 0;
}

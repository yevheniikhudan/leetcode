/*
143. Reorder List

You are given the head of a singly linked-list. Reorder the list to be in the form:
L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Difficulty: Medium
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
     * Reorder list in-place using three-step approach:
     * 1. Find middle
     * 2. Reverse second half
     * 3. Merge two halves
     *
     * @param head Head of the linked list
     *
     * Time Complexity: O(n) - three passes through the list
     * Space Complexity: O(1) - only using pointers
     */
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) { 
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr and fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* left = head;
        ListNode* right = prev;

        while (right != nullptr) {
            ListNode* next1 = left->next;
            ListNode* next2 = right->next;

            left->next = right;
            right->next = next1;
            left = next1;
            right = next2;
        }
    }
};

// Helper functions for testing
vector<int> listToArray(ListNode* head) {
    vector<int> result;
    ListNode* curr = head;
    while (curr) {
        result.push_back(curr->val);
        curr = curr->next;
    }
    return result;
}

ListNode* arrayToList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

void printArray(const vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]";
}

void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void runTests() {
    Solution solution;

    // Test case 1: Example 1 - even length
    ListNode* head1 = arrayToList({1, 2, 3, 4});
    solution.reorderList(head1);
    cout << "Test 1: ";
    printArray(listToArray(head1));
    cout << " (expected: [1, 4, 2, 3])\n";
    deleteList(head1);

    // Test case 2: Example 2 - odd length
    ListNode* head2 = arrayToList({1, 2, 3, 4, 5});
    solution.reorderList(head2);
    cout << "Test 2: ";
    printArray(listToArray(head2));
    cout << " (expected: [1, 5, 2, 4, 3])\n";
    deleteList(head2);

    // Test case 3: Single node
    ListNode* head3 = arrayToList({1});
    solution.reorderList(head3);
    cout << "Test 3: ";
    printArray(listToArray(head3));
    cout << " (expected: [1])\n";
    deleteList(head3);

    // Test case 4: Two nodes
    ListNode* head4 = arrayToList({1, 2});
    solution.reorderList(head4);
    cout << "Test 4: ";
    printArray(listToArray(head4));
    cout << " (expected: [1, 2])\n";
    deleteList(head4);

    // Test case 5: Three nodes
    ListNode* head5 = arrayToList({1, 2, 3});
    solution.reorderList(head5);
    cout << "Test 5: ";
    printArray(listToArray(head5));
    cout << " (expected: [1, 3, 2])\n";
    deleteList(head5);

    // Test case 6: Six nodes
    ListNode* head6 = arrayToList({1, 2, 3, 4, 5, 6});
    solution.reorderList(head6);
    cout << "Test 6: ";
    printArray(listToArray(head6));
    cout << " (expected: [1, 6, 2, 5, 3, 4])\n";
    deleteList(head6);

    // Test case 7: Seven nodes
    ListNode* head7 = arrayToList({1, 2, 3, 4, 5, 6, 7});
    solution.reorderList(head7);
    cout << "Test 7: ";
    printArray(listToArray(head7));
    cout << " (expected: [1, 7, 2, 6, 3, 5, 4])\n";
    deleteList(head7);

    // Test case 8: Large even list
    ListNode* head8 = arrayToList({1, 2, 3, 4, 5, 6, 7, 8});
    solution.reorderList(head8);
    cout << "Test 8: ";
    printArray(listToArray(head8));
    cout << " (expected: [1, 8, 2, 7, 3, 6, 4, 5])\n";
    deleteList(head8);
}

int main() {
    runTests();
    return 0;
}

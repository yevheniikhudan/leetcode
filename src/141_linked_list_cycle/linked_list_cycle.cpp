/*
141. Linked List Cycle

Given head, the head of a linked list, determine if the linked list has a cycle in it.

Return true if there is a cycle in the linked list. Otherwise, return false.

Difficulty: Easy
*/

#include <iostream>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    /**
     * Detect cycle in linked list using Floyd's Cycle Detection (Two Pointers).
     *
     * @param head Head of the linked list
     * @return true if cycle exists, false otherwise
     *
     * Time Complexity: O(n) - visit each node at most once
     * Space Complexity: O(1) - only two pointers
     */
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

    /**
     * Detect cycle in linked list using hash set.
     *
     * @param head Head of the linked list
     * @return true if cycle exists, false otherwise
     *
     * Time Complexity: O(n) - visit each node once
     * Space Complexity: O(n) - store all visited nodes
     */
    bool hasCycleHashSet(ListNode* head) {
        unordered_set<ListNode*> seen;

        while (head != nullptr) {
            if (seen.count(head)) {
                return true;
            }
            seen.insert(head);
            head = head->next;
        }

        return false;
    }
};

// Helper function for testing
ListNode* createCycleList(int values[], int size, int pos) {
    if (size == 0) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;
    ListNode* cycleNode = (pos == 0) ? head : nullptr;

    for (int i = 1; i < size; i++) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
        if (i == pos) {
            cycleNode = curr;
        }
    }

    // Create cycle if pos is valid
    if (pos >= 0 && cycleNode) {
        curr->next = cycleNode;
    }

    return head;
}

void runTests() {
    Solution solution;

    // Test case 1: Example 1 - cycle at position 1
    int arr1[] = {3, 2, 0, -4};
    ListNode* head1 = createCycleList(arr1, 4, 1);
    bool result1 = solution.hasCycle(head1);
    cout << "Test 1 (Two Pointers): " << (result1 ? "true" : "false") << " (expected: true)\n";

    // Test case 2: Example 2 - cycle at position 0
    int arr2[] = {1, 2};
    ListNode* head2 = createCycleList(arr2, 2, 0);
    bool result2 = solution.hasCycle(head2);
    cout << "Test 2 (Two Pointers): " << (result2 ? "true" : "false") << " (expected: true)\n";

    // Test case 3: Example 3 - no cycle
    int arr3[] = {1};
    ListNode* head3 = createCycleList(arr3, 1, -1);
    bool result3 = solution.hasCycle(head3);
    cout << "Test 3 (Two Pointers): " << (result3 ? "true" : "false") << " (expected: false)\n";

    // Test case 4: Empty list
    ListNode* head4 = createCycleList(nullptr, 0, -1);
    bool result4 = solution.hasCycle(head4);
    cout << "Test 4 (Two Pointers): " << (result4 ? "true" : "false") << " (expected: false)\n";

    // Test case 5: Two nodes, no cycle
    int arr5[] = {1, 2};
    ListNode* head5 = createCycleList(arr5, 2, -1);
    bool result5 = solution.hasCycle(head5);
    cout << "Test 5 (Two Pointers): " << (result5 ? "true" : "false") << " (expected: false)\n";

    // Test case 6: Single node with self-loop
    int arr6[] = {1};
    ListNode* head6 = createCycleList(arr6, 1, 0);
    bool result6 = solution.hasCycle(head6);
    cout << "Test 6 (Two Pointers): " << (result6 ? "true" : "false") << " (expected: true)\n";

    // Test case 7: Large cycle
    int arr7[] = {1, 2, 3, 4, 5, 6};
    ListNode* head7 = createCycleList(arr7, 6, 2);
    bool result7 = solution.hasCycle(head7);
    cout << "Test 7 (Two Pointers): " << (result7 ? "true" : "false") << " (expected: true)\n";

    // Test case 8: Cycle at end
    int arr8[] = {1, 2, 3, 4};
    ListNode* head8 = createCycleList(arr8, 4, 3);
    bool result8 = solution.hasCycle(head8);
    cout << "Test 8 (Two Pointers): " << (result8 ? "true" : "false") << " (expected: true)\n";

    cout << "\n--- Hash Set Tests ---\n";

    // Test case 9: Hash set - cycle exists
    int arr9[] = {3, 2, 0, -4};
    ListNode* head9 = createCycleList(arr9, 4, 1);
    bool result9 = solution.hasCycleHashSet(head9);
    cout << "Test 9 (Hash Set): " << (result9 ? "true" : "false") << " (expected: true)\n";

    // Test case 10: Hash set - no cycle
    int arr10[] = {1, 2, 3};
    ListNode* head10 = createCycleList(arr10, 3, -1);
    bool result10 = solution.hasCycleHashSet(head10);
    cout << "Test 10 (Hash Set): " << (result10 ? "true" : "false") << " (expected: false)\n";

    // Test case 11: Hash set - empty list
    ListNode* head11 = createCycleList(nullptr, 0, -1);
    bool result11 = solution.hasCycleHashSet(head11);
    cout << "Test 11 (Hash Set): " << (result11 ? "true" : "false") << " (expected: false)\n";

    // Test case 12: Hash set - single node with cycle
    int arr12[] = {1};
    ListNode* head12 = createCycleList(arr12, 1, 0);
    bool result12 = solution.hasCycleHashSet(head12);
    cout << "Test 12 (Hash Set): " << (result12 ? "true" : "false") << " (expected: true)\n";

    // Note: Not deleting nodes because some have cycles (would cause infinite loops)
}

int main() {
    runTests();
    return 0;
}

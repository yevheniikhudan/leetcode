/*
206. Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.

Difficulty: Easy
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
     * Reverse a singly linked list iteratively.
     *
     * @param head Head of the linked list
     * @return Head of the reversed linked list
     *
     * Time Complexity: O(n) - visit each node once
     * Space Complexity: O(1) - only use three pointers
     */
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    /**
     * Reverse a singly linked list recursively.
     *
     * @param head Head of the linked list
     * @return Head of the reversed linked list
     *
     * Time Complexity: O(n) - visit each node once
     * Space Complexity: O(n) - recursive call stack
     */
    ListNode* reverseListRecursive(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newHead = reverseListRecursive(head->next);

        head->next->next = head;
        head->next = nullptr;

        return newHead;
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

    // Test case 1: Example 1 - regular list
    ListNode* head1 = arrayToList({1, 2, 3, 4, 5});
    ListNode* result1 = solution.reverseList(head1);
    cout << "Test 1 (Iterative): ";
    printArray(listToArray(result1));
    cout << " (expected: [5, 4, 3, 2, 1])\n";
    deleteList(result1);

    // Test case 2: Example 2 - two nodes
    ListNode* head2 = arrayToList({1, 2});
    ListNode* result2 = solution.reverseList(head2);
    cout << "Test 2 (Iterative): ";
    printArray(listToArray(result2));
    cout << " (expected: [2, 1])\n";
    deleteList(result2);

    // Test case 3: Example 3 - empty list
    ListNode* head3 = arrayToList({});
    ListNode* result3 = solution.reverseList(head3);
    cout << "Test 3 (Iterative): ";
    printArray(listToArray(result3));
    cout << " (expected: [])\n";
    deleteList(result3);

    // Test case 4: Single node
    ListNode* head4 = arrayToList({1});
    ListNode* result4 = solution.reverseList(head4);
    cout << "Test 4 (Iterative): ";
    printArray(listToArray(result4));
    cout << " (expected: [1])\n";
    deleteList(result4);

    // Test case 5: Three nodes
    ListNode* head5 = arrayToList({1, 2, 3});
    ListNode* result5 = solution.reverseList(head5);
    cout << "Test 5 (Iterative): ";
    printArray(listToArray(result5));
    cout << " (expected: [3, 2, 1])\n";
    deleteList(result5);

    cout << "\n--- Recursive Tests ---\n";

    // Test case 6: Recursive - regular list
    ListNode* head6 = arrayToList({1, 2, 3, 4, 5});
    ListNode* result6 = solution.reverseListRecursive(head6);
    cout << "Test 6 (Recursive): ";
    printArray(listToArray(result6));
    cout << " (expected: [5, 4, 3, 2, 1])\n";
    deleteList(result6);

    // Test case 7: Recursive - two nodes
    ListNode* head7 = arrayToList({1, 2});
    ListNode* result7 = solution.reverseListRecursive(head7);
    cout << "Test 7 (Recursive): ";
    printArray(listToArray(result7));
    cout << " (expected: [2, 1])\n";
    deleteList(result7);

    // Test case 8: Recursive - empty list
    ListNode* head8 = arrayToList({});
    ListNode* result8 = solution.reverseListRecursive(head8);
    cout << "Test 8 (Recursive): ";
    printArray(listToArray(result8));
    cout << " (expected: [])\n";
    deleteList(result8);

    // Test case 9: Recursive - single node
    ListNode* head9 = arrayToList({1});
    ListNode* result9 = solution.reverseListRecursive(head9);
    cout << "Test 9 (Recursive): ";
    printArray(listToArray(result9));
    cout << " (expected: [1])\n";
    deleteList(result9);

    // Test case 10: Recursive - three nodes
    ListNode* head10 = arrayToList({1, 2, 3});
    ListNode* result10 = solution.reverseListRecursive(head10);
    cout << "Test 10 (Recursive): ";
    printArray(listToArray(result10));
    cout << " (expected: [3, 2, 1])\n";
    deleteList(result10);
}

int main() {
    runTests();
    return 0;
}

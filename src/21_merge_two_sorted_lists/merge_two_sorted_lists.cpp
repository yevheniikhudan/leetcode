/*
21. Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing
together the nodes of the first two lists.

Return the head of the merged linked list.

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
     * Merge two sorted linked lists iteratively using dummy node.
     *
     * @param list1 Head of first sorted linked list
     * @param list2 Head of second sorted linked list
     * @return Head of merged sorted linked list
     *
     * Time Complexity: O(n + m) - visit each node once
     * Space Complexity: O(1) - only use a few pointers
     */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        curr->next = list1 != nullptr ? list1 : list2;

        return dummy->next;
    }

    /**
     * Merge two sorted linked lists recursively.
     *
     * @param list1 Head of first sorted linked list
     * @param list2 Head of second sorted linked list
     * @return Head of merged sorted linked list
     *
     * Time Complexity: O(n + m) - visit each node once
     * Space Complexity: O(n + m) - recursive call stack
     */
    ListNode* mergeTwoListsRecursive(ListNode* list1, ListNode* list2) {
        if (list2 == nullptr) {
            return list1;
        }
        if (list1 == nullptr) {
            return list2;
        }

        if (list1->val < list2->val) {
            list1->next = mergeTwoListsRecursive(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoListsRecursive(list1, list2->next);
            return list2;
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

    // Test case 1: Example 1 - regular merge
    ListNode* list1_1 = arrayToList({1, 2, 4});
    ListNode* list2_1 = arrayToList({1, 3, 4});
    ListNode* result1 = solution.mergeTwoLists(list1_1, list2_1);
    cout << "Test 1 (Iterative): ";
    printArray(listToArray(result1));
    cout << " (expected: [1, 1, 2, 3, 4, 4])\n";
    deleteList(result1);

    // Test case 2: Example 2 - both empty
    ListNode* list1_2 = arrayToList({});
    ListNode* list2_2 = arrayToList({});
    ListNode* result2 = solution.mergeTwoLists(list1_2, list2_2);
    cout << "Test 2 (Iterative): ";
    printArray(listToArray(result2));
    cout << " (expected: [])\n";
    deleteList(result2);

    // Test case 3: Example 3 - one empty
    ListNode* list1_3 = arrayToList({});
    ListNode* list2_3 = arrayToList({0});
    ListNode* result3 = solution.mergeTwoLists(list1_3, list2_3);
    cout << "Test 3 (Iterative): ";
    printArray(listToArray(result3));
    cout << " (expected: [0])\n";
    deleteList(result3);

    // Test case 4: First list empty
    ListNode* list1_4 = arrayToList({});
    ListNode* list2_4 = arrayToList({1, 2, 3});
    ListNode* result4 = solution.mergeTwoLists(list1_4, list2_4);
    cout << "Test 4 (Iterative): ";
    printArray(listToArray(result4));
    cout << " (expected: [1, 2, 3])\n";
    deleteList(result4);

    // Test case 5: Second list empty
    ListNode* list1_5 = arrayToList({1, 2, 3});
    ListNode* list2_5 = arrayToList({});
    ListNode* result5 = solution.mergeTwoLists(list1_5, list2_5);
    cout << "Test 5 (Iterative): ";
    printArray(listToArray(result5));
    cout << " (expected: [1, 2, 3])\n";
    deleteList(result5);

    // Test case 6: No overlap
    ListNode* list1_6 = arrayToList({1, 2, 3});
    ListNode* list2_6 = arrayToList({4, 5, 6});
    ListNode* result6 = solution.mergeTwoLists(list1_6, list2_6);
    cout << "Test 6 (Iterative): ";
    printArray(listToArray(result6));
    cout << " (expected: [1, 2, 3, 4, 5, 6])\n";
    deleteList(result6);

    // Test case 7: Different lengths
    ListNode* list1_7 = arrayToList({1, 3, 5, 7, 9});
    ListNode* list2_7 = arrayToList({2, 4});
    ListNode* result7 = solution.mergeTwoLists(list1_7, list2_7);
    cout << "Test 7 (Iterative): ";
    printArray(listToArray(result7));
    cout << " (expected: [1, 2, 3, 4, 5, 7, 9])\n";
    deleteList(result7);

    // Test case 8: All duplicates
    ListNode* list1_8 = arrayToList({1, 1, 1});
    ListNode* list2_8 = arrayToList({1, 1});
    ListNode* result8 = solution.mergeTwoLists(list1_8, list2_8);
    cout << "Test 8 (Iterative): ";
    printArray(listToArray(result8));
    cout << " (expected: [1, 1, 1, 1, 1])\n";
    deleteList(result8);

    cout << "\n--- Recursive Tests ---\n";

    // Test case 9: Recursive - regular merge
    ListNode* list1_9 = arrayToList({1, 2, 4});
    ListNode* list2_9 = arrayToList({1, 3, 4});
    ListNode* result9 = solution.mergeTwoListsRecursive(list1_9, list2_9);
    cout << "Test 9 (Recursive): ";
    printArray(listToArray(result9));
    cout << " (expected: [1, 1, 2, 3, 4, 4])\n";
    deleteList(result9);

    // Test case 10: Recursive - both empty
    ListNode* list1_10 = arrayToList({});
    ListNode* list2_10 = arrayToList({});
    ListNode* result10 = solution.mergeTwoListsRecursive(list1_10, list2_10);
    cout << "Test 10 (Recursive): ";
    printArray(listToArray(result10));
    cout << " (expected: [])\n";
    deleteList(result10);

    // Test case 11: Recursive - one empty
    ListNode* list1_11 = arrayToList({});
    ListNode* list2_11 = arrayToList({0});
    ListNode* result11 = solution.mergeTwoListsRecursive(list1_11, list2_11);
    cout << "Test 11 (Recursive): ";
    printArray(listToArray(result11));
    cout << " (expected: [0])\n";
    deleteList(result11);

    // Test case 12: Recursive - different lengths
    ListNode* list1_12 = arrayToList({1, 3, 5});
    ListNode* list2_12 = arrayToList({2, 4, 6, 8, 10});
    ListNode* result12 = solution.mergeTwoListsRecursive(list1_12, list2_12);
    cout << "Test 12 (Recursive): ";
    printArray(listToArray(result12));
    cout << " (expected: [1, 2, 3, 4, 5, 6, 8, 10])\n";
    deleteList(result12);
}

int main() {
    runTests();
    return 0;
}

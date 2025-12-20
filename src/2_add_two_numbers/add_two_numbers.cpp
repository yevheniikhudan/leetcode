/**
 * 2. Add Two Numbers
 *
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.
 *
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>

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
     * Add two numbers represented as linked lists in reverse order.
     *
     * Approach:
     * 1. Traverse both lists simultaneously
     * 2. Add corresponding digits plus carry
     * 3. Create new node with sum % 10
     * 4. Update carry as sum / 10
     * 5. Handle remaining carry at the end
     *
     * Time Complexity: O(max(m, n)) where m, n are lengths of lists
     * Space Complexity: O(max(m, n)) for the result list
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get values from current nodes (0 if nullptr)
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Calculate sum and carry
            int total = val1 + val2 + carry;
            carry = total / 10;
            int digit = total % 10;

            // Create new node with the digit
            current->next = new ListNode(digit);
            current = current->next;

            // Move to next nodes
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

// Helper functions for testing
std::vector<int> listToArray(ListNode* head) {
    std::vector<int> result;
    ListNode* curr = head;
    while (curr != nullptr) {
        result.push_back(curr->val);
        curr = curr->next;
    }
    return result;
}

ListNode* arrayToList(const std::vector<int>& arr) {
    if (arr.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void printArray(const std::vector<int>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < arr.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

int main() {
    Solution solution;

    // Test case 1: Example 1 - basic addition
    ListNode* l1 = arrayToList({2, 4, 3});
    ListNode* l2 = arrayToList({5, 6, 4});
    ListNode* result1 = solution.addTwoNumbers(l1, l2);
    std::cout << "Test 1: ";
    printArray(listToArray(result1));
    std::cout << " (expected: [7, 0, 8])" << std::endl;
    deleteList(l1);
    deleteList(l2);
    deleteList(result1);

    // Test case 2: Example 2 - both zero
    l1 = arrayToList({0});
    l2 = arrayToList({0});
    ListNode* result2 = solution.addTwoNumbers(l1, l2);
    std::cout << "Test 2: ";
    printArray(listToArray(result2));
    std::cout << " (expected: [0])" << std::endl;
    deleteList(l1);
    deleteList(l2);
    deleteList(result2);

    // Test case 3: Example 3 - different lengths with carry
    l1 = arrayToList({9, 9, 9, 9, 9, 9, 9});
    l2 = arrayToList({9, 9, 9, 9});
    ListNode* result3 = solution.addTwoNumbers(l1, l2);
    std::cout << "Test 3: ";
    printArray(listToArray(result3));
    std::cout << " (expected: [8, 9, 9, 9, 0, 0, 0, 1])" << std::endl;
    deleteList(l1);
    deleteList(l2);
    deleteList(result3);

    // Test case 4: Single digit with carry
    l1 = arrayToList({5});
    l2 = arrayToList({5});
    ListNode* result4 = solution.addTwoNumbers(l1, l2);
    std::cout << "Test 4: ";
    printArray(listToArray(result4));
    std::cout << " (expected: [0, 1])" << std::endl;
    deleteList(l1);
    deleteList(l2);
    deleteList(result4);

    // Test case 5: Different lengths
    l1 = arrayToList({9, 9});
    l2 = arrayToList({1});
    ListNode* result5 = solution.addTwoNumbers(l1, l2);
    std::cout << "Test 5: ";
    printArray(listToArray(result5));
    std::cout << " (expected: [0, 0, 1])" << std::endl;
    deleteList(l1);
    deleteList(l2);
    deleteList(result5);

    // Test case 6: No carry
    l1 = arrayToList({1, 2, 3});
    l2 = arrayToList({4, 5, 6});
    ListNode* result6 = solution.addTwoNumbers(l1, l2);
    std::cout << "Test 6: ";
    printArray(listToArray(result6));
    std::cout << " (expected: [5, 7, 9])" << std::endl;
    deleteList(l1);
    deleteList(l2);
    deleteList(result6);

    return 0;
}

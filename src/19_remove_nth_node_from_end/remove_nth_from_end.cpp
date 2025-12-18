/**
 * 19. Remove Nth Node From End of List
 *
 * Given the head of a linked list, remove the nth node from the end of the list and return its
 * head.
 *
 * Difficulty: Medium
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
     * Remove nth node from end using two-pointer technique with dummy node.
     *
     * Approach:
     * 1. Use dummy node to handle edge case of removing head
     * 2. Use two pointers with n gap between them
     * 3. Move both until fast reaches end
     * 4. Remove the node after slow pointer
     *
     * Time Complexity: O(L) where L is the length of the list
     * Space Complexity: O(1) - only using pointers
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        while (n > 0) {
            fast = fast->next;
            n--;
        }

        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return dummy->next;
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

ListNode* arrayToList(const vector<int>& arr) {
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

void printArray(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution solution;

    // Test case 1: Remove 2nd from end
    ListNode* head1 = arrayToList({1, 2, 3, 4, 5});
    ListNode* result1 = solution.removeNthFromEnd(head1, 2);
    cout << "Test 1: ";
    printArray(listToArray(result1));
    cout << " (expected: [1, 2, 3, 5])" << endl;
    deleteList(result1);

    // Test case 2: Remove only node
    ListNode* head2 = arrayToList({1});
    ListNode* result2 = solution.removeNthFromEnd(head2, 1);
    cout << "Test 2: ";
    printArray(listToArray(result2));
    cout << " (expected: [])" << endl;
    deleteList(result2);

    // Test case 3: Remove first of two nodes
    ListNode* head3 = arrayToList({1, 2});
    ListNode* result3 = solution.removeNthFromEnd(head3, 1);
    cout << "Test 3: ";
    printArray(listToArray(result3));
    cout << " (expected: [1])" << endl;
    deleteList(result3);

    // Test case 4: Remove last node (head)
    ListNode* head4 = arrayToList({1, 2});
    ListNode* result4 = solution.removeNthFromEnd(head4, 2);
    cout << "Test 4: ";
    printArray(listToArray(result4));
    cout << " (expected: [2])" << endl;
    deleteList(result4);

    // Test case 5: Remove from middle
    ListNode* head5 = arrayToList({1, 2, 3, 4, 5});
    ListNode* result5 = solution.removeNthFromEnd(head5, 3);
    cout << "Test 5: ";
    printArray(listToArray(result5));
    cout << " (expected: [1, 2, 4, 5])" << endl;
    deleteList(result5);

    // Test case 6: Remove first node (last from end)
    ListNode* head6 = arrayToList({1, 2, 3, 4, 5});
    ListNode* result6 = solution.removeNthFromEnd(head6, 5);
    cout << "Test 6: ";
    printArray(listToArray(result6));
    cout << " (expected: [2, 3, 4, 5])" << endl;
    deleteList(result6);

    // Test case 7: Remove last node
    ListNode* head7 = arrayToList({1, 2, 3, 4, 5});
    ListNode* result7 = solution.removeNthFromEnd(head7, 1);
    cout << "Test 7: ";
    printArray(listToArray(result7));
    cout << " (expected: [1, 2, 3, 4])" << endl;
    deleteList(result7);

    return 0;
}

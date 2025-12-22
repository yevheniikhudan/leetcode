/**
 * 23. Merge k Sorted Lists
 *
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 *
 * Difficulty: Hard
 */

#include <iostream>
#include <queue>
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
     * Merge k sorted linked lists into one sorted linked list using Min-Heap.
     *
     * @param lists Vector of k linked-lists, each sorted in ascending order
     * @return Head of the merged sorted linked list
     *
     * Time Complexity: O(N log k) where N is total nodes, k is number of lists
     * Space Complexity: O(k) for the heap
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Custom comparator for min-heap (greater creates min-heap)
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;  // Min-heap: smaller values have higher priority
        };

        // Min-heap using priority_queue
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);

        // Add the first node from each list to the heap
        for (ListNode* node : lists) {
            if (node != nullptr) {
                minHeap.push(node);
            }
        }

        // Dummy node to build result list
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        // Process heap until empty
        while (!minHeap.empty()) {
            // Get the smallest node
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            // Add to result list
            curr->next = smallest;
            curr = curr->next;

            // If this node has a next node, add it to heap
            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }

        ListNode* result = dummy->next;
        delete dummy;  // Clean up dummy node
        return result;
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

void test_merge_k_lists() {
    Solution solution;

    // Test case 1: Example 1 - three lists
    vector<ListNode*> lists1 = {arrayToList({1, 4, 5}), arrayToList({1, 3, 4}),
                                arrayToList({2, 6})};
    ListNode* result1 = solution.mergeKLists(lists1);
    cout << "Test 1: ";
    printArray(listToArray(result1));
    cout << " (expected: [1, 1, 2, 3, 4, 4, 5, 6])" << endl;

    // Test case 2: Example 2 - empty list
    vector<ListNode*> lists2 = {};
    ListNode* result2 = solution.mergeKLists(lists2);
    cout << "Test 2: ";
    printArray(listToArray(result2));
    cout << " (expected: [])" << endl;

    // Test case 3: Example 3 - list with empty list
    vector<ListNode*> lists3 = {arrayToList({})};
    ListNode* result3 = solution.mergeKLists(lists3);
    cout << "Test 3: ";
    printArray(listToArray(result3));
    cout << " (expected: [])" << endl;

    // Test case 4: Single list
    vector<ListNode*> lists4 = {arrayToList({1, 2, 3})};
    ListNode* result4 = solution.mergeKLists(lists4);
    cout << "Test 4: ";
    printArray(listToArray(result4));
    cout << " (expected: [1, 2, 3])" << endl;

    // Test case 5: Two lists
    vector<ListNode*> lists5 = {arrayToList({1, 3, 5}), arrayToList({2, 4, 6})};
    ListNode* result5 = solution.mergeKLists(lists5);
    cout << "Test 5: ";
    printArray(listToArray(result5));
    cout << " (expected: [1, 2, 3, 4, 5, 6])" << endl;

    // Test case 6: Lists with different lengths
    vector<ListNode*> lists6 = {arrayToList({1}), arrayToList({1, 3, 4}), arrayToList({2, 6})};
    ListNode* result6 = solution.mergeKLists(lists6);
    cout << "Test 6: ";
    printArray(listToArray(result6));
    cout << " (expected: [1, 1, 2, 3, 4, 6])" << endl;

    // Test case 7: Negative values
    vector<ListNode*> lists7 = {arrayToList({-2, -1, 0}), arrayToList({-3, 1, 2})};
    ListNode* result7 = solution.mergeKLists(lists7);
    cout << "Test 7: ";
    printArray(listToArray(result7));
    cout << " (expected: [-3, -2, -1, 0, 1, 2])" << endl;
}

int main() {
    test_merge_k_lists();
    return 0;
}

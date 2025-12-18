/**
 * 138. Copy List with Random Pointer
 *
 * A linked list of length n is given such that each node contains an additional random pointer,
 * which could point to any node in the list, or null.
 *
 * Construct a deep copy of the list.
 *
 * Difficulty: Medium
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
   public:
    /**
     * Create a deep copy of a linked list with random pointers.
     *
     * Approach: Use a hash map to track old -> new node mappings
     * Recursive implementation with memoization
     *
     * Time Complexity: O(n) - each node visited once
     * Space Complexity: O(n) - hash map to store node mappings + recursion stack
     */
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> cache;
        return copyRandomList(head, cache);
    }

   private:
    Node* copyRandomList(Node* head, unordered_map<Node*, Node*>& cache) {
        if (head == nullptr) {
            return nullptr;
        }

        if (cache.find(head) != cache.end()) {
            return cache[head];
        }

        Node* copy = new Node(head->val);
        cache[head] = copy;
        copy->next = copyRandomList(head->next, cache);
        copy->random = (cache.find(head->random) != cache.end()) ? cache[head->random] : nullptr;

        return copy;
    }
};

// Helper functions for testing
Node* createListWithRandom(const vector<pair<int, int>>& values) {
    if (values.empty()) {
        return nullptr;
    }

    // Create all nodes first
    vector<Node*> nodes;
    for (const auto& [val, _] : values) {
        nodes.push_back(new Node(val));
    }

    // Set next pointers
    for (size_t i = 0; i < nodes.size() - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }

    // Set random pointers (-1 means null)
    for (size_t i = 0; i < values.size(); i++) {
        if (values[i].second != -1) {
            nodes[i]->random = nodes[values[i].second];
        }
    }

    return nodes[0];
}

string listToString(Node* head) {
    if (head == nullptr) {
        return "[]";
    }

    // Map nodes to indices
    unordered_map<Node*, int> nodeToIndex;
    Node* curr = head;
    int index = 0;
    while (curr != nullptr) {
        nodeToIndex[curr] = index;
        curr = curr->next;
        index++;
    }

    // Build result string
    string result = "[";
    curr = head;
    while (curr != nullptr) {
        result += "[" + to_string(curr->val) + ",";
        if (curr->random != nullptr) {
            result += to_string(nodeToIndex[curr->random]);
        } else {
            result += "null";
        }
        result += "]";
        if (curr->next != nullptr) {
            result += ",";
        }
        curr = curr->next;
    }
    result += "]";
    return result;
}

bool verifyDeepCopy(Node* original, Node* copied) {
    if (original == nullptr && copied == nullptr) {
        return true;
    }
    if (original == nullptr || copied == nullptr) {
        return false;
    }

    // Check that no nodes are shared
    unordered_map<Node*, bool> originalNodes;
    Node* curr = original;
    while (curr != nullptr) {
        originalNodes[curr] = true;
        curr = curr->next;
    }

    curr = copied;
    while (curr != nullptr) {
        if (originalNodes.find(curr) != originalNodes.end()) {
            return false;
        }
        curr = curr->next;
    }

    return true;
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution solution;

    // Test case 1: Example 1 - complex random pointers
    // [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Node* head1 = createListWithRandom({{7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}});
    Node* result1 = solution.copyRandomList(head1);
    cout << "Test 1: " << listToString(result1) << endl;
    cout << "  Expected: [[7,null],[13,0],[11,4],[10,2],[1,0]]" << endl;
    cout << "  Deep copy: " << (verifyDeepCopy(head1, result1) ? "true" : "false") << endl;
    deleteList(result1);
    deleteList(head1);

    // Test case 2: Example 2 - simple case
    Node* head2 = createListWithRandom({{1, 1}, {2, 1}});
    Node* result2 = solution.copyRandomList(head2);
    cout << "\nTest 2: " << listToString(result2) << endl;
    cout << "  Expected: [[1,1],[2,1]]" << endl;
    cout << "  Deep copy: " << (verifyDeepCopy(head2, result2) ? "true" : "false") << endl;
    deleteList(result2);
    deleteList(head2);

    // Test case 3: Example 3 - some null random pointers
    Node* head3 = createListWithRandom({{3, -1}, {3, 0}, {3, -1}});
    Node* result3 = solution.copyRandomList(head3);
    cout << "\nTest 3: " << listToString(result3) << endl;
    cout << "  Expected: [[3,null],[3,0],[3,null]]" << endl;
    cout << "  Deep copy: " << (verifyDeepCopy(head3, result3) ? "true" : "false") << endl;
    deleteList(result3);
    deleteList(head3);

    // Test case 4: Empty list
    Node* head4 = nullptr;
    Node* result4 = solution.copyRandomList(head4);
    cout << "\nTest 4: " << listToString(result4) << endl;
    cout << "  Expected: []" << endl;

    // Test case 5: Single node
    Node* head5 = createListWithRandom({{1, -1}});
    Node* result5 = solution.copyRandomList(head5);
    cout << "\nTest 5: " << listToString(result5) << endl;
    cout << "  Expected: [[1,null]]" << endl;
    cout << "  Deep copy: " << (verifyDeepCopy(head5, result5) ? "true" : "false") << endl;
    deleteList(result5);
    deleteList(head5);

    // Test case 6: Self-referencing random pointer
    Node* head6 = createListWithRandom({{1, 0}, {2, 1}});
    Node* result6 = solution.copyRandomList(head6);
    cout << "\nTest 6: " << listToString(result6) << endl;
    cout << "  Expected: [[1,0],[2,1]]" << endl;
    cout << "  Deep copy: " << (verifyDeepCopy(head6, result6) ? "true" : "false") << endl;
    deleteList(result6);
    deleteList(head6);

    return 0;
}

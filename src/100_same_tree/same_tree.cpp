/**
 * 100. Same Tree
 *
 * Given the roots of two binary trees p and q, write a function to check if they are the same or
 * not. Two binary trees are considered the same if they are structurally identical, and the nodes
 * have the same value.
 */

#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    /**
     * Check if two binary trees are the same.
     *
     * @param p Root of first binary tree
     * @param q Root of second binary tree
     * @return true if trees are identical in structure and values, false otherwise
     */
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            return p == q;
        }

        if (p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Helper function to build a binary tree from a vector (level-order)
TreeNode* buildTree(const vector<int*>& values) {
    if (values.empty() || values[0] == nullptr) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(*values[0]);
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;

    while (!q.empty() && i < values.size()) {
        TreeNode* node = q.front();
        q.pop();

        if (i < values.size() && values[i] != nullptr) {
            node->left = new TreeNode(*values[i]);
            q.push(node->left);
        }
        i++;

        if (i < values.size() && values[i] != nullptr) {
            node->right = new TreeNode(*values[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}

// Helper function to delete a tree and free memory
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution solution;

    // Test case 1: Both trees identical [1,2,3]
    cout << "Test 1: Both trees [1,2,3]" << endl;
    int v1 = 1, v2 = 2, v3 = 3;
    TreeNode* p1 = buildTree({&v1, &v2, &v3});
    TreeNode* q1 = buildTree({&v1, &v2, &v3});
    bool result1 = solution.isSameTree(p1, q1);
    cout << "Result: " << (result1 ? "true" : "false") << ", Expected: true" << endl;
    assert(result1 == true);
    deleteTree(p1);
    deleteTree(q1);

    // Test case 2: Different structure [1,2] vs [1,null,2]
    cout << "\nTest 2: Different structure [1,2] vs [1,null,2]" << endl;
    TreeNode* p2 = buildTree({&v1, &v2});
    TreeNode* q2 = buildTree({&v1, nullptr, &v2});
    bool result2 = solution.isSameTree(p2, q2);
    cout << "Result: " << (result2 ? "true" : "false") << ", Expected: false" << endl;
    assert(result2 == false);
    deleteTree(p2);
    deleteTree(q2);

    // Test case 3: Different values [1,2,1] vs [1,1,2]
    cout << "\nTest 3: Different values [1,2,1] vs [1,1,2]" << endl;
    TreeNode* p3 = buildTree({&v1, &v2, &v1});
    TreeNode* q3 = buildTree({&v1, &v1, &v2});
    bool result3 = solution.isSameTree(p3, q3);
    cout << "Result: " << (result3 ? "true" : "false") << ", Expected: false" << endl;
    assert(result3 == false);
    deleteTree(p3);
    deleteTree(q3);

    // Test case 4: Both empty trees
    cout << "\nTest 4: Both empty trees" << endl;
    TreeNode* p4 = nullptr;
    TreeNode* q4 = nullptr;
    bool result4 = solution.isSameTree(p4, q4);
    cout << "Result: " << (result4 ? "true" : "false") << ", Expected: true" << endl;
    assert(result4 == true);

    // Test case 5: One empty, one not
    cout << "\nTest 5: One empty [1] vs []" << endl;
    TreeNode* p5 = buildTree({&v1});
    TreeNode* q5 = nullptr;
    bool result5 = solution.isSameTree(p5, q5);
    cout << "Result: " << (result5 ? "true" : "false") << ", Expected: false" << endl;
    assert(result5 == false);
    deleteTree(p5);

    // Test case 6: Single nodes with same value
    cout << "\nTest 6: Single nodes both [1]" << endl;
    TreeNode* p6 = buildTree({&v1});
    TreeNode* q6 = buildTree({&v1});
    bool result6 = solution.isSameTree(p6, q6);
    cout << "Result: " << (result6 ? "true" : "false") << ", Expected: true" << endl;
    assert(result6 == true);
    deleteTree(p6);
    deleteTree(q6);

    // Test case 7: Single nodes with different values
    cout << "\nTest 7: Single nodes [1] vs [2]" << endl;
    TreeNode* p7 = buildTree({&v1});
    TreeNode* q7 = buildTree({&v2});
    bool result7 = solution.isSameTree(p7, q7);
    cout << "Result: " << (result7 ? "true" : "false") << ", Expected: false" << endl;
    assert(result7 == false);
    deleteTree(p7);
    deleteTree(q7);

    // Test case 8: Larger identical trees
    cout << "\nTest 8: Larger identical trees" << endl;
    int v4 = 4, v5 = 5, v6 = 6, v7 = 7;
    TreeNode* p8 = buildTree({&v1, &v2, &v3, &v4, &v5, &v6, &v7});
    TreeNode* q8 = buildTree({&v1, &v2, &v3, &v4, &v5, &v6, &v7});
    bool result8 = solution.isSameTree(p8, q8);
    cout << "Result: " << (result8 ? "true" : "false") << ", Expected: true" << endl;
    assert(result8 == true);
    deleteTree(p8);
    deleteTree(q8);

    // Test case 9: Different at leaf level
    cout << "\nTest 9: Different at leaf level" << endl;
    int v8 = 8;
    TreeNode* p9 = buildTree({&v1, &v2, &v3, &v4, &v5, &v6, &v7});
    TreeNode* q9 = buildTree({&v1, &v2, &v3, &v4, &v5, &v6, &v8});
    bool result9 = solution.isSameTree(p9, q9);
    cout << "Result: " << (result9 ? "true" : "false") << ", Expected: false" << endl;
    assert(result9 == false);
    deleteTree(p9);
    deleteTree(q9);

    // Test case 10: Different tree sizes
    cout << "\nTest 10: Different tree sizes" << endl;
    TreeNode* p10 = buildTree({&v1, &v2, &v3});
    TreeNode* q10 = buildTree({&v1, &v2, &v3, &v4});
    bool result10 = solution.isSameTree(p10, q10);
    cout << "Result: " << (result10 ? "true" : "false") << ", Expected: false" << endl;
    assert(result10 == false);
    deleteTree(p10);
    deleteTree(q10);

    cout << "\n✅ All tests passed!" << endl;

    return 0;
}

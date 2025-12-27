/**
 * 1448. Count Good Nodes in Binary Tree
 *
 * Given a binary tree root, a node X in the tree is named good if in the path
 * from root to X there are no nodes with a value greater than X.
 *
 * Return the number of good nodes in the binary tree.
 */

#include <algorithm>
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
     * Count the number of good nodes in the binary tree.
     *
     * A node is "good" if in the path from root to that node,
     * there are no nodes with a value greater than it.
     *
     * @param root Root of the binary tree
     * @return The number of good nodes in the tree
     */
    int goodNodes(TreeNode* root) { return countGoodNodes(root, root->val); }

   private:
    int countGoodNodes(TreeNode* root, int maxVal) {
        if (!root) {
            return 0;
        }

        int count = root->val >= maxVal ? 1 : 0;
        int newMax = max(maxVal, root->val);

        count += countGoodNodes(root->left, newMax);
        count += countGoodNodes(root->right, newMax);

        return count;
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

    // Test case 1: Standard example with mix of good and bad nodes
    cout << "Test 1: Tree [3,1,4,3,null,1,5]" << endl;
    int v1 = 3, v2 = 1, v3 = 4, v4 = 5;
    TreeNode* root1 = buildTree({&v1, &v2, &v3, &v1, nullptr, &v2, &v4});
    int result1 = solution.goodNodes(root1);
    int expected1 = 4;
    cout << "Result: " << result1 << endl;
    cout << "Expected: " << expected1 << endl;
    assert(result1 == expected1);
    deleteTree(root1);

    // Test case 2: Tree where not all nodes are good
    cout << "\nTest 2: Tree [3,3,null,4,2]" << endl;
    int v5 = 2;
    TreeNode* root2 = buildTree({&v1, &v1, nullptr, &v3, &v5});
    int result2 = solution.goodNodes(root2);
    int expected2 = 3;
    cout << "Result: " << result2 << endl;
    cout << "Expected: " << expected2 << endl;
    assert(result2 == expected2);
    deleteTree(root2);

    // Test case 3: Single node
    cout << "\nTest 3: Single node [1]" << endl;
    TreeNode* root3 = buildTree({&v2});
    int result3 = solution.goodNodes(root3);
    int expected3 = 1;
    cout << "Result: " << result3 << endl;
    cout << "Expected: " << expected3 << endl;
    assert(result3 == expected3);
    deleteTree(root3);

    // Test case 4: All nodes equal (all should be good)
    cout << "\nTest 4: All equal values [2,2,2,2,2]" << endl;
    TreeNode* root4 = buildTree({&v5, &v5, &v5, &v5, &v5});
    int result4 = solution.goodNodes(root4);
    int expected4 = 5;
    cout << "Result: " << result4 << endl;
    cout << "Expected: " << expected4 << endl;
    assert(result4 == expected4);
    deleteTree(root4);

    // Test case 5: Strictly increasing (all good)
    cout << "\nTest 5: Strictly increasing [1,2,3,4,5]" << endl;
    TreeNode* root5 = buildTree({&v2, &v5, &v1, &v3, &v4});
    int result5 = solution.goodNodes(root5);
    int expected5 = 5;
    cout << "Result: " << result5 << endl;
    cout << "Expected: " << expected5 << endl;
    assert(result5 == expected5);
    deleteTree(root5);

    // Test case 6: Strictly decreasing (only root good)
    cout << "\nTest 6: Strictly decreasing [5,4,3,2,1]" << endl;
    TreeNode* root6 = buildTree({&v4, &v3, &v1, &v5, &v2});
    int result6 = solution.goodNodes(root6);
    int expected6 = 1;
    cout << "Result: " << result6 << endl;
    cout << "Expected: " << expected6 << endl;
    assert(result6 == expected6);
    deleteTree(root6);

    // Test case 7: Negative values
    cout << "\nTest 7: With negative values [-1,5,-2,4,null,null,8]" << endl;
    int v6 = -1, v7 = -2, v8 = 8;
    TreeNode* root7 = buildTree({&v6, &v4, &v7, &v3, nullptr, nullptr, &v8});
    int result7 = solution.goodNodes(root7);
    int expected7 = 3;
    cout << "Result: " << result7 << endl;
    cout << "Expected: " << expected7 << endl;
    assert(result7 == expected7);
    deleteTree(root7);

    cout << "\n✅ All tests passed!" << endl;

    return 0;
}

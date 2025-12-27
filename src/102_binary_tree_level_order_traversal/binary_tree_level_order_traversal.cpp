/**
 * 102. Binary Tree Level Order Traversal
 *
 * Given the root of a binary tree, return the level order traversal of its nodes' values.
 * (i.e., from left to right, level by level).
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
     * Return level order traversal of binary tree.
     *
     * @param root Root of the binary tree
     * @return Vector of vectors, where each inner vector contains values at that level
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        int currentLevel = 0;

        if (root) {
            q.push(root);
        }

        while (q.size() > 0) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();

                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }

                if (result.size() == currentLevel) {
                    vector<int> level;
                    result.push_back(level);
                }
                result[currentLevel].push_back(current->val);
            }

            currentLevel++;
        }

        return result;
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

// Helper to print result
void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution solution;

    // Test case 1: Standard tree with 3 levels
    cout << "Test 1: Standard tree [3,9,20,null,null,15,7]" << endl;
    int v1 = 3, v2 = 9, v3 = 20, v4 = 15, v5 = 7;
    TreeNode* root1 = buildTree({&v1, &v2, &v3, nullptr, nullptr, &v4, &v5});
    vector<vector<int>> result1 = solution.levelOrder(root1);
    vector<vector<int>> expected1 = {{3}, {9, 20}, {15, 7}};
    cout << "Result: ";
    printResult(result1);
    cout << endl;
    cout << "Expected: ";
    printResult(expected1);
    cout << endl;
    assert(result1 == expected1);
    deleteTree(root1);

    // Test case 2: Single node
    cout << "\nTest 2: Single node [1]" << endl;
    int v6 = 1;
    TreeNode* root2 = buildTree({&v6});
    vector<vector<int>> result2 = solution.levelOrder(root2);
    vector<vector<int>> expected2 = {{1}};
    cout << "Result: ";
    printResult(result2);
    cout << endl;
    cout << "Expected: ";
    printResult(expected2);
    cout << endl;
    assert(result2 == expected2);
    deleteTree(root2);

    // Test case 3: Empty tree
    cout << "\nTest 3: Empty tree []" << endl;
    TreeNode* root3 = nullptr;
    vector<vector<int>> result3 = solution.levelOrder(root3);
    vector<vector<int>> expected3 = {};
    cout << "Result: ";
    printResult(result3);
    cout << endl;
    cout << "Expected: ";
    printResult(expected3);
    cout << endl;
    assert(result3 == expected3);

    // Test case 4: Complete binary tree
    cout << "\nTest 4: Complete binary tree [1,2,3,4,5,6,7]" << endl;
    int v7 = 2, v8 = 4, v9 = 5, v10 = 6;
    TreeNode* root4 = buildTree({&v6, &v7, &v1, &v8, &v9, &v10, &v5});
    vector<vector<int>> result4 = solution.levelOrder(root4);
    vector<vector<int>> expected4 = {{1}, {2, 3}, {4, 5, 6, 7}};
    cout << "Result: ";
    printResult(result4);
    cout << endl;
    cout << "Expected: ";
    printResult(expected4);
    cout << endl;
    assert(result4 == expected4);
    deleteTree(root4);

    // Test case 5: Left-skewed tree
    cout << "\nTest 5: Left-skewed tree [1,2,null,3]" << endl;
    TreeNode* root5 = buildTree({&v6, &v7, nullptr, &v1});
    vector<vector<int>> result5 = solution.levelOrder(root5);
    vector<vector<int>> expected5 = {{1}, {2}, {3}};
    cout << "Result: ";
    printResult(result5);
    cout << endl;
    cout << "Expected: ";
    printResult(expected5);
    cout << endl;
    assert(result5 == expected5);
    deleteTree(root5);

    // Test case 6: Right-skewed tree
    cout << "\nTest 6: Right-skewed tree [1,null,2,null,3]" << endl;
    TreeNode* root6 = buildTree({&v6, nullptr, &v7, nullptr, &v1});
    vector<vector<int>> result6 = solution.levelOrder(root6);
    vector<vector<int>> expected6 = {{1}, {2}, {3}};
    cout << "Result: ";
    printResult(result6);
    cout << endl;
    cout << "Expected: ";
    printResult(expected6);
    cout << endl;
    assert(result6 == expected6);
    deleteTree(root6);

    // Test case 7: Tree with negative values
    cout << "\nTest 7: Tree with negative values [-10,9,20,null,null,15,7]" << endl;
    int v11 = -10;
    TreeNode* root7 = buildTree({&v11, &v2, &v3, nullptr, nullptr, &v4, &v5});
    vector<vector<int>> result7 = solution.levelOrder(root7);
    vector<vector<int>> expected7 = {{-10}, {9, 20}, {15, 7}};
    cout << "Result: ";
    printResult(result7);
    cout << endl;
    cout << "Expected: ";
    printResult(expected7);
    cout << endl;
    assert(result7 == expected7);
    deleteTree(root7);

    // Test case 8: Unbalanced tree
    cout << "\nTest 8: Unbalanced tree [1,2,3,4,null,null,5]" << endl;
    TreeNode* root8 = buildTree({&v6, &v7, &v1, &v8, nullptr, nullptr, &v9});
    vector<vector<int>> result8 = solution.levelOrder(root8);
    vector<vector<int>> expected8 = {{1}, {2, 3}, {4, 5}};
    cout << "Result: ";
    printResult(result8);
    cout << endl;
    cout << "Expected: ";
    printResult(expected8);
    cout << endl;
    assert(result8 == expected8);
    deleteTree(root8);

    // Test case 9: Two nodes (parent-left child)
    cout << "\nTest 9: Two nodes [1,2]" << endl;
    TreeNode* root9 = buildTree({&v6, &v7});
    vector<vector<int>> result9 = solution.levelOrder(root9);
    vector<vector<int>> expected9 = {{1}, {2}};
    cout << "Result: ";
    printResult(result9);
    cout << endl;
    cout << "Expected: ";
    printResult(expected9);
    cout << endl;
    assert(result9 == expected9);
    deleteTree(root9);

    cout << "\n✅ All tests passed!" << endl;

    return 0;
}

/**
 * 199. Binary Tree Right Side View
 *
 * Given the root of a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
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
     * Return the right side view of binary tree.
     *
     * @param root Root of the binary tree
     * @return Vector of values visible from right side (rightmost node at each level)
     */
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;

        if (root) {
            q.push(root);
        }

        while (q.size() > 0) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* cur = q.front();
                q.pop();

                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
                if (i == levelSize - 1) {
                    result.push_back(cur->val);
                }
            }
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

int main() {
    Solution solution;

    // Test case 1: Standard example with left nodes visible
    cout << "Test 1: Tree [1,2,3,null,5,null,4]" << endl;
    int v1 = 1, v2 = 2, v3 = 3, v4 = 4, v5 = 5, v6 = 6, v7 = 7;
    TreeNode* root1 = buildTree({&v1, &v2, &v3, nullptr, &v5, nullptr, &v4});
    vector<int> result1 = solution.rightSideView(root1);
    vector<int> expected1 = {1, 3, 4};
    cout << "Result: [";
    for (size_t i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    assert(result1 == expected1);
    deleteTree(root1);

    // Test case 2: Left-skewed tree visible from right
    cout << "\nTest 2: Tree [1,2,3,4,null,null,null,5]" << endl;
    TreeNode* root2 = buildTree({&v1, &v2, &v3, &v4, nullptr, nullptr, nullptr, &v5});
    vector<int> result2 = solution.rightSideView(root2);
    vector<int> expected2 = {1, 3, 4, 5};
    cout << "Result: [";
    for (size_t i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    assert(result2 == expected2);
    deleteTree(root2);

    // Test case 3: Only right children
    cout << "\nTest 3: Tree [1,null,3]" << endl;
    TreeNode* root3 = buildTree({&v1, nullptr, &v3});
    vector<int> result3 = solution.rightSideView(root3);
    vector<int> expected3 = {1, 3};
    cout << "Result: [";
    for (size_t i = 0; i < result3.size(); i++) {
        cout << result3[i];
        if (i < result3.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    assert(result3 == expected3);
    deleteTree(root3);

    // Test case 4: Empty tree
    cout << "\nTest 4: Empty tree" << endl;
    TreeNode* root4 = nullptr;
    vector<int> result4 = solution.rightSideView(root4);
    vector<int> expected4 = {};
    cout << "Result: []" << endl;
    assert(result4 == expected4);

    // Test case 5: Single node
    cout << "\nTest 5: Single node [1]" << endl;
    TreeNode* root5 = buildTree({&v1});
    vector<int> result5 = solution.rightSideView(root5);
    vector<int> expected5 = {1};
    cout << "Result: [" << (result5.empty() ? "" : to_string(result5[0])) << "]" << endl;
    assert(result5 == expected5);
    deleteTree(root5);

    // Test case 6: Complete binary tree
    cout << "\nTest 6: Complete tree [1,2,3,4,5,6,7]" << endl;
    TreeNode* root6 = buildTree({&v1, &v2, &v3, &v4, &v5, &v6, &v7});
    vector<int> result6 = solution.rightSideView(root6);
    vector<int> expected6 = {1, 3, 7};
    cout << "Result: [";
    for (size_t i = 0; i < result6.size(); i++) {
        cout << result6[i];
        if (i < result6.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    assert(result6 == expected6);
    deleteTree(root6);

    // Test case 7: Only left children
    cout << "\nTest 7: Left-skewed tree [1,2,null,3,null,4]" << endl;
    TreeNode* root7 = buildTree({&v1, &v2, nullptr, &v3, nullptr, &v4});
    vector<int> result7 = solution.rightSideView(root7);
    vector<int> expected7 = {1, 2, 3, 4};
    cout << "Result: [";
    for (size_t i = 0; i < result7.size(); i++) {
        cout << result7[i];
        if (i < result7.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    assert(result7 == expected7);
    deleteTree(root7);

    // Test case 8: Two nodes (left child only)
    cout << "\nTest 8: Two nodes [1,2]" << endl;
    TreeNode* root8 = buildTree({&v1, &v2});
    vector<int> result8 = solution.rightSideView(root8);
    vector<int> expected8 = {1, 2};
    cout << "Result: [";
    for (size_t i = 0; i < result8.size(); i++) {
        cout << result8[i];
        if (i < result8.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    assert(result8 == expected8);
    deleteTree(root8);

    // Test case 9: Two nodes (right child only)
    cout << "\nTest 9: Two nodes [1,null,2]" << endl;
    TreeNode* root9 = buildTree({&v1, nullptr, &v2});
    vector<int> result9 = solution.rightSideView(root9);
    vector<int> expected9 = {1, 2};
    cout << "Result: [";
    for (size_t i = 0; i < result9.size(); i++) {
        cout << result9[i];
        if (i < result9.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    assert(result9 == expected9);
    deleteTree(root9);

    cout << "\n✅ All tests passed!" << endl;

    return 0;
}

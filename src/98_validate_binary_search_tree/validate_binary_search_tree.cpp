/**
 * 98. Validate Binary Search Tree
 *
 * Given the root of a binary tree, return true if it is a valid binary search tree,
 * otherwise return false.
 *
 * A valid BST satisfies:
 * - Left subtree contains only nodes with keys less than node's key
 * - Right subtree contains only nodes with keys greater than node's key
 * - Both left and right subtrees are also BSTs
 */

#include <cassert>
#include <climits>
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
     * Determine if a binary tree is a valid binary search tree.
     *
     * @param root Root of the binary tree
     * @return True if the tree is a valid BST, false otherwise
     */
    bool isValidBST(TreeNode* root) { return dfs(root, LONG_MIN, LONG_MAX); }

   private:
    bool dfs(TreeNode* root, long minVal, long maxVal) {
        if (!root) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;

        return dfs(root->left, minVal, root->val) && dfs(root->right, root->val, maxVal);
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

    // Test case 1: Valid BST
    cout << "Test 1: Valid BST [2,1,3]" << endl;
    int v1 = 2, v2 = 1, v3 = 3;
    TreeNode* root1 = buildTree({&v1, &v2, &v3});
    bool result1 = solution.isValidBST(root1);
    bool expected1 = true;
    cout << "Result: " << (result1 ? "true" : "false") << endl;
    cout << "Expected: " << (expected1 ? "true" : "false") << endl;
    assert(result1 == expected1);
    deleteTree(root1);

    // Test case 2: Invalid BST (left child greater than root)
    cout << "\nTest 2: Invalid BST [1,2,3]" << endl;
    TreeNode* root2 = buildTree({&v2, &v1, &v3});
    bool result2 = solution.isValidBST(root2);
    bool expected2 = false;
    cout << "Result: " << (result2 ? "true" : "false") << endl;
    cout << "Expected: " << (expected2 ? "true" : "false") << endl;
    assert(result2 == expected2);
    deleteTree(root2);

    // Test case 3: Invalid BST (right subtree has value less than root)
    cout << "\nTest 3: Invalid BST [5,1,4,null,null,3,6]" << endl;
    int v4 = 5, v5 = 4, v6 = 6;
    TreeNode* root3 = buildTree({&v4, &v2, &v5, nullptr, nullptr, &v3, &v6});
    bool result3 = solution.isValidBST(root3);
    bool expected3 = false;
    cout << "Result: " << (result3 ? "true" : "false") << endl;
    cout << "Expected: " << (expected3 ? "true" : "false") << endl;
    assert(result3 == expected3);
    deleteTree(root3);

    // Test case 4: Single node
    cout << "\nTest 4: Single node [1]" << endl;
    TreeNode* root4 = buildTree({&v2});
    bool result4 = solution.isValidBST(root4);
    bool expected4 = true;
    cout << "Result: " << (result4 ? "true" : "false") << endl;
    cout << "Expected: " << (expected4 ? "true" : "false") << endl;
    assert(result4 == expected4);
    deleteTree(root4);

    // Test case 5: Valid BST with negative values
    cout << "\nTest 5: Valid BST with negatives [0,-1,1]" << endl;
    int v7 = 0, v8 = -1;
    TreeNode* root5 = buildTree({&v7, &v8, &v2});
    bool result5 = solution.isValidBST(root5);
    bool expected5 = true;
    cout << "Result: " << (result5 ? "true" : "false") << endl;
    cout << "Expected: " << (expected5 ? "true" : "false") << endl;
    assert(result5 == expected5);
    deleteTree(root5);

    // Test case 6: Invalid BST (duplicate value)
    cout << "\nTest 6: Invalid BST with duplicate [5,1,5]" << endl;
    TreeNode* root6 = buildTree({&v4, &v2, &v4});
    bool result6 = solution.isValidBST(root6);
    bool expected6 = false;
    cout << "Result: " << (result6 ? "true" : "false") << endl;
    cout << "Expected: " << (expected6 ? "true" : "false") << endl;
    assert(result6 == expected6);
    deleteTree(root6);

    // Test case 7: Invalid BST
    cout << "\nTest 7: Invalid BST [10,5,15,null,null,6,20]" << endl;
    int v9 = 10, v10 = 15, v11 = 20;
    TreeNode* root7 = buildTree({&v9, &v4, &v10, nullptr, nullptr, &v6, &v11});
    bool result7 = solution.isValidBST(root7);
    bool expected7 = false;
    cout << "Result: " << (result7 ? "true" : "false") << endl;
    cout << "Expected: " << (expected7 ? "true" : "false") << endl;
    assert(result7 == expected7);
    deleteTree(root7);

    // Test case 8: Left-skewed valid BST
    cout << "\nTest 8: Left-skewed BST [3,2,null,1]" << endl;
    TreeNode* root8 = buildTree({&v3, &v1, nullptr, &v2});
    bool result8 = solution.isValidBST(root8);
    bool expected8 = true;
    cout << "Result: " << (result8 ? "true" : "false") << endl;
    cout << "Expected: " << (expected8 ? "true" : "false") << endl;
    assert(result8 == expected8);
    deleteTree(root8);

    // Test case 9: Right-skewed valid BST
    cout << "\nTest 9: Right-skewed BST [1,null,2,null,3]" << endl;
    TreeNode* root9 = buildTree({&v2, nullptr, &v1, nullptr, &v3});
    bool result9 = solution.isValidBST(root9);
    bool expected9 = true;
    cout << "Result: " << (result9 ? "true" : "false") << endl;
    cout << "Expected: " << (expected9 ? "true" : "false") << endl;
    assert(result9 == expected9);
    deleteTree(root9);

    cout << "\n✅ All tests passed!" << endl;

    return 0;
}

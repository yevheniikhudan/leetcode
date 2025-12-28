/**
 * 124. Binary Tree Maximum Path Sum
 *
 * A path in a binary tree is a sequence of nodes where each pair of adjacent nodes
 * in the sequence has an edge connecting them. A node can only appear in the sequence
 * at most once. Note that the path does not need to pass through the root.
 *
 * The path sum of a path is the sum of the node's values in the path.
 *
 * Given the root of a binary tree, return the maximum path sum of any non-empty path.
 */

#include <algorithm>
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
     * Find the maximum path sum in a binary tree.
     *
     * @param root Root of the binary tree
     * @return Maximum path sum of any non-empty path
     */
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        dfs(root);

        return maxSum;
    }

   private:
    int maxSum;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int currentSum = root->val;
        int leftSum = max(dfs(root->left), 0);
        int rightSum = max(dfs(root->right), 0);

        currentSum += max(leftSum, rightSum);

        maxSum = max(maxSum, root->val + leftSum + rightSum);

        return currentSum;
    }
};

// Helper function to build tree from level-order vector
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

// Helper function to delete tree
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution solution;

    // Test case 1: Simple tree
    cout << "Test 1: root = [1,2,3]" << endl;
    vector<int*> values1 = {new int(1), new int(2), new int(3)};
    TreeNode* root1 = buildTree(values1);
    int result1 = solution.maxPathSum(root1);
    int expected1 = 6;
    cout << "Result: " << result1 << endl;
    cout << "Expected: " << expected1 << endl;
    assert(result1 == expected1);
    deleteTree(root1);
    for (auto p : values1) delete p;

    // Test case 2: Tree with negative root
    cout << "\nTest 2: root = [-10,9,20,null,null,15,7]" << endl;
    vector<int*> values2 = {new int(-10), new int(9),  new int(20), nullptr,
                            nullptr,      new int(15), new int(7)};
    TreeNode* root2 = buildTree(values2);
    int result2 = solution.maxPathSum(root2);
    int expected2 = 42;
    cout << "Result: " << result2 << endl;
    cout << "Expected: " << expected2 << endl;
    assert(result2 == expected2);
    deleteTree(root2);
    for (auto p : values2)
        if (p) delete p;

    // Test case 3: Single node
    cout << "\nTest 3: root = [-3]" << endl;
    vector<int*> values3 = {new int(-3)};
    TreeNode* root3 = buildTree(values3);
    int result3 = solution.maxPathSum(root3);
    int expected3 = -3;
    cout << "Result: " << result3 << endl;
    cout << "Expected: " << expected3 << endl;
    assert(result3 == expected3);
    deleteTree(root3);
    for (auto p : values3) delete p;

    // Test case 4: All negative values
    cout << "\nTest 4: root = [-2,-1]" << endl;
    vector<int*> values4 = {new int(-2), new int(-1)};
    TreeNode* root4 = buildTree(values4);
    int result4 = solution.maxPathSum(root4);
    int expected4 = -1;
    cout << "Result: " << result4 << endl;
    cout << "Expected: " << expected4 << endl;
    assert(result4 == expected4);
    deleteTree(root4);
    for (auto p : values4) delete p;

    // Test case 5: Path doesn't include root
    cout << "\nTest 5: root = [2,-1,-2]" << endl;
    vector<int*> values5 = {new int(2), new int(-1), new int(-2)};
    TreeNode* root5 = buildTree(values5);
    int result5 = solution.maxPathSum(root5);
    int expected5 = 2;
    cout << "Result: " << result5 << endl;
    cout << "Expected: " << expected5 << endl;
    assert(result5 == expected5);
    deleteTree(root5);
    for (auto p : values5) delete p;

    // Test case 6: Left skewed tree
    cout << "\nTest 6: root = [5,4,null,3,null,2,null,1]" << endl;
    vector<int*> values6 = {new int(5), new int(4), nullptr, new int(3),
                            nullptr,    new int(2), nullptr, new int(1)};
    TreeNode* root6 = buildTree(values6);
    int result6 = solution.maxPathSum(root6);
    int expected6 = 15;
    cout << "Result: " << result6 << endl;
    cout << "Expected: " << expected6 << endl;
    assert(result6 == expected6);
    deleteTree(root6);
    for (auto p : values6)
        if (p) delete p;

    // Test case 7: Larger tree
    cout << "\nTest 7: root = [9,6,-3,null,null,-6,2,null,null,2,null,-6,-6,-6]" << endl;
    vector<int*> values7 = {new int(9),  new int(6),  new int(-3), nullptr,    nullptr,
                            new int(-6), new int(2),  nullptr,     nullptr,    new int(2),
                            nullptr,     new int(-6), new int(-6), new int(-6)};
    TreeNode* root7 = buildTree(values7);
    int result7 = solution.maxPathSum(root7);
    int expected7 = 16;
    cout << "Result: " << result7 << endl;
    cout << "Expected: " << expected7 << endl;
    assert(result7 == expected7);
    deleteTree(root7);
    for (auto p : values7)
        if (p) delete p;

    // Test case 8: Two nodes with positive values
    cout << "\nTest 8: root = [1,2]" << endl;
    vector<int*> values8 = {new int(1), new int(2)};
    TreeNode* root8 = buildTree(values8);
    int result8 = solution.maxPathSum(root8);
    int expected8 = 3;
    cout << "Result: " << result8 << endl;
    cout << "Expected: " << expected8 << endl;
    assert(result8 == expected8);
    deleteTree(root8);
    for (auto p : values8) delete p;

    // Test case 9: Mix of positive and negative
    cout << "\nTest 9: root = [-1,5,null,4,null,null,2,-4]" << endl;
    vector<int*> values9 = {new int(-1), new int(5), nullptr,    new int(4),
                            nullptr,     nullptr,    new int(2), new int(-4)};
    TreeNode* root9 = buildTree(values9);
    int result9 = solution.maxPathSum(root9);
    int expected9 = 11;
    cout << "Result: " << result9 << endl;
    cout << "Expected: " << expected9 << endl;
    assert(result9 == expected9);
    deleteTree(root9);
    for (auto p : values9)
        if (p) delete p;

    cout << "\n✅ All tests passed!" << endl;

    return 0;
}

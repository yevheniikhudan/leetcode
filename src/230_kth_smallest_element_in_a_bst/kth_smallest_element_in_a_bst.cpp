/**
 * 230. Kth Smallest Element in a BST
 *
 * Given the root of a binary search tree, and an integer k, return the kth
 * smallest value (1-indexed) of all the values of the nodes in the tree.
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
    vector<int> inorder;
    int k;

   public:
    /**
     * Find the kth smallest element in a BST.
     *
     * @param root Root of the binary search tree
     * @param k The k value (1-indexed)
     * @return The kth smallest value in the BST
     */
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        inorder.clear();
        dfs(root);

        return inorder[k - 1];
    }

   private:
    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        if (inorder.size() == k) {
            return;
        }

        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
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

    // Test case 1: k=1 (smallest element)
    cout << "Test 1: BST [3,1,4,null,2], k=1" << endl;
    int v1 = 3, v2 = 1, v3 = 4, v4 = 2;
    TreeNode* root1 = buildTree({&v1, &v2, &v3, nullptr, &v4});
    int result1 = solution.kthSmallest(root1, 1);
    int expected1 = 1;
    cout << "Result: " << result1 << endl;
    cout << "Expected: " << expected1 << endl;
    assert(result1 == expected1);
    deleteTree(root1);

    // Test case 2: k=3 (middle element)
    cout << "\nTest 2: BST [5,3,6,2,4,null,null,1], k=3" << endl;
    int v5 = 5, v6 = 6;
    TreeNode* root2 = buildTree({&v5, &v1, &v6, &v4, &v3, nullptr, nullptr, &v2});
    int result2 = solution.kthSmallest(root2, 3);
    int expected2 = 3;
    cout << "Result: " << result2 << endl;
    cout << "Expected: " << expected2 << endl;
    assert(result2 == expected2);
    deleteTree(root2);

    // Test case 3: Single node, k=1
    cout << "\nTest 3: BST [1], k=1" << endl;
    TreeNode* root3 = buildTree({&v2});
    int result3 = solution.kthSmallest(root3, 1);
    int expected3 = 1;
    cout << "Result: " << result3 << endl;
    cout << "Expected: " << expected3 << endl;
    assert(result3 == expected3);
    deleteTree(root3);

    // Test case 4: Two nodes, k=2
    cout << "\nTest 4: BST [2,1], k=2" << endl;
    TreeNode* root4 = buildTree({&v4, &v2});
    int result4 = solution.kthSmallest(root4, 2);
    int expected4 = 2;
    cout << "Result: " << result4 << endl;
    cout << "Expected: " << expected4 << endl;
    assert(result4 == expected4);
    deleteTree(root4);

    // Test case 5: Right-skewed tree, k=3
    cout << "\nTest 5: BST [1,null,2,null,3,null,4], k=3" << endl;
    TreeNode* root5 = buildTree({&v2, nullptr, &v4, nullptr, &v1, nullptr, &v3});
    int result5 = solution.kthSmallest(root5, 3);
    int expected5 = 3;
    cout << "Result: " << result5 << endl;
    cout << "Expected: " << expected5 << endl;
    assert(result5 == expected5);
    deleteTree(root5);

    // Test case 6: Left-skewed tree, k=2
    cout << "\nTest 6: BST [4,3,null,2,null,1], k=2" << endl;
    TreeNode* root6 = buildTree({&v3, &v1, nullptr, &v4, nullptr, &v2});
    int result6 = solution.kthSmallest(root6, 2);
    int expected6 = 2;
    cout << "Result: " << result6 << endl;
    cout << "Expected: " << expected6 << endl;
    assert(result6 == expected6);
    deleteTree(root6);

    // Test case 7: Balanced tree, k=4
    cout << "\nTest 7: BST [4,2,6,1,3,5,7], k=4" << endl;
    int v7 = 7;
    TreeNode* root7 = buildTree({&v3, &v4, &v6, &v2, &v1, &v5, &v7});
    int result7 = solution.kthSmallest(root7, 4);
    int expected7 = 4;
    cout << "Result: " << result7 << endl;
    cout << "Expected: " << expected7 << endl;
    assert(result7 == expected7);
    deleteTree(root7);

    // Test case 8: Last element (maximum)
    cout << "\nTest 8: BST [3,1,4,null,2], k=4" << endl;
    TreeNode* root8 = buildTree({&v1, &v2, &v3, nullptr, &v4});
    int result8 = solution.kthSmallest(root8, 4);
    int expected8 = 4;
    cout << "Result: " << result8 << endl;
    cout << "Expected: " << expected8 << endl;
    assert(result8 == expected8);
    deleteTree(root8);

    // Test case 9: Large tree, k=5
    cout << "\nTest 9: BST [10,5,15,3,7,null,18,1,4,6,8], k=5" << endl;
    int v8 = 10, v9 = 15, v10 = 18, v11 = 8;
    TreeNode* root9 = buildTree({&v8, &v5, &v9, &v1, &v7, nullptr, &v10, &v2, &v3, &v6, &v11});
    int result9 = solution.kthSmallest(root9, 5);
    int expected9 = 6;  // Inorder: [1,3,4,5,6,7,8,10,15,18], 5th = 6
    cout << "Result: " << result9 << endl;
    cout << "Expected: " << expected9 << endl;
    assert(result9 == expected9);
    deleteTree(root9);

    cout << "\n✅ All tests passed!" << endl;

    return 0;
}

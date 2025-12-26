/**
 * 572. Subtree of Another Tree
 *
 * Given the roots of two binary trees root and subRoot, return true if there is a subtree
 * of root with the same structure and node values of subRoot and false otherwise.
 *
 * A subtree of a binary tree tree is a tree that consists of a node in tree and all of
 * this node's descendants. The tree tree could also be considered as a subtree of itself.
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
     * Check if subRoot is a subtree of root.
     *
     * @param root Root of the main binary tree
     * @param subRoot Root of the potential subtree
     * @return true if subRoot is a subtree of root, false otherwise
     */
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }
        if (isSameTree(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

   private:
    bool isSameTree(TreeNode* a, TreeNode* b) {
        if (!a || !b) {
            return a == b;
        }

        if (a->val != b->val) {
            return false;
        }

        return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
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

    // Test case 1: subRoot is subtree at left child
    cout << "Test 1: subRoot is subtree at left child" << endl;
    int v1 = 3, v2 = 4, v3 = 5, v4 = 1, v5 = 2;
    TreeNode* root1 = buildTree({&v1, &v2, &v3, &v4, &v5});
    TreeNode* subRoot1 = buildTree({&v2, &v4, &v5});
    bool result1 = solution.isSubtree(root1, subRoot1);
    cout << "Result: " << (result1 ? "true" : "false") << ", Expected: true" << endl;
    assert(result1 == true);
    deleteTree(root1);
    deleteTree(subRoot1);

    // Test case 2: Extra node in root's subtree
    cout << "\nTest 2: Extra node in root's subtree" << endl;
    int v0 = 0;
    TreeNode* root2 = buildTree({&v1, &v2, &v3, &v4, &v5, nullptr, nullptr, nullptr, nullptr, &v0});
    TreeNode* subRoot2 = buildTree({&v2, &v4, &v5});
    bool result2 = solution.isSubtree(root2, subRoot2);
    cout << "Result: " << (result2 ? "true" : "false") << ", Expected: false" << endl;
    assert(result2 == false);
    deleteTree(root2);
    deleteTree(subRoot2);

    // Test case 3: subRoot equals entire root
    cout << "\nTest 3: subRoot equals entire root" << endl;
    TreeNode* root3 = buildTree({&v4, &v5, &v1});
    TreeNode* subRoot3 = buildTree({&v4, &v5, &v1});
    bool result3 = solution.isSubtree(root3, subRoot3);
    cout << "Result: " << (result3 ? "true" : "false") << ", Expected: true" << endl;
    assert(result3 == true);
    deleteTree(root3);
    deleteTree(subRoot3);

    // Test case 4: Single node trees, matching
    cout << "\nTest 4: Single node trees, matching" << endl;
    TreeNode* root4 = buildTree({&v4});
    TreeNode* subRoot4 = buildTree({&v4});
    bool result4 = solution.isSubtree(root4, subRoot4);
    cout << "Result: " << (result4 ? "true" : "false") << ", Expected: true" << endl;
    assert(result4 == true);
    deleteTree(root4);
    deleteTree(subRoot4);

    // Test case 5: Single node trees, not matching
    cout << "\nTest 5: Single node trees, not matching" << endl;
    TreeNode* root5 = buildTree({&v4});
    TreeNode* subRoot5 = buildTree({&v5});
    bool result5 = solution.isSubtree(root5, subRoot5);
    cout << "Result: " << (result5 ? "true" : "false") << ", Expected: false" << endl;
    assert(result5 == false);
    deleteTree(root5);
    deleteTree(subRoot5);

    // Test case 6: subRoot at right child
    cout << "\nTest 6: subRoot at right child" << endl;
    TreeNode* root6 = buildTree({&v1, &v2, &v3, &v4, &v5});
    TreeNode* subRoot6 = buildTree({&v3});
    bool result6 = solution.isSubtree(root6, subRoot6);
    cout << "Result: " << (result6 ? "true" : "false") << ", Expected: true" << endl;
    assert(result6 == true);
    deleteTree(root6);
    deleteTree(subRoot6);

    // Test case 7: subRoot is leaf node
    cout << "\nTest 7: subRoot is leaf node" << endl;
    TreeNode* root7 = buildTree({&v1, &v2, &v3, &v4, &v5});
    TreeNode* subRoot7 = buildTree({&v5});
    bool result7 = solution.isSubtree(root7, subRoot7);
    cout << "Result: " << (result7 ? "true" : "false") << ", Expected: true" << endl;
    assert(result7 == true);
    deleteTree(root7);
    deleteTree(subRoot7);

    // Test case 8: Similar structure but different values
    cout << "\nTest 8: Similar structure but different values" << endl;
    TreeNode* root8 = buildTree({&v1, &v2, &v3, &v4, &v5});
    TreeNode* subRoot8 = buildTree({&v2, &v4, &v1});
    bool result8 = solution.isSubtree(root8, subRoot8);
    cout << "Result: " << (result8 ? "true" : "false") << ", Expected: false" << endl;
    assert(result8 == false);
    deleteTree(root8);
    deleteTree(subRoot8);

    // Test case 9: subRoot larger than root
    cout << "\nTest 9: subRoot larger than root" << endl;
    TreeNode* root9 = buildTree({&v4, &v5});
    TreeNode* subRoot9 = buildTree({&v4, &v5, &v1});
    bool result9 = solution.isSubtree(root9, subRoot9);
    cout << "Result: " << (result9 ? "true" : "false") << ", Expected: false" << endl;
    assert(result9 == false);
    deleteTree(root9);
    deleteTree(subRoot9);

    // Test case 10: Complex tree, subRoot deep inside
    cout << "\nTest 10: Complex tree, subRoot deep inside" << endl;
    int v6 = 6, v7 = 7, v8 = 8, v9 = 9;
    TreeNode* root10 = buildTree({&v4, &v5, &v1, &v2, &v3, &v6, &v7, &v8, &v9});
    TreeNode* subRoot10 = buildTree({&v2, &v8, &v9});
    bool result10 = solution.isSubtree(root10, subRoot10);
    cout << "Result: " << (result10 ? "true" : "false") << ", Expected: true" << endl;
    assert(result10 == true);
    deleteTree(root10);
    deleteTree(subRoot10);

    // Test case 11: Partial match (substring-like scenario)
    cout << "\nTest 11: Value appears but not as subtree" << endl;
    int v12 = 12;
    TreeNode* root11 = buildTree({&v12});
    TreeNode* subRoot11 = buildTree({&v5});
    bool result11 = solution.isSubtree(root11, subRoot11);
    cout << "Result: " << (result11 ? "true" : "false") << ", Expected: false" << endl;
    assert(result11 == false);
    deleteTree(root11);
    deleteTree(subRoot11);

    cout << "\n✅ All tests passed!" << endl;

    return 0;
}

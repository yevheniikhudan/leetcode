// 110. Balanced Binary Tree
// Difficulty: Easy
// Topics: Tree, Depth-First Search, Binary Tree

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

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
     * Determines if a binary tree is height-balanced.
     *
     * A height-balanced binary tree is one where the depth of the two subtrees
     * of every node never differs by more than 1.
     *
     * @param root The root of the binary tree
     * @return True if the tree is balanced, false otherwise
     */
    bool isBalanced(TreeNode* root) { return dfs(root) != -1; }

   private:
    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int longestLeft = dfs(root->left);
        if (longestLeft == -1) {
            return -1;
        }

        int longestRight = dfs(root->right);
        if (longestRight == -1) {
            return -1;
        }

        if (abs(longestLeft - longestRight) > 1) {
            return -1;
        }

        return std::max(longestLeft, longestRight) + 1;
    }
};

// Helper function to build tree from level-order vector
TreeNode* buildTree(const std::vector<int>& values) {
    if (values.empty() || values[0] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(values[0]);
    std::queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;

    while (!q.empty() && i < values.size()) {
        TreeNode* node = q.front();
        q.pop();

        if (i < values.size() && values[i] != -1) {
            node->left = new TreeNode(values[i]);
            q.push(node->left);
        }
        i++;

        if (i < values.size() && values[i] != -1) {
            node->right = new TreeNode(values[i]);
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

    // Test case 1: Example 1 - Balanced tree
    TreeNode* root1 = buildTree({3, 9, 20, -1, -1, 15, 7});
    std::cout << "Test 1 - Input: [3,9,20,null,null,15,7]" << std::endl;
    std::cout << "Expected: true" << std::endl;
    std::cout << "Got: " << (solution.isBalanced(root1) ? "true" : "false") << std::endl;
    deleteTree(root1);
    std::cout << std::endl;

    // Test case 2: Example 2 - Not balanced
    TreeNode* root2 = buildTree({1, 2, 2, 3, 3, -1, -1, 4, 4});
    std::cout << "Test 2 - Input: [1,2,2,3,3,null,null,4,4]" << std::endl;
    std::cout << "Expected: false" << std::endl;
    std::cout << "Got: " << (solution.isBalanced(root2) ? "true" : "false") << std::endl;
    deleteTree(root2);
    std::cout << std::endl;

    // Test case 3: Empty tree
    TreeNode* root3 = buildTree({});
    std::cout << "Test 3 - Input: []" << std::endl;
    std::cout << "Expected: true" << std::endl;
    std::cout << "Got: " << (solution.isBalanced(root3) ? "true" : "false") << std::endl;
    deleteTree(root3);
    std::cout << std::endl;

    // Test case 4: Single node
    TreeNode* root4 = buildTree({1});
    std::cout << "Test 4 - Input: [1]" << std::endl;
    std::cout << "Expected: true" << std::endl;
    std::cout << "Got: " << (solution.isBalanced(root4) ? "true" : "false") << std::endl;
    deleteTree(root4);
    std::cout << std::endl;

    // Test case 5: Left-skewed tree
    TreeNode* root5 = buildTree({1, 2, -1, 3});
    std::cout << "Test 5 - Input: [1,2,null,3]" << std::endl;
    std::cout << "Expected: false" << std::endl;
    std::cout << "Got: " << (solution.isBalanced(root5) ? "true" : "false") << std::endl;
    deleteTree(root5);
    std::cout << std::endl;

    // Test case 6: Balanced complete tree
    TreeNode* root6 = buildTree({1, 2, 3, 4, 5, 6, 7});
    std::cout << "Test 6 - Input: [1,2,3,4,5,6,7]" << std::endl;
    std::cout << "Expected: true" << std::endl;
    std::cout << "Got: " << (solution.isBalanced(root6) ? "true" : "false") << std::endl;
    deleteTree(root6);
    std::cout << std::endl;

    return 0;
}

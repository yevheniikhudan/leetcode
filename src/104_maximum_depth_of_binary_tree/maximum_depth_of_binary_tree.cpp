// 104. Maximum Depth of Binary Tree
// Difficulty: Easy
// Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>  // for std::pair
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct NodeDepthPair {
    int depth;
    TreeNode* node;
    NodeDepthPair(TreeNode* n, int d) : node(n), depth(d) {}
};

class Solution {
   public:
    /**
     * Returns the maximum depth of a binary tree.
     *
     * @param root The root of the binary tree
     * @return The maximum depth (number of nodes along longest path from root to leaf)
     */
    int maxDepth(TreeNode* root) {
        std::stack<NodeDepthPair> stk;
        stk.push(NodeDepthPair(root, 1));
        int res = 0;

        while (!stk.empty()) {
            NodeDepthPair current = stk.top();
            stk.pop();
            TreeNode* node = current.node;
            int depth = current.depth;

            if (node != nullptr) {
                res = std::max(res, depth);
                stk.push(NodeDepthPair(node->left, depth + 1));
                stk.push(NodeDepthPair(node->right, depth + 1));
            }
        }
        return res;
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

    // Test case 1: Example 1
    TreeNode* root1 = buildTree({3, 9, 20, -1, -1, 15, 7});
    std::cout << "Test 1 - Input: [3,9,20,null,null,15,7]" << std::endl;
    std::cout << "Expected: 3" << std::endl;
    std::cout << "Got: " << solution.maxDepth(root1) << std::endl;
    deleteTree(root1);
    std::cout << std::endl;

    // Test case 2: Example 2
    TreeNode* root2 = buildTree({1, -1, 2});
    std::cout << "Test 2 - Input: [1,null,2]" << std::endl;
    std::cout << "Expected: 2" << std::endl;
    std::cout << "Got: " << solution.maxDepth(root2) << std::endl;
    deleteTree(root2);
    std::cout << std::endl;

    // Test case 3: Empty tree
    TreeNode* root3 = buildTree({});
    std::cout << "Test 3 - Input: []" << std::endl;
    std::cout << "Expected: 0" << std::endl;
    std::cout << "Got: " << solution.maxDepth(root3) << std::endl;
    deleteTree(root3);
    std::cout << std::endl;

    // Test case 4: Single node
    TreeNode* root4 = buildTree({1});
    std::cout << "Test 4 - Input: [1]" << std::endl;
    std::cout << "Expected: 1" << std::endl;
    std::cout << "Got: " << solution.maxDepth(root4) << std::endl;
    deleteTree(root4);
    std::cout << std::endl;

    // Test case 5: Left-skewed tree
    TreeNode* root5 = buildTree({1, 2, -1, 3, -1, 4});
    std::cout << "Test 5 - Input: [1,2,null,3,null,4]" << std::endl;
    std::cout << "Expected: 4" << std::endl;
    std::cout << "Got: " << solution.maxDepth(root5) << std::endl;
    deleteTree(root5);
    std::cout << std::endl;

    // Test case 6: Balanced tree
    TreeNode* root6 = buildTree({1, 2, 3, 4, 5, 6, 7});
    std::cout << "Test 6 - Input: [1,2,3,4,5,6,7]" << std::endl;
    std::cout << "Expected: 3" << std::endl;
    std::cout << "Got: " << solution.maxDepth(root6) << std::endl;
    deleteTree(root6);
    std::cout << std::endl;

    return 0;
}

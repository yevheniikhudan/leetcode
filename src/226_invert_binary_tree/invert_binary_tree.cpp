// 226. Invert Binary Tree
// Difficulty: Easy
// Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree

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
     * Inverts a binary tree (mirrors it).
     *
     * @param root The root of the binary tree
     * @return The root of the inverted binary tree
     */
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
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

// Helper function to convert tree to level-order vector
std::vector<int> treeToList(TreeNode* root) {
    if (!root) {
        return {};
    }

    std::vector<int> result;
    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node) {
            result.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back(-1);  // Use -1 to represent null
        }
    }

    // Remove trailing -1 values
    while (!result.empty() && result.back() == -1) {
        result.pop_back();
    }

    return result;
}

// Helper function to print vector
void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] == -1) {
            std::cout << "null";
        } else {
            std::cout << vec[i];
        }
        if (i < vec.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;
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
    TreeNode* root1 = buildTree({4, 2, 7, 1, 3, 6, 9});
    std::cout << "Test 1 - Input: [4,2,7,1,3,6,9]" << std::endl;
    std::cout << "Expected: [4,7,2,9,6,3,1]" << std::endl;
    std::cout << "Got: ";
    TreeNode* result1 = solution.invertTree(root1);
    printVector(treeToList(result1));
    deleteTree(result1);
    std::cout << std::endl;

    // Test case 2: Example 2
    TreeNode* root2 = buildTree({2, 1, 3});
    std::cout << "Test 2 - Input: [2,1,3]" << std::endl;
    std::cout << "Expected: [2,3,1]" << std::endl;
    std::cout << "Got: ";
    TreeNode* result2 = solution.invertTree(root2);
    printVector(treeToList(result2));
    deleteTree(result2);
    std::cout << std::endl;

    // Test case 3: Empty tree
    TreeNode* root3 = buildTree({});
    std::cout << "Test 3 - Input: []" << std::endl;
    std::cout << "Expected: []" << std::endl;
    std::cout << "Got: ";
    TreeNode* result3 = solution.invertTree(root3);
    printVector(treeToList(result3));
    deleteTree(result3);
    std::cout << std::endl;

    // Test case 4: Single node
    TreeNode* root4 = buildTree({1});
    std::cout << "Test 4 - Input: [1]" << std::endl;
    std::cout << "Expected: [1]" << std::endl;
    std::cout << "Got: ";
    TreeNode* result4 = solution.invertTree(root4);
    printVector(treeToList(result4));
    deleteTree(result4);
    std::cout << std::endl;

    // Test case 5: Left-skewed tree
    TreeNode* root5 = buildTree({1, 2, -1, 3});
    std::cout << "Test 5 - Input: [1,2,null,3]" << std::endl;
    std::cout << "Expected: [1,null,2,null,3]" << std::endl;
    std::cout << "Got: ";
    TreeNode* result5 = solution.invertTree(root5);
    printVector(treeToList(result5));
    deleteTree(result5);
    std::cout << std::endl;

    return 0;
}

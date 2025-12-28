/**
 * 105. Construct Binary Tree from Preorder and Inorder Traversal
 *
 * Given two integer arrays preorder and inorder where preorder is the preorder
 * traversal of a binary tree and inorder is the inorder traversal of the same tree,
 * construct and return the binary tree.
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
     * Construct binary tree from preorder and inorder traversals.
     *
     * @param preorder Preorder traversal of the tree
     * @param inorder Inorder traversal of the tree
     * @return Root of the constructed binary tree
     */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> indices;
        preId = 0;

        for (int i = 0; i < inorder.size(); i++) {
            indices[inorder[i]] = i;
        }

        return dfs(preorder, indices, 0, preorder.size() - 1);
    }

   private:
    int preId;

    TreeNode* dfs(vector<int>& preorder, unordered_map<int, int>& indices, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preId++]);
        int mid = indices[root->val];

        root->left = dfs(preorder, indices, left, mid - 1);
        root->right = dfs(preorder, indices, mid + 1, right);

        return root;
    }
};

// Helper function to convert tree to level-order vector
vector<int> treeToVector(TreeNode* root) {
    vector<int> result;
    if (!root) {
        return result;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node) {
            result.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back(-1001);  // Use -1001 as null marker (outside constraint range)
        }
    }

    // Remove trailing null markers
    while (!result.empty() && result.back() == -1001) {
        result.pop_back();
    }

    return result;
}

// Helper function to delete tree
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Helper function to print vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] == -1001) {
            cout << "null";
        } else {
            cout << vec[i];
        }
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution solution;

    // Test case 1: Example tree
    cout << "Test 1: preorder=[3,9,20,15,7], inorder=[9,3,15,20,7]" << endl;
    vector<int> preorder1 = {3, 9, 20, 15, 7};
    vector<int> inorder1 = {9, 3, 15, 20, 7};
    TreeNode* result1 = solution.buildTree(preorder1, inorder1);
    vector<int> resultVec1 = treeToVector(result1);
    vector<int> expected1 = {3, 9, 20, -1001, -1001, 15, 7};
    cout << "Result: ";
    printVector(resultVec1);
    cout << endl << "Expected: ";
    printVector(expected1);
    cout << endl;
    assert(resultVec1 == expected1);
    deleteTree(result1);

    // Test case 2: Single node
    cout << "\nTest 2: preorder=[-1], inorder=[-1]" << endl;
    vector<int> preorder2 = {-1};
    vector<int> inorder2 = {-1};
    TreeNode* result2 = solution.buildTree(preorder2, inorder2);
    vector<int> resultVec2 = treeToVector(result2);
    vector<int> expected2 = {-1};
    cout << "Result: ";
    printVector(resultVec2);
    cout << endl << "Expected: ";
    printVector(expected2);
    cout << endl;
    assert(resultVec2 == expected2);
    deleteTree(result2);

    // Test case 3: Left-skewed tree
    cout << "\nTest 3: preorder=[1,2,3], inorder=[3,2,1]" << endl;
    vector<int> preorder3 = {1, 2, 3};
    vector<int> inorder3 = {3, 2, 1};
    TreeNode* result3 = solution.buildTree(preorder3, inorder3);
    vector<int> resultVec3 = treeToVector(result3);
    vector<int> expected3 = {1, 2, -1001, 3};
    cout << "Result: ";
    printVector(resultVec3);
    cout << endl << "Expected: ";
    printVector(expected3);
    cout << endl;
    assert(resultVec3 == expected3);
    deleteTree(result3);

    // Test case 4: Right-skewed tree
    cout << "\nTest 4: preorder=[1,2,3], inorder=[1,2,3]" << endl;
    vector<int> preorder4 = {1, 2, 3};
    vector<int> inorder4 = {1, 2, 3};
    TreeNode* result4 = solution.buildTree(preorder4, inorder4);
    vector<int> resultVec4 = treeToVector(result4);
    vector<int> expected4 = {1, -1001, 2, -1001, 3};
    cout << "Result: ";
    printVector(resultVec4);
    cout << endl << "Expected: ";
    printVector(expected4);
    cout << endl;
    assert(resultVec4 == expected4);
    deleteTree(result4);

    // Test case 5: Balanced tree
    cout << "\nTest 5: preorder=[1,2,4,5,3,6,7], inorder=[4,2,5,1,6,3,7]" << endl;
    vector<int> preorder5 = {1, 2, 4, 5, 3, 6, 7};
    vector<int> inorder5 = {4, 2, 5, 1, 6, 3, 7};
    TreeNode* result5 = solution.buildTree(preorder5, inorder5);
    vector<int> resultVec5 = treeToVector(result5);
    vector<int> expected5 = {1, 2, 3, 4, 5, 6, 7};
    cout << "Result: ";
    printVector(resultVec5);
    cout << endl << "Expected: ";
    printVector(expected5);
    cout << endl;
    assert(resultVec5 == expected5);
    deleteTree(result5);

    // Test case 6: Two nodes (left child)
    cout << "\nTest 6: preorder=[1,2], inorder=[2,1]" << endl;
    vector<int> preorder6 = {1, 2};
    vector<int> inorder6 = {2, 1};
    TreeNode* result6 = solution.buildTree(preorder6, inorder6);
    vector<int> resultVec6 = treeToVector(result6);
    vector<int> expected6 = {1, 2};
    cout << "Result: ";
    printVector(resultVec6);
    cout << endl << "Expected: ";
    printVector(expected6);
    cout << endl;
    assert(resultVec6 == expected6);
    deleteTree(result6);

    // Test case 7: Two nodes (right child)
    cout << "\nTest 7: preorder=[1,2], inorder=[1,2]" << endl;
    vector<int> preorder7 = {1, 2};
    vector<int> inorder7 = {1, 2};
    TreeNode* result7 = solution.buildTree(preorder7, inorder7);
    vector<int> resultVec7 = treeToVector(result7);
    vector<int> expected7 = {1, -1001, 2};
    cout << "Result: ";
    printVector(resultVec7);
    cout << endl << "Expected: ";
    printVector(expected7);
    cout << endl;
    assert(resultVec7 == expected7);
    deleteTree(result7);

    // Test case 8: Larger unbalanced tree
    cout << "\nTest 8: preorder=[3,9,8,5,20,15,7], inorder=[8,9,5,3,15,20,7]" << endl;
    vector<int> preorder8 = {3, 9, 8, 5, 20, 15, 7};
    vector<int> inorder8 = {8, 9, 5, 3, 15, 20, 7};
    TreeNode* result8 = solution.buildTree(preorder8, inorder8);
    vector<int> resultVec8 = treeToVector(result8);
    vector<int> expected8 = {3, 9, 20, 8, 5, 15, 7};
    cout << "Result: ";
    printVector(resultVec8);
    cout << endl << "Expected: ";
    printVector(expected8);
    cout << endl;
    assert(resultVec8 == expected8);
    deleteTree(result8);

    cout << "\n✅ All tests passed!" << endl;

    return 0;
}

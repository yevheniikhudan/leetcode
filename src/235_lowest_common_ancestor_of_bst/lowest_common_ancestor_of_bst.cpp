/**
 * 235. Lowest Common Ancestor of a Binary Search Tree
 *
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes
 * in the BST.
 *
 * According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined between
 * two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a
 * node to be a descendant of itself)."
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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    /**
     * Find the lowest common ancestor of two nodes in a BST.
     *
     * @param root Root of the BST
     * @param p First node
     * @param q Second node
     * @return The lowest common ancestor node
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            // Both p and q are in left subtree
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            // Both p and q are in right subtree
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            // Found the split point (or one of p/q is root)
            else {
                return root;
            }
        }
        
        return root;
    }
};

// Helper function to build a BST from a vector (level-order)
TreeNode* buildBST(const vector<int*>& values) {
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

// Helper to find a node with given value in the tree
TreeNode* findNode(TreeNode* root, int val) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->val == val) {
        return root;
    }

    TreeNode* left = findNode(root->left, val);
    if (left != nullptr) {
        return left;
    }

    return findNode(root->right, val);
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

    // Test case 1: LCA of nodes in different subtrees
    cout << "Test 1: LCA of nodes in different subtrees (2, 8)" << endl;
    int v0 = 6, v1 = 2, v2 = 8, v3 = 0, v4 = 4, v5 = 7, v6 = 9, v7 = 3, v8 = 5;
    TreeNode* root1 = buildBST({&v0, &v1, &v2, &v3, &v4, &v5, &v6, nullptr, nullptr, &v7, &v8});
    TreeNode* p1 = findNode(root1, 2);
    TreeNode* q1 = findNode(root1, 8);
    TreeNode* result1 = solution.lowestCommonAncestor(root1, p1, q1);
    cout << "Result: " << (result1 ? result1->val : -1) << ", Expected: 6" << endl;
    assert(result1 && result1->val == 6);
    deleteTree(root1);

    // Test case 2: LCA where one node is ancestor of the other
    cout << "\nTest 2: LCA where one node is ancestor of the other (2, 4)" << endl;
    TreeNode* root2 = buildBST({&v0, &v1, &v2, &v3, &v4, &v5, &v6, nullptr, nullptr, &v7, &v8});
    TreeNode* p2 = findNode(root2, 2);
    TreeNode* q2 = findNode(root2, 4);
    TreeNode* result2 = solution.lowestCommonAncestor(root2, p2, q2);
    cout << "Result: " << (result2 ? result2->val : -1) << ", Expected: 2" << endl;
    assert(result2 && result2->val == 2);
    deleteTree(root2);

    // Test case 3: Small tree
    cout << "\nTest 3: Small tree (2, 1)" << endl;
    int v9 = 2, v10 = 1;
    TreeNode* root3 = buildBST({&v9, &v10});
    TreeNode* p3 = findNode(root3, 2);
    TreeNode* q3 = findNode(root3, 1);
    TreeNode* result3 = solution.lowestCommonAncestor(root3, p3, q3);
    cout << "Result: " << (result3 ? result3->val : -1) << ", Expected: 2" << endl;
    assert(result3 && result3->val == 2);
    deleteTree(root3);

    // Test case 4: LCA of leaf nodes
    cout << "\nTest 4: LCA of leaf nodes (3, 5)" << endl;
    TreeNode* root4 = buildBST({&v0, &v1, &v2, &v3, &v4, &v5, &v6, nullptr, nullptr, &v7, &v8});
    TreeNode* p4 = findNode(root4, 3);
    TreeNode* q4 = findNode(root4, 5);
    TreeNode* result4 = solution.lowestCommonAncestor(root4, p4, q4);
    cout << "Result: " << (result4 ? result4->val : -1) << ", Expected: 4" << endl;
    assert(result4 && result4->val == 4);
    deleteTree(root4);

    // Test case 5: LCA in right subtree
    cout << "\nTest 5: LCA in right subtree (7, 9)" << endl;
    TreeNode* root5 = buildBST({&v0, &v1, &v2, &v3, &v4, &v5, &v6, nullptr, nullptr, &v7, &v8});
    TreeNode* p5 = findNode(root5, 7);
    TreeNode* q5 = findNode(root5, 9);
    TreeNode* result5 = solution.lowestCommonAncestor(root5, p5, q5);
    cout << "Result: " << (result5 ? result5->val : -1) << ", Expected: 8" << endl;
    assert(result5 && result5->val == 8);
    deleteTree(root5);

    // Test case 6: LCA is the root
    cout << "\nTest 6: LCA is the root (0, 9)" << endl;
    TreeNode* root6 = buildBST({&v0, &v1, &v2, &v3, &v4, &v5, &v6, nullptr, nullptr, &v7, &v8});
    TreeNode* p6 = findNode(root6, 0);
    TreeNode* q6 = findNode(root6, 9);
    TreeNode* result6 = solution.lowestCommonAncestor(root6, p6, q6);
    cout << "Result: " << (result6 ? result6->val : -1) << ", Expected: 6" << endl;
    assert(result6 && result6->val == 6);
    deleteTree(root6);

    // Test case 7: Adjacent nodes (parent-child)
    cout << "\nTest 7: Adjacent nodes (2, 0)" << endl;
    TreeNode* root7 = buildBST({&v0, &v1, &v2, &v3, &v4, &v5, &v6, nullptr, nullptr, &v7, &v8});
    TreeNode* p7 = findNode(root7, 2);
    TreeNode* q7 = findNode(root7, 0);
    TreeNode* result7 = solution.lowestCommonAncestor(root7, p7, q7);
    cout << "Result: " << (result7 ? result7->val : -1) << ", Expected: 2" << endl;
    assert(result7 && result7->val == 2);
    deleteTree(root7);

    // Test case 8: Root and child
    cout << "\nTest 8: Root and child (6, 8)" << endl;
    TreeNode* root8 = buildBST({&v0, &v1, &v2, &v3, &v4, &v5, &v6, nullptr, nullptr, &v7, &v8});
    TreeNode* p8 = findNode(root8, 6);
    TreeNode* q8 = findNode(root8, 8);
    TreeNode* result8 = solution.lowestCommonAncestor(root8, p8, q8);
    cout << "Result: " << (result8 ? result8->val : -1) << ", Expected: 6" << endl;
    assert(result8 && result8->val == 6);
    deleteTree(root8);

    // Test case 9: Deep nodes on same side
    cout << "\nTest 9: Deep nodes on same side (3, 4)" << endl;
    TreeNode* root9 = buildBST({&v0, &v1, &v2, &v3, &v4, &v5, &v6, nullptr, nullptr, &v7, &v8});
    TreeNode* p9 = findNode(root9, 3);
    TreeNode* q9 = findNode(root9, 4);
    TreeNode* result9 = solution.lowestCommonAncestor(root9, p9, q9);
    cout << "Result: " << (result9 ? result9->val : -1) << ", Expected: 4" << endl;
    assert(result9 && result9->val == 4);
    deleteTree(root9);

    // Test case 10: Reversed order (q, p instead of p, q)
    cout << "\nTest 10: Reversed order (8, 2)" << endl;
    TreeNode* root10 = buildBST({&v0, &v1, &v2, &v3, &v4, &v5, &v6, nullptr, nullptr, &v7, &v8});
    TreeNode* p10 = findNode(root10, 8);
    TreeNode* q10 = findNode(root10, 2);
    TreeNode* result10 = solution.lowestCommonAncestor(root10, p10, q10);
    cout << "Result: " << (result10 ? result10->val : -1) << ", Expected: 6" << endl;
    assert(result10 && result10->val == 6);
    deleteTree(root10);

    cout << "\n✅ All tests passed!" << endl;

    return 0;
}

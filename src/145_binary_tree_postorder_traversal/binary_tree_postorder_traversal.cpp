#include <climits>
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
    vector<int> postorderTraversal(TreeNode* root) {
        deque<pair<TreeNode*, bool>> stack;
        vector<int> res;
        stack.push_back({root, false});

        while (stack.size() > 0) {
            pair<TreeNode*, bool> p = stack.back();
            stack.pop_back();
            if (p.second) {
                res.push_back(p.first->val);
            } else if (p.first) {
                stack.push_back({p.first, true});
                stack.push_back({p.first->right, false});
                stack.push_back({p.first->left, false});
            }
        }

        return res;
    }
};

// Helper to build tree from level order array (use INT_MIN for null)
TreeNode* buildTree(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    vector<TreeNode*> nodes;
    for (int v : arr) nodes.push_back(v == INT_MIN ? nullptr : new TreeNode(v));
    int pos = 1;
    for (int i = 0; i < nodes.size() && pos < nodes.size(); ++i) {
        if (nodes[i]) {
            if (pos < nodes.size()) nodes[i]->left = nodes[pos++];
            if (pos < nodes.size()) nodes[i]->right = nodes[pos++];
        }
    }
    return nodes[0];
}

int main() {
    Solution sol;
    struct Test {
        vector<int> tree;
        vector<int> expected;
    } tests[] = {
        {{1, INT_MIN, 2, 3}, {3, 2, 1}}, {{}, {}}, {{1}, {1}}, {{1, 2, 3}, {2, 3, 1}},
        {{1, INT_MIN, 2}, {2, 1}},
    };
    for (int i = 0; i < 5; ++i) {
        TreeNode* root = buildTree(tests[i].tree);
        vector<int> result = sol.postorderTraversal(root);
        cout << "Test " << (i + 1) << ": [";
        for (int v : result) cout << v << ",";
        cout << "] | [";
        for (int v : tests[i].expected) cout << v << ",";
        cout << "]" << endl;
    }
    return 0;
}

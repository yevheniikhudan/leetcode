#include <cstddef>
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
    int maxProduct(TreeNode* root) {
        int MOD = 1'000'000'007;
        totalSum = treeSum(root);
        maxProd = 0;
        dfs(root);
        return (int)(maxProd % MOD);
    }

   private:
    long long maxProd = 0;
    int totalSum = 0;
    int treeSum(TreeNode* node) {
        if (!node) return 0;
        return node->val + treeSum(node->left) + treeSum(node->right);
    }
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int subSum = dfs(node->left) + dfs(node->right) + node->val;
        maxProd = std::max(maxProd, 1LL * subSum * (totalSum - subSum));
        return subSum;
    }
};

// ...existing code...

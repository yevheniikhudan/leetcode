/**
 * 297. Serialize and Deserialize Binary Tree
 *
 * Design an algorithm to serialize and deserialize a binary tree.
 */

#include <cassert>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
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

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serializeHelper(root, res);
        return res;
    }
    void serializeHelper(TreeNode* root, string& res) {
        if (!root) {
            res += "N,";
            return;
        }
        res += to_string(root->val) + ",";
        serializeHelper(root->left, res);
        serializeHelper(root->right, res);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data) {
        vector<string> nodes;
        string token;
        stringstream ss(data);
        while (getline(ss, token, ',')) {
            nodes.push_back(token);
        }
        int idx = 0;
        return deserializeHelper(nodes, idx);
    }
    TreeNode* deserializeHelper(const vector<string>& nodes, int& idx) {
        if (nodes[idx] == "N") {
            idx++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(nodes[idx++]));
        root->left = deserializeHelper(nodes, idx);
        root->right = deserializeHelper(nodes, idx);
        return root;
    }
};

// Helper functions for testing
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
vector<int> treeToVector(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
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
            result.push_back(-1001);
        }
    }
    while (!result.empty() && result.back() == -1001) {
        result.pop_back();
    }
    return result;
}
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
int main() {
    Codec codec;
    // Test case 1: Example tree
    cout << "Test 1: root = [1,2,3,null,null,4,5]" << endl;
    vector<int*> values1 = {new int(1), new int(2), new int(3), nullptr,
                            nullptr,    new int(4), new int(5)};
    TreeNode* root1 = buildTree(values1);
    string data1 = codec.serialize(root1);
    TreeNode* result1 = codec.deserialize(data1);
    vector<int> resultVec1 = treeToVector(result1);
    vector<int> expected1 = {1, 2, 3, -1001, -1001, 4, 5};
    cout << "Result: ";
    for (int v : resultVec1) cout << (v == -1001 ? "null," : to_string(v) + ",");
    cout << endl << "Expected: 1,2,3,null,null,4,5" << endl;
    assert(resultVec1 == expected1);
    deleteTree(root1);
    deleteTree(result1);
    for (auto p : values1)
        if (p) delete p;
    // Test case 2: Empty tree
    cout << "\nTest 2: root = []" << endl;
    vector<int*> values2 = {};
    TreeNode* root2 = buildTree(values2);
    string data2 = codec.serialize(root2);
    TreeNode* result2 = codec.deserialize(data2);
    vector<int> resultVec2 = treeToVector(result2);
    vector<int> expected2 = {};
    cout << "Result: ";
    for (int v : resultVec2) cout << (v == -1001 ? "null," : to_string(v) + ",");
    cout << endl << "Expected: " << endl;
    assert(resultVec2 == expected2);
    deleteTree(root2);
    deleteTree(result2);
    // Test case 3: Single node
    cout << "\nTest 3: root = [42]" << endl;
    vector<int*> values3 = {new int(42)};
    TreeNode* root3 = buildTree(values3);
    string data3 = codec.serialize(root3);
    TreeNode* result3 = codec.deserialize(data3);
    vector<int> resultVec3 = treeToVector(result3);
    vector<int> expected3 = {42};
    cout << "Result: ";
    for (int v : resultVec3) cout << (v == -1001 ? "null," : to_string(v) + ",");
    cout << endl << "Expected: 42" << endl;
    assert(resultVec3 == expected3);
    deleteTree(root3);
    deleteTree(result3);
    for (auto p : values3)
        if (p) delete p;
    // Test case 4: Left-skewed tree
    cout << "\nTest 4: root = [1,2,null,3,null,4]" << endl;
    vector<int*> values4 = {new int(1), new int(2), nullptr, new int(3), nullptr, new int(4)};
    TreeNode* root4 = buildTree(values4);
    string data4 = codec.serialize(root4);
    TreeNode* result4 = codec.deserialize(data4);
    vector<int> resultVec4 = treeToVector(result4);
    vector<int> expected4 = {1, 2, -1001, 3, -1001, 4};
    cout << "Result: ";
    for (int v : resultVec4) cout << (v == -1001 ? "null," : to_string(v) + ",");
    cout << endl << "Expected: 1,2,null,3,null,4" << endl;
    assert(resultVec4 == expected4);
    deleteTree(root4);
    deleteTree(result4);
    for (auto p : values4)
        if (p) delete p;
    // Test case 5: Right-skewed tree
    cout << "\nTest 5: root = [1,null,2,null,3,null,4]" << endl;
    vector<int*> values5 = {new int(1), nullptr, new int(2), nullptr,
                            new int(3), nullptr, new int(4)};
    TreeNode* root5 = buildTree(values5);
    string data5 = codec.serialize(root5);
    TreeNode* result5 = codec.deserialize(data5);
    vector<int> resultVec5 = treeToVector(result5);
    vector<int> expected5 = {1, -1001, 2, -1001, 3, -1001, 4};
    cout << "Result: ";
    for (int v : resultVec5) cout << (v == -1001 ? "null," : to_string(v) + ",");
    cout << endl << "Expected: 1,null,2,null,3,null,4" << endl;
    assert(resultVec5 == expected5);
    deleteTree(root5);
    deleteTree(result5);
    for (auto p : values5)
        if (p) delete p;
    cout << "\n✅ All tests passed!" << endl;
    return 0;
}

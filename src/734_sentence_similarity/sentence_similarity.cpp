#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) return false;

        unordered_set<pair<string, string>> pairs;
        for (auto& p : similarPairs) {
            pairs.insert({p[0], p[1]});
            pairs.insert({p[1], p[0]});
        }

        for (int i = 0; i < sentence1.size(); i++) {
            if (sentence1[i] == sentence2[i]) continue;
            if (pairs.find({sentence1[i], sentence2[i]}) == pairs.end()) return false;
        }

        return true;
    }
};

// Helper function to print vector of strings
void printSentence(const vector<string>& sentence) {
    cout << "[";
    for (size_t i = 0; i < sentence.size(); i++) {
        cout << sentence[i];
        if (i < sentence.size() - 1) cout << ", ";
    }
    cout << "]";
}

// Helper function to print vector of vector of strings
void printPairs(const vector<vector<string>>& pairs) {
    cout << "[";
    for (size_t i = 0; i < pairs.size(); i++) {
        cout << "[" << pairs[i][0] << ", " << pairs[i][1] << "]";
        if (i < pairs.size() - 1) cout << ", ";
    }
    cout << "]";
}

// Helper function to print test result
void printResult(bool actual, bool expected) {
    cout << (actual ? "true" : "false") << " | " << (expected ? "true" : "false");
    if (actual == expected) {
        cout << " | PASS" << endl;
    } else {
        cout << " | FAIL" << endl;
    }
}

int main() {
    Solution solution;

    // Test case 1: Sentences with similar pairs
    vector<string> sentence1_1 = {"great", "acting", "skills"};
    vector<string> sentence2_1 = {"fine", "drama", "talent"};
    vector<vector<string>> similarPairs_1 = {{"great", "fine"}, {"acting", "drama"}, {"skills", "talent"}};
    bool result1 = solution.areSentencesSimilar(sentence1_1, sentence2_1, similarPairs_1);
    cout << "Test 1: ";
    printResult(result1, true);

    // Test case 2: Sentences of different lengths
    vector<string> sentence1_2 = {"I", "love", "leetcode"};
    vector<string> sentence2_2 = {"I", "love", "leetcode", "code"};
    vector<vector<string>> similarPairs_2 = {};
    bool result2 = solution.areSentencesSimilar(sentence1_2, sentence2_2, similarPairs_2);
    cout << "Test 2: ";
    printResult(result2, false);

    // Test case 3: Identical sentences
    vector<string> sentence1_3 = {"hello", "world"};
    vector<string> sentence2_3 = {"hello", "world"};
    vector<vector<string>> similarPairs_3 = {};
    bool result3 = solution.areSentencesSimilar(sentence1_3, sentence2_3, similarPairs_3);
    cout << "Test 3: ";
    printResult(result3, true);

    // Test case 4: Single word sentences
    vector<string> sentence1_4 = {"a"};
    vector<string> sentence2_4 = {"b"};
    vector<vector<string>> similarPairs_4 = {{"a", "b"}};
    bool result4 = solution.areSentencesSimilar(sentence1_4, sentence2_4, similarPairs_4);
    cout << "Test 4: ";
    printResult(result4, true);

    // Test case 5: Transitive similarity (not similar due to lack of direct mapping)
    vector<string> sentence1_5 = {"ab", "cd"};
    vector<string> sentence2_5 = {"ab", "zz"};
    vector<vector<string>> similarPairs_5 = {{"ab", "cd"}, {"cd", "zz"}};
    bool result5 = solution.areSentencesSimilar(sentence1_5, sentence2_5, similarPairs_5);
    cout << "Test 5: ";
    printResult(result5, false);

    // Test case 6: Partial matching
    vector<string> sentence1_6 = {"a", "b", "c"};
    vector<string> sentence2_6 = {"a", "b", "c"};
    vector<vector<string>> similarPairs_6 = {{"a", "x"}, {"b", "y"}};
    bool result6 = solution.areSentencesSimilar(sentence1_6, sentence2_6, similarPairs_6);
    cout << "Test 6: ";
    printResult(result6, true);

    return 0;
}

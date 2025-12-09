#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * Encodes a list of strings to a single string.
     *
     * @param strs List of strings to encode
     * @return Encoded string
     */
    string encode(vector<string>& strs) {
        string encoded = "";
        string delimiter = "#";

        for (string s : strs) {
            encoded = encoded + to_string(s.size()) + delimiter + s;
        }

        return encoded;
    }

    /**
     * Decodes a single string to a list of strings.
     *
     * @param s Encoded string
     * @return List of decoded strings
     */
    vector<string> decode(string s) {
        char delimiter = '#';
        vector<string> decoded;
        int pointer = 0;
        int end = 0;

        while (pointer < s.size()) {
            while (s[pointer] != delimiter) {
                pointer += 1;
            }
            int start = pointer + 1;

            int nextLength = stoi(s.substr(end, pointer - end));
            end = start + nextLength;

            decoded.push_back(s.substr(start, nextLength));
            pointer = end;
        }
        return decoded;
    }
};

void test_encode_decode_strings() {
    Solution solution;

    // Test case 1: Basic example
    vector<string> strs1 = {"Hello", "World"};
    string encoded1 = solution.encode(strs1);
    vector<string> decoded1 = solution.decode(encoded1);
    cout << "Test 1: [";
    for (size_t i = 0; i < strs1.size(); i++) {
        cout << "\"" << strs1[i] << "\"";
        if (i < strs1.size() - 1) cout << ", ";
    }
    cout << "] -> \"" << encoded1 << "\" -> [";
    for (size_t i = 0; i < decoded1.size(); i++) {
        cout << "\"" << decoded1[i] << "\"";
        if (i < decoded1.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    assert(decoded1 == strs1);

    // Test case 2: Empty string
    vector<string> strs2 = {""};
    string encoded2 = solution.encode(strs2);
    vector<string> decoded2 = solution.decode(encoded2);
    cout << "Test 2: [\"\"] -> \"" << encoded2 << "\" -> [\"" << decoded2[0] << "\"]" << endl;
    assert(decoded2 == strs2);

    // Test case 3: Empty list
    vector<string> strs3 = {};
    string encoded3 = solution.encode(strs3);
    vector<string> decoded3 = solution.decode(encoded3);
    cout << "Test 3: [] -> \"" << encoded3 << "\" -> []" << endl;
    assert(decoded3 == strs3);

    // Test case 4: Strings with special characters
    vector<string> strs4 = {"a#b", "c#d"};
    string encoded4 = solution.encode(strs4);
    vector<string> decoded4 = solution.decode(encoded4);
    cout << "Test 4: [\"a#b\", \"c#d\"] -> \"" << encoded4 << "\" -> [\"a#b\", \"c#d\"]" << endl;
    assert(decoded4 == strs4);

    // Test case 5: Multiple empty strings
    vector<string> strs5 = {"", "", ""};
    string encoded5 = solution.encode(strs5);
    vector<string> decoded5 = solution.decode(encoded5);
    cout << "Test 5: [\"\", \"\", \"\"] -> \"" << encoded5 << "\" -> [\"\", \"\", \"\"]" << endl;
    assert(decoded5 == strs5);

    // Test case 6: Strings with numbers
    vector<string> strs6 = {"123", "456", "789"};
    string encoded6 = solution.encode(strs6);
    vector<string> decoded6 = solution.decode(encoded6);
    cout << "Test 6: [\"123\", \"456\", \"789\"] -> \"" << encoded6
         << "\" -> [\"123\", \"456\", \"789\"]" << endl;
    assert(decoded6 == strs6);

    // Test case 7: Mixed length strings
    vector<string> strs7 = {"a", "ab", "abc", "abcd"};
    string encoded7 = solution.encode(strs7);
    vector<string> decoded7 = solution.decode(encoded7);
    cout << "Test 7: [\"a\", \"ab\", \"abc\", \"abcd\"] -> \"" << encoded7
         << "\" -> [\"a\", \"ab\", \"abc\", \"abcd\"]" << endl;
    assert(decoded7 == strs7);

    cout << "All test cases passed!" << endl;
}

int main() {
    test_encode_decode_strings();
    return 0;
}

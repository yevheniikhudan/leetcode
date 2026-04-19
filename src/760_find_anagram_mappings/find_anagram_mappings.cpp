#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mapping;

        for (int i = 0; i < nums2.size(); i++) {
            mapping[nums2[i]] = i;
        }

        vector<int> res;

        for (int i = 0; i < nums1.size(); i++) {
            res.push_back(mapping[nums1[i]]);
        }
        return res;
    }
};

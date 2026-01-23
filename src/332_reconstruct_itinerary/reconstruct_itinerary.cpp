#include <string>
#include <vector>

class Solution {
   public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, vector<string>> adjList;

        // Sort tickets by destination in descending order
        // So when we pop from back, we get the smallest lexicographically
        sort(tickets.begin(), tickets.end(), [](const vector<string>& a, const vector<string>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });

        for (auto& ticket : tickets) {
            adjList[ticket[0]].push_back(ticket[1]);
        }

        vector<string> res;
        dfs("JFK", adjList, res);
        reverse(res.begin(), res.end());
        return res;
    }

   private:
    void dfs(string src, map<string, vector<string>>& adjList, vector<string>& res) {
        while (adjList.count(src) && !adjList[src].empty()) {
            string dst = adjList[src].back();
            adjList[src].pop_back();
            dfs(dst, adjList, res);
        }
        res.push_back(src);
    }
};

// Test helper
void testFindItinerary() {
    Solution solution;

    // Test case 1: Example 1
    std::vector<std::vector<std::string>> tickets1 = {
        {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    std::vector<std::string> expected1 = {"JFK", "MUC", "LHR", "SFO", "SJC"};
    std::vector<std::string> actual1 = solution.findItinerary(tickets1);
    // Print logic would be added, but for skeleton, placeholder

    // Test case 2: Example 2
    std::vector<std::vector<std::string>> tickets2 = {
        {"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
    std::vector<std::string> expected2 = {"JFK", "ATL", "JFK", "SFO", "ATL", "SFO"};
    std::vector<std::string> actual2 = solution.findItinerary(tickets2);

    // Additional test cases similarly
}

int main() {
    testFindItinerary();
    return 0;
}

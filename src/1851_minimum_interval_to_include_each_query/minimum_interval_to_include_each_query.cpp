#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<int> minInterval(std::vector<std::vector<int>>& intervals,
                                 std::vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        std::vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());
        int i = 0;
        std::unordered_map<int, int> minIntervals;
        std::vector<int> res;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>>
            pq;
        for (int query : sortedQueries) {
            while (i < intervals.size() && intervals[i][0] <= query) {
                pq.push({intervalSize(intervals[i]), intervals[i][1]});
                i++;
            }

            while (pq.size() > 0 && pq.top().second < query) {
                pq.pop();
            }

            minIntervals[query] = pq.size() > 0 ? pq.top().first : -1;
        }

        for (int query : queries) {
            res.push_back(minIntervals[query]);
        }
        return res;
    }

   private:
    int intervalSize(std::vector<int>& interval) { return interval[1] - interval[0] + 1; }
};

std::vector<std::vector<int>> copy2D(const std::vector<std::vector<int>>& source) { return source; }

std::string vectorToString(const std::vector<int>& values) {
    std::string result = "[";

    for (size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            result += ", ";
        }
        result += std::to_string(values[i]);
    }

    result += "]";
    return result;
}

void runTests() {
    Solution sol;
    std::vector<std::vector<std::vector<int>>> intervalInputs = {
        {{1, 4}, {2, 4}, {3, 6}, {4, 4}},
        {{2, 3}, {2, 5}, {1, 8}, {20, 25}},
        {{1, 2}},
        {{5, 10}, {1, 3}},
        {{1, 1}, {2, 2}, {3, 3}},
        {{1, 10000000}},
    };
    std::vector<std::vector<int>> queryInputs = {
        {2, 3, 4, 5}, {2, 19, 5, 22}, {1, 2, 3}, {4, 5, 6}, {1, 2, 3}, {1, 5000000, 10000000},
    };
    std::vector<std::vector<int>> expecteds = {
        {3, 3, 1, 4}, {2, -1, 4, 6}, {2, 2, -1},
        {-1, 6, 6},   {1, 1, 1},     {10000000, 10000000, 10000000},
    };

    for (size_t i = 0; i < intervalInputs.size(); ++i) {
        auto intervals = copy2D(intervalInputs[i]);
        auto queries = queryInputs[i];
        std::vector<int> actual = sol.minInterval(intervals, queries);
        std::cout << vectorToString(actual) << " | " << vectorToString(expecteds[i]) << std::endl;
    }
}

int main() {
    runTests();
    return 0;
}
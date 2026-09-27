#include <ranges>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, size_t> counts {};
        for (const int& x: nums) {
            ++counts[x];
        }

        vector<vector<int>> tallies { nums.size() + 1, std::vector<int>(0) };
        for (const auto& [key, value]: counts) {
            tallies[value].push_back(key);
        }

        int n { 0 };
        vector<int> results {};
        for (const vector<int>& t: tallies | views::reverse) {
            for (const int& tally: t) {
                ++n;
                results.push_back(tally);
                if (n >= k) {
                    return results;
                }
            }
        }

        return results;
    }
};

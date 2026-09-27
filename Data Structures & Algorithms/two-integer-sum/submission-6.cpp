class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices {};
        for (size_t i { 0 }; i < nums.size(); ++i) {
            indices[nums[i]] = i;
        }
        
        for (size_t i { 0 }; i < nums.size(); ++i) {
            int need = target - nums[i];
            if (auto j_itr = indices.find(need); j_itr != indices.end() && i != j_itr->second) {
                int j = j_itr->second;
                if (i <= j) {
                    return { static_cast<int>(i), j };
                } else {
                    return { j, static_cast<int>(i) };
                }
            }
        }

        return {};
    }
};

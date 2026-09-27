class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) {
            return s.size();
        }

        unordered_set<int> window{};

        int left{ 0 };
        int maxLength{ 1 };

        window.insert(s[left]);
        for (int right{ 1 }; right < s.size();) {
            if (window.count(s[right])) {
                window.erase(s[left]);
                ++left;
            } else {
                window.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
                ++right;
            }
        }

        return maxLength;
    }
};

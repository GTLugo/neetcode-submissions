class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) {
            return s.size();
        }

        unordered_map<char, int> window{};

        int left{ 0 };
        int maxLength{ 1 };

        window.emplace(s[left], left);
        for (int right{ 1 }; right < s.size(); ++right) {
            if (window.count(s[right]) && window[s[right]] >= left) {
                left = window[s[right]] + 1;
            }
            window[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window{};

        int left{ 0 };
        int maxLength{ 0 };

        for (int right{ 0 }; right < s.size(); ++right) {
            if (window.count(s[right]) && window[s[right]] >= left) {
                left = window[s[right]] + 1;
            }
            window[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

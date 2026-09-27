class Solution {
   public:
    bool isValid(string s) {
        vector<char> parens{};

        for (const char& c : s) {
            if (isOpener(c)) {
                parens.push_back(c);
                continue;
            }

            if (parens.empty()) {
                return false;
            }

            if (isMatch(parens.back(), c)) {
                parens.pop_back();
            } else {
                return false;
            }
        }

        return parens.empty();
    }

    [[nodiscard]] bool isOpener(const char& c) const noexcept {
        switch (c) {
            case '(':
            case '[':
            case '{':
                return true;
            default:
                return false;
        }
    }

    [[nodiscard]] bool isMatch(const char& a, const char& b) const noexcept {
        switch (a) {
            case '(':
                if (b == ')') {
                    return true;
                }
                break;
            case '[':
                if (b == ']') {
                    return true;
                }
                break;
            case '{':
                if (b == '}') {
                    return true;
                }
                break;
            default:
                break;
        }
        return false;
    }
};

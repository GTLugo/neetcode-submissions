class Solution {
   public:
    bool isValid(string s) {
        stack<char> parens{};

        for (const char& c : s) {
            if (isOpener(c)) {
                parens.push(c);
                continue;
            }

            if (parens.empty()) {
                return false;
            }

            if (isMatch(parens.top(), c)) {
                parens.pop();
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

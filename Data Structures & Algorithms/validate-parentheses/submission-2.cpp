// I prefer this solution over pushing paired brackets onto the stack
// because this solution is O(n) in worst case, while the paired solution
// is O(2n) in worst case ---> (((((( is stored as ()()()()()()
class Solution {
   public:
    bool isValid(string s) {
        const unordered_map<char, char> lookup = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'},
        };
        vector<char> parens{};

        for (const char& c : s) {
            if (lookup.count(c) != 0) {
                parens.push_back(c);
                continue;
            }

            if (parens.empty()) {
                return false;
            }

            if (lookup.at(parens.back()) == c) {
                parens.pop_back();
            } else {
                return false;
            }
        }

        return parens.empty();
    }

    // [[nodiscard]] bool isOpener(const char& c) const noexcept {
    //     switch (c) {
    //         case '(':
    //         case '[':
    //         case '{':
    //             return true;
    //         default:
    //             return false;
    //     }
    // }

    // [[nodiscard]] bool isMatch(const char& a, const char& b) const noexcept {
    //     switch (a) {
    //         case '(':
    //             if (b == ')') {
    //                 return true;
    //             }
    //             break;
    //         case '[':
    //             if (b == ']') {
    //                 return true;
    //             }
    //             break;
    //         case '{':
    //             if (b == '}') {
    //                 return true;
    //             }
    //             break;
    //         default:
    //             break;
    //     }
    //     return false;
    // }
};

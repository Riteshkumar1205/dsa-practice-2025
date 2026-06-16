#include <string>
#include <algorithm>

class Solution {
public:
    string processStr(string s) {
        string result = "";
        
        for (char c : s) {
            if (c == '*') {
                // Remove the last character if it exists
                if (!result.empty()) {
                    result.pop_back();
                }
            } else if (c == '#') {
                // Duplicate the current result and append it to itself
                result += result;
            } else if (c == '%') {
                // Reverse the current result
                std::reverse(result.begin(), result.end());
            } else {
                // It's a lowercase English letter, so append it
                result.push_back(c);
            }
        }
        
        return result;
    }
};
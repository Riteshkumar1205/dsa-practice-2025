#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string smallestPalindrome(std::string s) {
        std::vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        std::string left_half = "";
        std::string middle = "";
        
        for (int i = 0; i < 26; ++i) {
            if (count[i] > 0) {
                left_half.append(count[i] / 2, (char)('a' + i));
                                if (count[i] % 2 != 0) {
                    middle = (char)('a' + i);
                }
            }
        }
        
        std::string right_half = left_half;
        std::reverse(right_half.begin(), right_half.end());
        
        return left_half + middle + right_half;
    }
};
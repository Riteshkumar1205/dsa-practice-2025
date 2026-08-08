class Solution {
public:
    std::vector<int> validSequence(std::string word1, std::string word2) {
        int n = word1.length();
        int m = word2.length();
        
        std::vector<int> suffix(n + 1, 0);
        int j = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }
            suffix[i] = m - 1 - j;
        }
        
        std::vector<int> result;
        int w2_idx = 0;
        bool used_wildcard = false;
        
        for (int i = 0; i < n && w2_idx < m; ++i) {
            if (word1[i] == word2[w2_idx]) {
                result.push_back(i);
                w2_idx++;
            } else if (!used_wildcard) {
                int remaining_needed = m - (w2_idx + 1);
                if (i + 1 < n && suffix[i + 1] >= remaining_needed) {
                    result.push_back(i);
                    used_wildcard = true;
                    w2_idx++;
                }
            }
        }
        
        if (w2_idx == m) {
            return result;
        }
        
        return {};
    }
};
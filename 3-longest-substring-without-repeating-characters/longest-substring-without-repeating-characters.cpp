class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1); 
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.size(); ++right) {
            unsigned char c = s[right];
            if (lastIndex[c] >= left) {
                left = lastIndex[c] + 1;
            }
            lastIndex[c] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

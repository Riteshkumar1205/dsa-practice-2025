class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.size(); ++right) {
            char currentChar = s[right];
            
            if (lastIndex.count(currentChar) && lastIndex[currentChar] >= left) {
                
                left = lastIndex[currentChar] + 1;
            }
            
            lastIndex[currentChar] = right;
            
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};

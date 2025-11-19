class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;
        
        for (int num : numSet) {
            // Only check for start of sequence
            if (!numSet.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;
                
                while (numSet.count(currentNum + 1)) {
                    ++currentNum;
                    ++currentStreak;
                }
                
                if (currentStreak > longestStreak) {
                    longestStreak = currentStreak;
                }
            }
        }
        
        return longestStreak;
    }
};

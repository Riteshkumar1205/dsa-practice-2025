class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor = 0;
        bool all_zeros = true;
        
        for (int num : nums) {
            total_xor ^= num;
            if (num != 0) {
                all_zeros = false;
            }
        }
        
        if (total_xor != 0) {
            return nums.size();
        }
        
        if (all_zeros) {
            return 0;
        }
        
        return nums.size() - 1;
    }
};
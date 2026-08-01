#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

class Solution {
private:
    int memo[20][20];
    
    int solve(const std::vector<int>& nums, int left, int right) {
        if (left > right) {
            return 0;
        }
        if (left == right) {
            return nums[left];
        }
        if (memo[left][right] != -1) {
            return memo[left][right];
        }
        
        int chooseLeft = nums[left] - solve(nums, left + 1, right);
        int chooseRight = nums[right] - solve(nums, left, right - 1);
        
        return memo[left][right] = std::max(chooseLeft, chooseRight);
    }

public:
    bool predictTheWinner(std::vector<int>& nums) {
        std::memset(memo, -1, sizeof(memo));
        return solve(nums, 0, nums.size() - 1) >= 0;
    }
};
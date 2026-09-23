#include <vector>
class Solution {
public:
    int minOperations(std::vector<int>& nums, int x) {
        long long total = 0;
        for (int num : nums) {
            total += num;
        }

        long long target = total - x;

        if (target < 0) return -1;
        if (target == 0) return nums.size();

        int max_len = -1;
        long long current_sum = 0;
        int left = 0;
        int n = nums.size();

        for (int right = 0; right < n; ++right) {
            current_sum += nums[right];

            while (left <= right && current_sum > target) {
                current_sum -= nums[left++];
            }

            if (current_sum == target) {
                max_len = std::max(max_len, right - left + 1);
            }
        }

        return max_len == -1 ? -1 : n - max_len;
    }
};
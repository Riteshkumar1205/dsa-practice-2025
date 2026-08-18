#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int largestInteger(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        // Case 1: k == 1
        if (k == 1) {
            std::unordered_map<int, int> count;
            for (int x : nums) {
                count[x]++;
            }
            int ans = -1;
            for (auto& [val, freq] : count) {
                if (freq == 1) {
                    ans = std::max(ans, val);
                }
            }
            return ans;
        }
        
        // Case 2: k == n
        if (k == n) {
            int ans = -1;
            for (int x : nums) {
                ans = std::max(ans, x);
            }
            return ans;
        }
        
        // Case 3: 1 < k < n
        bool first_unique = true;
        bool last_unique = true;
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[0]) {
                first_unique = false;
            }
            if (nums[n - 1 - i] == nums[n - 1]) {
                last_unique = false;
            }
        }
        
        int ans = -1;
        if (nums[0] == nums[n - 1]) {
            if (first_unique) {
                ans = nums[0];
            }
        } else {
            if (first_unique) {
                ans = std::max(ans, nums[0]);
            }
            if (last_unique) {
                ans = std::max(ans, nums[n - 1]);
            }
        }
        
        return ans;
    }
};
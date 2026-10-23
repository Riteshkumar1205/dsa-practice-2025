class Solution {
public:
    int sortPermutation(std::vector<int>& nums) {
        int k = -1;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                if (k == -1) {
                    k = nums[i];
                } else {
                    k &= nums[i];
                }
            }
        }

        return (k == -1) ? 0 : k;
    }
};
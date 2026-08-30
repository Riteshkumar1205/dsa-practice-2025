class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int min_idx = 0;
        int max_idx = 0;

        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[min_idx]) {
                min_idx = i;
            }
            if (nums[i] > nums[max_idx]) {
                max_idx = i;
            }
        }

        int l = std::min(min_idx, max_idx);
        int r = std::max(min_idx, max_idx);

        int front_only = r + 1;

        int back_only = n - l;

        int both_sides = (l + 1) + (n - r);

        return std::min({front_only, back_only, both_sides});
    }
};
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        // Count places where order decreases
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        // Valid only if at most one break exists
        return count <= 1;
    }
};
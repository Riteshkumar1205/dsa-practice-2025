class Solution {
public:
    bool sorted(vector<int>& a) {
        for (int i = 1; i < a.size(); i++) {
            if (a[i] < a[i - 1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;

        while (!sorted(nums)) {
            int minSum = INT_MAX, idx = 0;

            for (int i = 0; i + 1 < nums.size(); i++) {
                if (nums[i] + nums[i + 1] < minSum) {
                    minSum = nums[i] + nums[i + 1];
                    idx = i;
                }
            }

            nums[idx] += nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);
            ops++;
        }

        return ops;
    }
};

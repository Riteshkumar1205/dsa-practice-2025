class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int pos0 = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                pos0 = i;
                break;
            }
        }

        bool is_inc = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(pos0 + i) % n] != i) {
                is_inc = false;
                break;
            }
        }

        if (is_inc) {
            if (pos0 == 0) return 0;
            return min(pos0, (n - pos0) + 2);
        }

        bool is_dec = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(pos0 - i + n) % n] != i) {
                is_dec = false;
                break;
            }
        }

        if (is_dec) {
            int optA = ((pos0 + 1) % n) + 1;
            int optB = 1 + (n - 1 - pos0);
            
            return min(optA, optB);
        }

        return -1;
    }
};
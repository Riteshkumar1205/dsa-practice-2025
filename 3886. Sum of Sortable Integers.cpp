class Solution {
    bool canSortBlock(const vector<int>& nums, int start, int k, int& min_val, int& max_val) {
        if (k == 1) {
            min_val = nums[start];
            max_val = nums[start];
            return true;
        }

        int drops = 0;
        int drop_idx = -1;

        for (int i = 0; i < k; ++i) {
            int cur = nums[start + i];
            int nxt = nums[start + ((i + 1) % k)];
            if (cur > nxt) {
                drops++;
                drop_idx = i;
            }
        }

        if (drops > 1) {
            return false;
        }

        if (drops == 0) {
            min_val = nums[start];
            max_val = nums[start + k - 1];
        } else {
            min_val = nums[start + (drop_idx + 1) % k];
            max_val = nums[start + drop_idx];
        }

        return true;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> divisors;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i * i != n) {
                    divisors.push_back(n / i);
                }
            }
        }

        int total_sum = 0;

        for (int k : divisors) {
            bool valid = true;
            int prev_max = -1;

            for (int i = 0; i < n; i += k) {
                int cur_min = 0, cur_max = 0;
                if (!canSortBlock(nums, i, k, cur_min, cur_max)) {
                    valid = false;
                    break;
                }
                if (i > 0 && prev_max > cur_min) {
                    valid = false;
                    break;
                }
                prev_max = cur_max;
            }

            if (valid) {
                total_sum += k;
            }
        }

        return total_sum;
    }
};

class Solution {
private:
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> digit_sums(n);
        for (int i = 0; i < n; ++i) {
            digit_sums[i] = getDigitSum(nums[i]);
        }
        
        vector<int> target_indices(n);
        iota(target_indices.begin(), target_indices.end(), 0);
        
        sort(target_indices.begin(), target_indices.end(), [&](int i, int j) {
            if (digit_sums[i] != digit_sums[j]) {
                return digit_sums[i] < digit_sums[j];
            }
            return nums[i] < nums[j];
        });
        
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            p[target_indices[i]] = i;
        }
        
        vector<bool> visited(n, false);
        int swaps = 0;
        
        for (int i = 0; i < n; ++i) {
            if (visited[i] || p[i] == i) {
                continue;
            }
            
            int cycle_length = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = p[curr];
                cycle_length++;
            }
            
            if (cycle_length > 1) {
                swaps += cycle_length - 1;
            }
        }
        
        return swaps;
    }
};
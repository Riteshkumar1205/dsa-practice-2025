class Solution {
public:
    int minElement(vector<int>& nums) {
        int min_val = INT_MAX;
        
        for (int num : nums) {
            int digit_sum = 0;
            // Calculate the sum of digits mathematically
            while (num > 0) {
                digit_sum += num % 10;
                num /= 10;
            }
            // Track the minimum digit sum found so far
            min_val = min(min_val, digit_sum);
        }
        
        return min_val;
    }
};
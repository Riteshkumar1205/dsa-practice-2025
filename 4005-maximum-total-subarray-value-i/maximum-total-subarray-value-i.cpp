class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        // Find the maximum and minimum elements in the entire array
        int max_val = *max_element(nums.begin(), nums.end());
        int min_val = *min_element(nums.begin(), nums.end());
        
        // Calculate the maximum value of a single optimal subarray
        long long max_subarray_value = max_val - min_val;
        
        // Multiply by k (use long long to prevent integer overflow)
        return max_subarray_value * k;
    }
};
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // Since 1 <= nums[i] <= 100, we can use a fixed-size array
        int freq[101] = {0};

        // Count frequencies
        for (int num : nums) {
            freq[num]++;
        }

        // Find the max frequency
        int maxFreq = 0;
        for (int i = 1; i <= 100; ++i) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
            }
        }

        // Count total number of elements with max frequency
        int total = 0;
        for (int i = 1; i <= 100; ++i) {
            if (freq[i] == maxFreq) {
                total += freq[i];
            }
        }

        return total;
    }
};
   //Input
//  nums  [1,2,2,3,1,4]    -> output :- 4

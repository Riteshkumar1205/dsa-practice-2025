class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> count;

        int maxFreq = 0;
        for (int num : nums) {
            count[num]++;
            maxFreq = max(maxFreq, count[num]);
        }

        int ans = 0;
        for (auto &p : count) {
            if (p.second == maxFreq) {
                ans += maxFreq;
            }
        }

        return ans;
    }
};

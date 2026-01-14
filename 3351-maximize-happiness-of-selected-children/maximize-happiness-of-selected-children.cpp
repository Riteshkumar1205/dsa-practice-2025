class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long ans = 0;
        for (int i = 0; i < k; i++) {
            long long cur = happiness[i] - i;
            if (cur > 0) ans += cur;
        }
        return ans;
    }
};

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        const int MAXF = 1500;
        vector<int> freq(MAXF + 1, 0);
        for (const auto& item : items) {
            freq[item[0]]++;
        }

        vector<int> strictlyGreaterDivisible(MAXF + 1, 0);
        for (int d = 1; d <= MAXF; ++d) {
            int cnt = 0;
            for (int m = 2 * d; m <= MAXF; m += d) {
                cnt += freq[m];
            }
            strictlyGreaterDivisible[d] = cnt;
        }

        vector<int> dp(budget + 1, 0);

        for (const auto& item : items) {
            int f = item[0];
            int p = item[1];
            int firstBuyGain = freq[f] + strictlyGreaterDivisible[f];

            vector<int> nextDp = dp; 

            for (int b = p; b <= budget; ++b) {
                if (dp[b - p] + firstBuyGain > nextDp[b]) {
                    nextDp[b] = dp[b - p] + firstBuyGain;
                }
            }

            for (int b = p; b <= budget; ++b) {
                if (nextDp[b - p] > 0 || b >= 2 * p) {
                }
            }
            for (int b = 2 * p; b <= budget; ++b) {
                if (nextDp[b - p] > dp[b - p]) {
                    nextDp[b] = max(nextDp[b], nextDp[b - p] + 1);
                }
            }

            dp.swap(nextDp);
        }

        return *max_element(dp.begin(), dp.end());
    }
};
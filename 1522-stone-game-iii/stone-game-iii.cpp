#include <vector>
#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::string stoneGameIII(std::vector<int>& stoneValue) {
        int n = stoneValue.size();
        std::vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            int takeSum = 0;
            int maxDiff = INT_MIN;

            // Try taking 1, 2, or 3 stones
            for (int k = 0; k < 3 && i + k < n; ++k) {
                takeSum += stoneValue[i + k];
                maxDiff = std::max(maxDiff, takeSum - dp[i + k + 1]);
            }

            dp[i] = maxDiff;
        }

        if (dp[0] > 0) {
            return "Alice";
        } else if (dp[0] < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};
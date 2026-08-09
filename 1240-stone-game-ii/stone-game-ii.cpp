#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
private:
    int memo[101][101];
    int suffixSum[101];
    int n;

    int dp(int i, int M, const vector<int>& piles) {
        if (i >= n) return 0;
        
        if (i + 2 * M >= n) {
            return suffixSum[i];
        }

        if (memo[i][M] != -1) {
            return memo[i][M];
        }

        int maxStones = 0;
        for (int X = 1; X <= 2 * M; ++X) {
            int opponentStones = dp(i + X, max(M, X), piles);
            int currentStones = suffixSum[i] - opponentStones;
            maxStones = max(maxStones, currentStones);
        }

        return memo[i][M] = maxStones;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(memo, -1, sizeof(memo));
        
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        return dp(0, 1, piles);
    }
};
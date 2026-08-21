class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        
        auto countAmounts = [&](long long x) -> long long {
            long long count = 0;
            for (int mask = 1; mask < (1 << n); ++mask) {
                long long currentLcm = 1;
                int bits = 0;
                
                for (int i = 0; i < n; ++i) {
                    if ((mask >> i) & 1) {
                        bits++;
                        currentLcm = std::lcm(currentLcm, (long long)coins[i]);
                        if (currentLcm > x) break; 
                    }
                }
                
                if (bits % 2 == 1) {
                    count += x / currentLcm;
                } else {
                    count -= x / currentLcm;
                }
            }
            return count;
        };

        long long low = 1;
        long long min_coin = *min_element(coins.begin(), coins.end());
        long long high = min_coin * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countAmounts(mid) >= k) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
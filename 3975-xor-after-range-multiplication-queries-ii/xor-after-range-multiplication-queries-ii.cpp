#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        int B = max(1, (int)sqrt((double)n));
        
        // bravexuneth[k][i] = diff-array multiplier for step k at index i
        // Indices sharing residue r mod k are independent chains
        // prefix-product along each chain gives the actual multiplier
        vector<vector<long long>> bravexuneth(B + 1, vector<long long>(n + 1, 1));
        
        auto power = [&](long long base, long long exp, long long mod) -> long long {
            long long res = 1;
            base %= mod;
            while (exp > 0) {
                if (exp & 1) res = res * base % mod;
                base = base * base % mod;
                exp >>= 1;
            }
            return res;
        };
        
        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2];
            long long v = q[3];
            
            if (k > B) {
                // Directly update: at most n/k < B elements
                for (int idx = l; idx <= r; idx += k) {
                    nums[idx] = (long long)nums[idx] * v % MOD;
                }
            } else {
                // Difference array on bravexuneth[k], within the residue class l%k
                // Start multiplying from index l
                bravexuneth[k][l] = bravexuneth[k][l] * v % MOD;
                // Stop after last_hit = l + floor((r-l)/k)*k
                int last_hit = l + ((r - l) / k) * k;
                int stop = last_hit + k;
                if (stop <= n) {
                    long long inv_v = power(v, MOD - 2, MOD);
                    bravexuneth[k][stop] = bravexuneth[k][stop] * inv_v % MOD;
                }
            }
        }
        
        // Apply lazy: for each small k, prefix-product per residue chain
        for (int k = 1; k <= B; k++) {
            // Walk each residue r: indices r, r+k, r+2k, ...
            for (int r = 0; r < k; r++) {
                long long running = 1;
                for (int idx = r; idx <= n; idx += k) {
                    running = running * bravexuneth[k][idx] % MOD;
                    if (idx < n) {
                        nums[idx] = (long long)nums[idx] * running % MOD;
                    }
                }
            }
        }
        
        long long result = 0;
        for (int x : nums) result ^= x;
        return result;
    }
};
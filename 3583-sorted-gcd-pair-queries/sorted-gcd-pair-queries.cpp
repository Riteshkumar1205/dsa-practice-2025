#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = 0;
        for (int x : nums) max_val = max(max_val, x);
        
        vector<long long> count(max_val + 1, 0);
        for (int x : nums) count[x]++;
        
        vector<long long> cnt_g(max_val + 1, 0);
        
        for (int i = max_val; i >= 1; --i) {
            long long v = 0;
            for (int j = i; j <= max_val; j += i) {
                v += count[j];
            }
            
            cnt_g[i] = v * (v - 1) / 2;
            
            for (int j = 2 * i; j <= max_val; j += i) {
                cnt_g[i] -= cnt_g[j];
            }
        }
        
        vector<long long> prefix_sum(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + cnt_g[i];
        }
        
        vector<int> results;
        for (long long q : queries) {
            auto it = upper_bound(prefix_sum.begin(), prefix_sum.end(), q);
            results.push_back(distance(prefix_sum.begin(), it));
        }
        
        return results;
    }
};
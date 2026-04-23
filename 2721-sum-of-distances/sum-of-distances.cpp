class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;
        
        // Step 1: group indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<long long> ans(n, 0);
        
        // Step 2: process each group
        for (auto& [val, pos] : mp) {
            int k = pos.size();
            
            // prefix sum array
            vector<long long> prefix(k, 0);
            prefix[0] = pos[0];
            
            for (int i = 1; i < k; i++) {
                prefix[i] = prefix[i - 1] + pos[i];
            }
            
            for (int i = 0; i < k; i++) {
                long long left = 0, right = 0;
                
                // left side
                if (i > 0) {
                    left = (long long)i * pos[i] - prefix[i - 1];
                }
                

                if (i < k - 1) {
                    right = (prefix[k - 1] - prefix[i]) - (long long)(k - i - 1) * pos[i];
                }
                
                ans[pos[i]] = left + right;
            }
        }
        
        return ans;
    }
};
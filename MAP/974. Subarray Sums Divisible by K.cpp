class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> countMap(k, 0);
        countMap[0] = 1;  
        
        int sum = 0, res = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int mod = ((sum % k) + k) % k; 
            
            res += countMap[mod];
            countMap[mod]++;
        }
        
        return res;
    }
};

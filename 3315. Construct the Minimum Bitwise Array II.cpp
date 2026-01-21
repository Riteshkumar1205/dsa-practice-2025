class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int p : nums) {
            if ((p & 1) == 0) {
                ans.push_back(-1);
                continue;
            }

            int t = 0;
            int temp = p;
            while (temp & 1) {
                t++;
                temp >>= 1;
            }

            int x = p - (1 << (t - 1));
            ans.push_back(x);
        }

        return ans;
    }
};

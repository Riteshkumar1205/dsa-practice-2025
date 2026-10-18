class Solution {
    private:
    static constexpr int MOD = 1e9 + 7;
    vector<vector<int>> comb;

    void precomputeComb(int n){
        comb.assign(n + 1, vector<int>(n+1, 0));
        for(int i = 0; i <= n; i++){
            comb[i][0] = 1;
            for(int j = 1; j <= i;j++){
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }
    }
    long long dfs(const vector<int> & nums){
        int n = nums.size();
        if(n <= 2) return 1;

        int root = nums[0];
        vector<int> left, right;

        for(int i = 1; i < n;i++){
            if(nums[i] < root){
                left.push_back(nums[i]);
            }else {
                right.push_back(nums[i]);
            }
        }
        long long leftWays = dfs(left);
        long long rightWays = dfs(right);

        int leftSize = left.size();
        int rightSize = right.size();

        long long ways = comb[leftSize + rightSize][leftSize];
        ways = (ways * leftWays) % MOD;
        ways = (ways * rightWays) % MOD;

        return ways;
    }
    public:
    int numOfWays(vector<int>& nums){
        int n = nums.size();
        precomputeComb(n);
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};
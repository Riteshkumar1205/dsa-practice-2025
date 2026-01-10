class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        
        vector<int> dp(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            int prev = 0; 
            for (int j = 1; j <= m; j++) {
                int temp = dp[j]; 
                if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = prev + s1[i - 1];
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                prev = temp;
            }
        }

        int sum1 = 0, sum2 = 0;
        for (char c : s1) sum1 += c;
        for (char c : s2) sum2 += c;

        return sum1 + sum2 - 2 * dp[m];
    }
};

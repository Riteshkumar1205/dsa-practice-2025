class Solution {
public:
    int dist(int a, int b) {
        if (a == -1 || b == -1) return 0;
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        int n = word.size();
        
        // dp[j] = max saving when second finger is at letter j
        vector<int> dp(26, 0);
        
        int total = 0;
        
        for (int i = 1; i < n; i++) {
            int cur = word[i] - 'A';
            int prev = word[i - 1] - 'A';
            
            int d = dist(prev, cur);
            total += d;
            
            vector<int> new_dp = dp;
            
            for (int j = 0; j < 26; j++) {
                // Move second finger from j to cur
                new_dp[prev] = max(new_dp[prev], dp[j] + d - dist(j, cur));
            }
            
            dp = new_dp;
        }
        
        int maxSave = 0;
        for (int x : dp) maxSave = max(maxSave, x);
        
        return total - maxSave;
    }
};
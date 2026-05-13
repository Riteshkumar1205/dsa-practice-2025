class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            int mn = min(a, b);
            int mx = max(a, b);
            int sum = a + b;

            /*
                For each pair:

                sum range:
                [2, 2*limit]

                Cost:
                2 moves everywhere initially

                1 move for:
                [mn + 1, mx + limit]

                0 move at:
                sum
            */

            // Start with 2 moves for all sums
            diff[2] += 2;

            // 1 move range starts
            diff[mn + 1] -= 1;

            // Back to 2 moves after range
            diff[mx + limit + 1] += 1;

            // 0 move at exact sum
            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }

        int ans = INT_MAX;
        int curr = 0;

        for (int s = 2; s <= 2 * limit; s++) {
            curr += diff[s];
            ans = min(ans, curr);
        }

        return ans;
    }
};
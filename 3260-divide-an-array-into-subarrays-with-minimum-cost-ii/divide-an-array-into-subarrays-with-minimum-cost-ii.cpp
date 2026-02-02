class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long ans = LLONG_MAX;

        priority_queue<long long> small; // max heap
        priority_queue<long long, vector<long long>, greater<long long>> large;
        unordered_map<long long, int> delayed;

        long long sumSmall = 0;
        int smallSize = 0, largeSize = 0;

        auto pruneSmall = [&]() {
            while (!small.empty() && delayed[small.top()]) {
                delayed[small.top()]--;
                small.pop();
            }
        };

        auto pruneLarge = [&]() {
            while (!large.empty() && delayed[large.top()]) {
                delayed[large.top()]--;
                large.pop();
            }
        };

        auto rebalance = [&]() {
            while (smallSize > k - 1) {
                pruneSmall();
                large.push(small.top());
                sumSmall -= small.top();
                small.pop();
                smallSize--;
                largeSize++;
            }
            while (smallSize < k - 1 && largeSize > 0) {
                pruneLarge();
                small.push(large.top());
                sumSmall += large.top();
                large.pop();
                smallSize++;
                largeSize--;
            }
        };

        int L = 1;
        for (int R = 1; R < n; R++) {
            if (small.empty() || nums[R] <= small.top()) {
                small.push(nums[R]);
                sumSmall += nums[R];
                smallSize++;
            } else {
                large.push(nums[R]);
                largeSize++;
            }

            rebalance();

            while (R - L > dist) {
                long long x = nums[L++];
                delayed[x]++;
                if (!small.empty() && x <= small.top()) {
                    smallSize--;
                    sumSmall -= x;
                } else {
                    largeSize--;
                }
                pruneSmall();
                pruneLarge();
                rebalance();
            }

            if (smallSize == k - 1) {
                ans = min(ans, sumSmall);
            }
        }

        return nums[0] + ans;
    }
};

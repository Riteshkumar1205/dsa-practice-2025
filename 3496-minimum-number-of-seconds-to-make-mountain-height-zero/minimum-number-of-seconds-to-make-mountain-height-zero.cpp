class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 0, right = 1e18;
        long long ans = right;

        auto can = [&](long long T) {
            long long total = 0;

            for (long long t : workerTimes) {
                long long val = (2 * T) / t;

                long long x = (sqrt(1 + 4.0 * val) - 1) / 2;

                total += x;
                if (total >= mountainHeight) return true;
            }

            return total >= mountainHeight;
        };

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (can(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
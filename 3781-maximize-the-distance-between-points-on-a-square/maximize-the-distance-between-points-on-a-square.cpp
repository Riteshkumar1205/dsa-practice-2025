class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> arr;

        // Step 1: map to 1D
        for (auto &p : points) {
            long long x = p[0], y = p[1];

            if (y == 0) arr.push_back(x);
            else if (x == side) arr.push_back((long long)side + y);
            else if (y == side) arr.push_back(3LL * side - x);
            else arr.push_back(4LL * side - y);
        }

        sort(arr.begin(), arr.end());
        int n = arr.size();

        long long low = 0, high = side, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (!notValid(arr, n, k, mid, side)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }

private:
    bool notValid(vector<long long>& arr, int n, int k, long long d, int side) {
        for (int i = 0; i < n; i++) {
            int ptr = i, cnt = 1;

            while (cnt < k) {
                long long target = arr[ptr] + d;

                int j = lowerBound(arr, target);

                if (j == n) break;

                ptr = j;
                cnt++;

                // circular constraint
                if (d + arr[ptr] > arr[i] + 4LL * side) {
                    cnt = 0;
                    break;
                }
            }

            if (cnt == k) return false;
        }

        return true;
    }

    int lowerBound(vector<long long>& arr, long long target) {
        int l = 0, r = arr.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (arr[mid] < target) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
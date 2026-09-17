#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;
        
        vector<int> min_len(n, INF);
        
        int left = 0;
        int current_sum = 0;
        int ans = INF;

        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];

            while (current_sum > target && left <= right) {
                current_sum -= arr[left];
                left++;
            }

            if (current_sum == target) {
                int curr_length = right - left + 1;

                // If a non-overlapping valid subarray exists to the left
                if (left > 0 && min_len[left - 1] != INF) {
                    ans = min(ans, curr_length + min_len[left - 1]);
                }

                // Update min_len for current position
                if (right > 0) {
                    min_len[right] = min(min_len[right - 1], curr_length);
                } else {
                    min_len[right] = curr_length;
                }
            } else {
                if (right > 0) {
                    min_len[right] = min_len[right - 1];
                }
            }
        }

        return ans >= INF ? -1 : ans;
    }
};

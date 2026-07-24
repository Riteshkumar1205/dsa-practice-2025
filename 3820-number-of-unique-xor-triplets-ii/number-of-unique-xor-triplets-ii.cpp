#include <vector>
#include <unordered_set>

class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        int n = nums.size();
        std::unordered_set<int> unique_xors;
        std::unordered_set<int> pair_xors;
        pair_xors.reserve(n * (n + 1) / 2);

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                pair_xors.insert(nums[i] ^ nums[j]);
            }
        }

        for (int p_xor : pair_xors) {
            for (int k = 0; k < n; ++k) {
                unique_xors.insert(p_xor ^ nums[k]);
            }
        }

        return unique_xors.size();
    }
};
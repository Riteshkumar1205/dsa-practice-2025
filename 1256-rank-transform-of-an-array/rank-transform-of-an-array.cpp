#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        if (arr.empty()) return {};

        // 1. Create a sorted copy of the array
        std::vector<int> sortedArr = arr;
        std::sort(sortedArr.begin(), sortedArr.end());

        // 2. Remove duplicates to identify unique elements
        sortedArr.erase(std::unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());

        // 3. Map each element to its rank (1-based index)
        std::unordered_map<int, int> rankMap;
        for (int i = 0; i < sortedArr.size(); ++i) {
            rankMap[sortedArr[i]] = i + 1;
        }

        // 4. Transform the original array using the map
        std::vector<int> result;
        result.reserve(arr.size());
        for (int num : arr) {
            result.push_back(rankMap[num]);
        }

        return result;
    }
};
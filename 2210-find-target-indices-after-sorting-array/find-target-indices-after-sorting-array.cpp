class Solution {
public:
    std::vector<int> targetIndices(std::vector<int>& nums, int target) {
        int countLessThan = 0;
        int countEqual = 0;

        for (int num : nums) {
            if (num < target) {
                countLessThan++;
            } else if (num == target) {
                countEqual++;
            }
        }

        std::vector<int> result;
        result.reserve(countEqual);

        for (int i = 0; i < countEqual; ++i) {
            result.push_back(countLessThan + i);
        }

        return result;
    }
};
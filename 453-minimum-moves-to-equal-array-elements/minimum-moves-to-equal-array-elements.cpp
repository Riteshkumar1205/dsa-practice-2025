class Solution {
public:
    int minMoves(std::vector<int>& nums) {
        int minVal = *std::min_element(nums.begin(), nums.end());
        int moves = 0;
        
        for (int x : nums) {
            moves += (x - minVal);
        }
        
        return moves;
    }
};
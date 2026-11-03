class Solution {
public:
    int minMoves(std::vector<int>& nums) {
        int max_val = *std::max_element(nums.begin(), nums.end());
        int moves = 0;
        
        for (int x : nums) {
            moves += (max_val - x);
        }
        
        return moves;
    }
};
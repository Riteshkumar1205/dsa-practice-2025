class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        
        // A sequential number starts with a digit from 1 to 9.
        // The length can range from 2 to 9 digits.
        for (int i = 1; i <= 9; ++i) {
            int num = i;
            for (int j = i + 1; j <= 9; ++j) {
                num = num * 10 + j;
                
                if (num > high) break;
                if (num >= low) {
                    result.push_back(num);
                }
            }
        }
        
        // The numbers are generated in increasing order of length,
        // and for the same length, in increasing order of the starting digit.
        // Sorting ensures the requirement is met.
        sort(result.begin(), result.end());
        
        return result;
    }
};
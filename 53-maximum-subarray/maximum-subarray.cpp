class Solution {
public:
    int maxSubArray(vector<int>& n) {
        int i = 0;
        int j = 0;
        int maxSum = INT_MIN;
        int sum = 0;

        while (j < n.size()) {
            sum += n[j];
            maxSum = max(maxSum, sum);   

            if (sum < 0) {              
                sum = 0;
                i = j + 1;
            }
            j++;
        }
        return maxSum;
    }
};

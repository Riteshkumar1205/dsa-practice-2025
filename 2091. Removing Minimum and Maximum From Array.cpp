#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        
        // Find indices of minimum and maximum elements
        int minIndex = 0, maxIndex = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIndex]) minIndex = i;
            if (nums[i] > nums[maxIndex]) maxIndex = i;
        }
        
        // Ensure minIndex comes before maxIndex (for easier calculation)
        if (minIndex > maxIndex) swap(minIndex, maxIndex);
        
        // Case 1: Remove both from front
        int front = maxIndex + 1;
        
        // Case 2: Remove both from back
        int back = n - minIndex;
        
        // Case 3: Remove one from front, one from back
        int both = (minIndex + 1) + (n - maxIndex);
        
        // Return the minimum of all three options
        return min({front, back, both});
    }
};

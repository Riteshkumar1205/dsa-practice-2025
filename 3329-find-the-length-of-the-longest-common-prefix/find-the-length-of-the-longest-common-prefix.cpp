class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;

        // Store all prefixes of numbers in arr1
        for (int num : arr1) {
            while (num > 0) {
                prefixes.insert(num);
                num /= 10;
            }
        }

        int ans = 0;

        // Check prefixes of numbers in arr2
        for (int num : arr2) {
            while (num > 0) {
                if (prefixes.count(num)) {
                    ans = max(ans, (int)to_string(num).size());
                }
                num /= 10;
            }
        }

        return ans;
    }
};
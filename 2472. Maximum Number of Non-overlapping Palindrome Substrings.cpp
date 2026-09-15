class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int ans = 0;
        int last_end = 0; // Next available starting index

        auto isPalindrome = [&](int l, int r) {
            while (l < r) {
                if (s[l] != s[r]) return false;
                l++;
                r--;
            }
            return true;
        };

        for (int r = 0; r < n; ++r) {
            // Check for a valid palindrome of length k ending at r
            if (r - k + 1 >= last_end && isPalindrome(r - k + 1, r)) {
                ans++;
                last_end = r + 1;
            }
            // Check for a valid palindrome of length k + 1 ending at r
            else if (r - k >= last_end && isPalindrome(r - k, r)) {
                ans++;
                last_end = r + 1;
            }
        }

        return ans;
    }
};

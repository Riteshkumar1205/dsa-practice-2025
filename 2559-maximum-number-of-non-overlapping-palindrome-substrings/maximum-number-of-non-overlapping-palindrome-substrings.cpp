class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int ans = 0;
        int last_end = 0; 
        auto isPalindrome = [&](int l, int r) {
            while (l < r) {
                if (s[l] != s[r]) return false;
                l++;
                r--;
            }
            return true;
        };

        for (int r = 0; r < n; ++r) {
          
            if (r - k + 1 >= last_end && isPalindrome(r - k + 1, r)) {
                ans++;
                last_end = r + 1;
            }
            
            else if (r - k >= last_end && isPalindrome(r - k, r)) {
                ans++;
                last_end = r + 1;
            }
        }

        return ans;
    }
};
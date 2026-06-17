#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        // Pack lengths tracking for each step
        vector<long long> lengths(n);
        long long current_len = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                current_len++;
            } else if (s[i] == '*') {
                if (current_len > 0) {
                    current_len--;
                }
            } else if (s[i] == '#') {
                current_len *= 2;
            } else if (s[i] == '%') {
                // Reversal does not change the length
                current_len = current_len; 
            }
            lengths[i] = current_len;
        }

        // If k is out of bounds of the final generated string
        if (k < 0 || k >= current_len) {
            return '.';
        }

        // Trace backward to pinpoint the index
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                if (k == lengths[i] - 1) {
                    return s[i];
                }
            } else if (s[i] == '*') {
                // Backspace is naturally handled by tracing back to the previous state,
                // nothing extra needs to be modified for index k itself here.
                continue;
            } else if (s[i] == '#') {
                long long prev_len = lengths[i] / 2;
                if (k >= prev_len) {
                    k %= prev_len;
                }
            } else if (s[i] == '%') {
                long long prev_len = lengths[i];
                k = prev_len - 1 - k;
            }
        }

        return '.';
    }
};
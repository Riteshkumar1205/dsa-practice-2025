class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total_sum = 0;
        
        for (int i = num1; i <= num2; ++i) {
            string s = to_string(i);
            int n = s.length();
            
            // Numbers with fewer than 3 digits have a waviness of 0
            if (n < 3) continue;
            
            // Check internal digits for peaks and valleys
            for (int j = 1; j < n - 1; ++j) {
                if (s[j] > s[j - 1] && s[j] > s[j + 1]) {
                    total_sum++; // Peak found
                } else if (s[j] < s[j - 1] && s[j] < s[j + 1]) {
                    total_sum++; // Valley found
                }
            }
        }
        
        return total_sum;
    }
};
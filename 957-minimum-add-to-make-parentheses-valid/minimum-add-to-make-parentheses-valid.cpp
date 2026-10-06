class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_count = 0;
        int unmatched_close = 0;

        for (char c : s) {
            if (c == '(') {
                open_count++;
            } else {
                if (open_count > 0) {
                    open_count--;
                } else {
                    unmatched_close++; 
                }
            }
        }

        return open_count + unmatched_close;
    }
};
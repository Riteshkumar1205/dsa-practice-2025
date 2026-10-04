class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0;
        int cmax = 0;

        for (char c : s) {
            if (c == '(') {
                cmin++;
                cmax++;
            } else if (c == ')') {
                cmin--;
                cmax--;
            } else if (c == '*') {
                cmin--; 
                cmax++; 
            }

            if (cmax < 0) {
                return false;
            }

            cmin = max(cmin, 0);
        }

        return cmin == 0;
    }
};
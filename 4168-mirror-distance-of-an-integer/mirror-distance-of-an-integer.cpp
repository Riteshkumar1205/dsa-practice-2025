class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }

    int mirrorDistance(int n) {
        int rev = reverseNum(n);
        return abs(n - rev);
    }
};
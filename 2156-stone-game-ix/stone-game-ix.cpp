class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};
        for (int s : stones) {
            cnt[s % 3]++;
        }

        if (cnt[1] == 0 && cnt[2] == 0) return false;

        auto check = [&](int c1, int c2) {
            c1--;
            bool aliceTurn = false; 
            while (true) {
                if (aliceTurn) {
                    if (c1 > 0) {
                        c1--;
                    } else {
                        return false; 
                    }
                } else {
                    if (c2 > 0) {
                        c2--;
                    } else {
                        return true; 
                    }
                }
                aliceTurn = !aliceTurn;
            }
        };

        if (cnt[0] % 2 == 0) {
            return (cnt[1] > 0 && cnt[2] > 0);
        } else {
            return abs(cnt[1] - cnt[2]) > 2;
        }
    }
};
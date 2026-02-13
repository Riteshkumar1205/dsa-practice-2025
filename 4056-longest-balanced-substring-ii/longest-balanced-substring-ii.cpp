#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        vector<char> cs(s.begin(), s.end());
        
        int x = calc1(cs); // single-character
        int y = max({calc2(cs, 'a', 'b'), calc2(cs, 'b', 'c'), calc2(cs, 'a', 'c')}); // two-character
        int z = calc3(cs); // three-character
        
        return max({x, y, z});
    }

private:
    // Single-character substrings
    int calc1(vector<char>& s) {
        int res = 0;
        int n = s.size();
        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && s[j] == s[i]) j++;
            res = max(res, j - i);
            i = j;
        }
        return res;
    }

    // Exactly two characters
    int calc2(vector<char>& s, char a, char b) {
        int res = 0;
        int n = s.size();
        int i = 0;
        while (i < n) {
            // Skip irrelevant characters
            while (i < n && s[i] != a && s[i] != b) i++;
            
            unordered_map<int,int> pos;
            pos[0] = i - 1;
            int d = 0;
            
            while (i < n && (s[i] == a || s[i] == b)) {
                d += (s[i] == a ? 1 : -1);
                if (pos.count(d)) {
                    res = max(res, i - pos[d]);
                } else {
                    pos[d] = i;
                }
                i++;
            }
        }
        return res;
    }

    // All three characters
    int calc3(vector<char>& s) {
        unordered_map<long long,int> pos;
        pos[f(0,0)] = -1;
        
        int cnt[3] = {0};
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i]-'a']++;
            int x = cnt[0] - cnt[1];
            int y = cnt[1] - cnt[2];
            long long k = f(x, y);
            if (pos.count(k)) {
                res = max(res, i - pos[k]);
            } else {
                pos[k] = i;
            }
        }
        return res;
    }

    // Encode pair (x,y) into a single long long key
    long long f(int x, int y) {
        return ((long long)(x + 100000) << 20) | (y + 100000);
    }
};

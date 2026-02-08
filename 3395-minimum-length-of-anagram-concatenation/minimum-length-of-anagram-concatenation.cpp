class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();

        // Get all divisors of n (possible lengths of t)
        vector<int> divisors;
        for (int l = 1; l <= n; l++) {
            if (n % l == 0) divisors.push_back(l);
        }

        // Try each candidate length
        for (int l : divisors) {
            vector<int> freqFirst(26, 0);
            for (int i = 0; i < l; i++) freqFirst[s[i] - 'a']++;

            bool ok = true;
            for (int start = l; start < n; start += l) {
                vector<int> freqCurr(26, 0);
                for (int i = start; i < start + l; i++) freqCurr[s[i] - 'a']++;
                if (freqCurr != freqFirst) {
                    ok = false;
                    break;
                }
            }

            if (ok) return l;
        }

        return n; 
    }
};

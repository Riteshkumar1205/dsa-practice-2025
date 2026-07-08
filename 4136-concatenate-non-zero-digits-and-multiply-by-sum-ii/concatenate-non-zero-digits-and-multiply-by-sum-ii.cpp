#include <vector>
#include <string>

using namespace std;

class Solution {
    long long MOD = 1e9 + 7;

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        
        // 1. Precompute digit sum prefix array
        vector<long long> digitSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            digitSum[i + 1] = digitSum[i] + (s[i] - '0');
        }

        // 2. Precompute powers of 10 mod MOD
        vector<long long> pow10(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; ++i) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        // 3. Precompute non-zero digits and their concatenated prefix values
        struct Element { int index; int val; };
        vector<Element> nz;
        vector<long long> prefixConcatenated(1, 0);
        
        for (int i = 0; i < n; ++i) {
            if (s[i] != '0') {
                nz.push_back({i, s[i] - '0'});
                long long newVal = (prefixConcatenated.back() * 10 + (s[i] - '0')) % MOD;
                prefixConcatenated.push_back(newVal);
            }
        }

        // 4. Process queries
        vector<int> answers;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            
            // Find range of non-zero digits within [l, r]
            auto it1 = lower_bound(nz.begin(), nz.end(), l, [](const Element& e, int val) {
                return e.index < val;
            });
            auto it2 = upper_bound(nz.begin(), nz.end(), r, [](int val, const Element& e) {
                return val < e.index;
            });

            if (it1 == it2) {
                answers.push_back(0);
                continue;
            }

            int start = distance(nz.begin(), it1);
            int end = distance(nz.begin(), it2);
            int count = end - start;

            // Get concatenated number x: (prefix[end] - prefix[start] * 10^count) % MOD
            long long x = (prefixConcatenated[end] - (prefixConcatenated[start] * pow10[count]) % MOD + MOD) % MOD;
            
            // Get sum of digits
            long long sVal = (digitSum[r + 1] - digitSum[l] + MOD) % MOD;
            
            answers.push_back((x * sVal) % MOD);
        }
        return answers;
    }
};
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        unordered_map<int,int> m;

        for (int ele : digits) {
            m[ele]++;
        }

        for (int i = 100; i <= 999; i += 2) {
            int x = i;
            int a = x % 10;
            x /= 10;
            int b = x % 10;
            x /= 10;
            int c = x;

            if (m[a] > 0) {
                m[a]--;
                if (m[b] > 0) {
                    m[b]--;
                    if (m[c] > 0) {
                        ans.push_back(i);
                    }
                    m[b]++;
                }
                m[a]++;
            }
        }
        return ans;
    }
};

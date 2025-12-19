class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) freq[d]++;

        vector<int> ans;

        for (int num = 100; num <= 999; num += 2) {
            int x = num;
            int a = x % 10;        
            x /= 10;
            int b = x % 10;        
            int c = x / 10;        

            vector<int> need(10, 0);
            need[a]++;
            need[b]++;
            need[c]++;

            bool ok = true;
            for (int d = 0; d <= 9; d++) {
                if (need[d] > freq[d]) {
                    ok = false;
                    break;
                }
            }

            if (ok) ans.push_back(num);
        }

        return ans;
    }
};

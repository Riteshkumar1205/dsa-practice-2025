class Solution {
public:

    bool isPrime(int x) {
        if (x < 2) return false;

        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }

        return true;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) return 0;

        // prime -> indices divisible by prime
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {

            int x = nums[i];

            // factorization
            for (int p = 2; p * p <= x; p++) {

                if (x % p == 0) {

                    mp[p].push_back(i);

                    while (x % p == 0)
                        x /= p;
                }
            }

            if (x > 1)
                mp[x].push_back(i);
        }

        vector<int> vis(n, 0);

        queue<pair<int,int>> q;

        q.push({0, 0});
        vis[0] = 1;

        unordered_set<int> usedPrime;

        while (!q.empty()) {

            auto [idx, steps] = q.front();
            q.pop();

            if (idx == n - 1)
                return steps;

            // left
            if (idx - 1 >= 0 && !vis[idx - 1]) {
                vis[idx - 1] = 1;
                q.push({idx - 1, steps + 1});
            }

            // right
            if (idx + 1 < n && !vis[idx + 1]) {
                vis[idx + 1] = 1;
                q.push({idx + 1, steps + 1});
            }

            // teleportation
            int val = nums[idx];

            if (isPrime(val) && !usedPrime.count(val)) {

                usedPrime.insert(val);

                for (int nextIdx : mp[val]) {

                    if (!vis[nextIdx]) {

                        vis[nextIdx] = 1;

                        q.push({nextIdx, steps + 1});
                    }
                }
            }
        }

        return -1;
    }
};
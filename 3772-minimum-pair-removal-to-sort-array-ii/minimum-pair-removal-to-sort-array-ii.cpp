class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<long long> a(nums.begin(), nums.end());
        
        vector<int> left(n), right(n);
        vector<bool> alive(n, true);
        for (int i = 0; i < n; i++) {
            left[i] = i - 1;
            right[i] = i + 1;
        }
        right[n - 1] = -1; 

        int bad = 0;
        for (int i = 1; i < n; i++)
            if (a[i] < a[i - 1]) bad++;

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        for (int i = 0; i + 1 < n; i++)
            pq.push({a[i] + a[i + 1], i});

        int ops = 0;

        while (bad > 0) {
            auto [sum, i] = pq.top();
            pq.pop();

            int j = right[i]; 
            if (!alive[i] || j == -1 || !alive[j] || a[i] + a[j] != sum) continue;

            int li = left[i];      
            int rj = right[j];  

            // Remove bad pairs that are disappearing
            if (li != -1 && a[i] < a[li]) bad--;
            if (rj != -1 && a[rj] < a[j]) bad--;
            if (a[j] < a[i]) bad--;

            // Merge the pair i + j
            a[i] += a[j];
            alive[j] = false;

            // Update linked list pointers
            right[i] = rj;
            if (rj != -1) left[rj] = i;

            // Add new bad pairs after merge
            if (li != -1 && a[i] < a[li]) bad++;
            if (rj != -1 && a[rj] < a[i]) bad++;

            // Push updated neighbor pairs to heap
            if (li != -1) pq.push({a[li] + a[i], li});
            if (rj != -1) pq.push({a[i] + a[rj], i});

            ops++;
        }

        return ops;
    }
};

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> count(k, 0);

        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;

        int n = arrival.size();
        for (int i = 0; i < n; ++i) {
            long long time = arrival[i];

            while (!busy.empty() && busy.top().first <= time) {
                available.insert(busy.top().second);
                busy.pop();
            }

            if (available.empty()) {
                continue;
            }

            int target = i % k;
            auto it = available.lower_bound(target);

            if (it == available.end()) {
                it = available.begin();
            }

            int server_id = *it;
            available.erase(it);

            busy.push({time + load[i], server_id});
            count[server_id]++;
        }

        int max_requests = *max_element(count.begin(), count.end());

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (count[i] == max_requests) {
                result.push_back(i);
            }
        }

        return result;
    }
};
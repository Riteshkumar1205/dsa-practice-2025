class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeServers;
        
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> busyServers;
        
        for (int i = 0; i < n; ++i) {
            freeServers.push({servers[i], i});
        }
        
        vector<int> ans(m);
        long long curTime = 0;
        
        for (int i = 0; i < m; ++i) {
            curTime = max(curTime, (long long)i);
            
            if (freeServers.empty()) {
                curTime = max(curTime, get<0>(busyServers.top()));
            }
            
            while (!busyServers.empty() && get<0>(busyServers.top()) <= curTime) {
                auto [time, weight, idx] = busyServers.top();
                busyServers.pop();
                freeServers.push({weight, idx});
            }
            
            auto [weight, idx] = freeServers.top();
            freeServers.pop();
            
            ans[i] = idx;
            busyServers.push({curTime + tasks[i], weight, idx});
        }
        
        return ans;
    }
};
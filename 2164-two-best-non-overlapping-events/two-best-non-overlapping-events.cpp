class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        
        sort(events.begin(), events.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        int maxValueSoFar = 0;
        int answer = 0;

        for (auto &e : events) {
            int start = e[0];
            int end = e[1];
            int value = e[2];

            while (!pq.empty() && pq.top().first < start) {
                maxValueSoFar = max(maxValueSoFar, pq.top().second);
                pq.pop();
            }

            answer = max(answer, maxValueSoFar + value);

            pq.push({end, value});
        }

        return answer;
    }
};

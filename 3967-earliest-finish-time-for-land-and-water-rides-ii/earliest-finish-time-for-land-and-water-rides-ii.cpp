class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        // --- Case 1: Land Ride First, then Water Ride ---
        int best_land_finish = INT_MAX;
        for (int i = 0; i < n; ++i) {
            best_land_finish = min(best_land_finish, landStartTime[i] + landDuration[i]);
        }
        
        int case1_total_finish = INT_MAX;
        for (int j = 0; j < m; ++j) {
            int current_finish = max(best_land_finish, waterStartTime[j]) + waterDuration[j];
            case1_total_finish = min(case1_total_finish, current_finish);
        }
        
        // --- Case 2: Water Ride First, then Land Ride ---
        int best_water_finish = INT_MAX;
        for (int j = 0; j < m; ++j) {
            best_water_finish = min(best_water_finish, waterStartTime[j] + waterDuration[j]);
        }
        
        int case2_total_finish = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int current_finish = max(best_water_finish, landStartTime[i]) + landDuration[i];
            case2_total_finish = min(case2_total_finish, current_finish);
        }
        
        return min(case1_total_finish, case2_total_finish);
    }
};
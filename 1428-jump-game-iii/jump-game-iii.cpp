class Solution {
public:
    bool dfs(vector<int>& arr, int i, vector<bool>& vis) {
        int n = arr.size();

        // Out of bounds or already visited
        if (i < 0 || i >= n || vis[i])
            return false;

        // Found zero
        if (arr[i] == 0)
            return true;

        vis[i] = true;

        // Try both directions
        return dfs(arr, i + arr[i], vis) ||
               dfs(arr, i - arr[i], vis);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(), false);
        return dfs(arr, start, vis);
    }
};
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;
        double totalArea = 0.0;

        for (auto& s : squares) {
            double y = s[1], l = s[2];
            low = min(low, y);
            high = max(high, y + l);
            totalArea += l * l;
        }

        double target = totalArea / 2.0;

        for (int it = 0; it < 60; it++) { 
            double mid = (low + high) / 2.0;
            double areaBelow = 0.0;

            for (auto& s : squares) {
                double y = s[1], l = s[2];
                double height = max(0.0, min(l, mid - y));
                areaBelow += height * l;
            }

            if (areaBelow < target)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1;
        long long c2 = cost2;
        long long cb = costBoth;
        long long n1 = need1;
        long long n2 = need2;

        long long common = std::min(n1, n2);
        long long totalCost = common * std::min(cb, c1 + c2);

        if (n1 > n2) {
            totalCost += (n1 - n2) * std::min(c1, cb);
        } else if (n2 > n1) {
            totalCost += (n2 - n1) * std::min(c2, cb);
        }

        return totalCost;
    }
};
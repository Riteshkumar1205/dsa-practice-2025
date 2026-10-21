class Solution {
public:
    int minOperations(std::string s) {
        int n = s.size();
        
        if (std::is_sorted(s.begin(), s.end())) {
            return 0;
        }
        
        if (n <= 2) {
            return -1;
        }
        
        char mn = *std::min_element(s.begin(), s.end());
        char mx = *std::max_element(s.begin(), s.end());
        
        if (s.front() == mn || s.back() == mx) {
            return 1;
        }
        
        int count_mn = std::count(s.begin(), s.end(), mn);
        int count_mx = std::count(s.begin(), s.end(), mx);
        if (s.front() == mx && s.back() == mn && count_mx == 1 && count_mn == 1) {
            return 3;
        }
        
        return 2;
    }
};
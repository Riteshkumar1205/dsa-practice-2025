class Solution {
public:
    string ans = "";
    
    void dfs(int n, int &k, string &curr) {
        if (curr.size() == n) {
            k--;
            if (k == 0) ans = curr;
            return;
        }
        
        for (char ch : {'a','b','c'}) {
            if (!curr.empty() && curr.back() == ch) continue;
            
            curr.push_back(ch);
            dfs(n, k, curr);
            curr.pop_back();
            
            if (!ans.empty()) return;
        }
    }
    
    string getHappyString(int n, int k) {
        string curr = "";
        dfs(n, k, curr);
        return ans;
    }
};
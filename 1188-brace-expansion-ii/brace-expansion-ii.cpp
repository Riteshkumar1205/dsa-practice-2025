class Solution {
    int i = 0;
    std::unordered_set<std::string> setUnion(const std::unordered_set<std::string>& a,
              const std::unordered_set<std::string>& b) {
        std::unordered_set<std::string> res = a;
        res.insert(b.begin(), b.end());
        return res;
    }

    std::unordered_set<std::string> setProduct(const std::unordered_set<std::string>& a,
                 const std::unordered_set<std::string>& b) {
        std::unordered_set<std::string> res;
        for (const std::string& s1 : a) {
            for (const std::string& s2 : b) {
                res.insert(s1 + s2);
            }
        }
        return res;
    }

    std::unordered_set<std::string> parseExpr(const std::string& s) {
        std::unordered_set<std::string> res = parseTerm(s);
        while (i < s.size() && s[i] == ',') {
            i++; 
            std::unordered_set<std::string> next_term = parseTerm(s);
            res = setUnion(res, next_term);
        }
        return res;
    }

    std::unordered_set<std::string> parseTerm(const std::string& s) {
        std::unordered_set<std::string> res = {""}; 
        while (i < s.size() && (s[i] == '{' || std::islower(s[i]))) {
            std::unordered_set<std::string> factor = parseFactor(s);
            res = setProduct(res, factor);
        }
        return res;
    }

    std::unordered_set<std::string> parseFactor(const std::string& s) {
        if (s[i] == '{') {
            i++; 
            std::unordered_set<std::string> res = parseExpr(s);
            i++; 
            return res;
        } else {
            std::string word(1, s[i]);
            i++; 
            return {word};
        }
    }

public:
    std::vector<std::string> braceExpansionII(std::string expression) {
        i = 0;
        std::unordered_set<std::string> wordSet = parseExpr(expression);
        
        std::vector<std::string> result(wordSet.begin(), wordSet.end());
        std::sort(result.begin(), result.end());
        return result;
    }
};
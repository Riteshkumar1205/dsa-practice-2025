class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        int balance = 0, start = 0;

        for (int i = 0; i < s.size(); ++i) {
            balance += (s[i] == '1') ? 1 : -1;

            if (balance == 0) {
                // Recursively process inner substring
                parts.push_back("1" + 
                    makeLargestSpecial(s.substr(start + 1, i - start - 1)) 
                    + "0");
                start = i + 1;
            }
        }

        // Sort descending for lexicographically largest
        sort(parts.begin(), parts.end(), greater<string>());

        // Efficient concatenation
        string result;
        result.reserve(s.size());
        for (const string& part : parts) {
            result += part;
        }

        return result;
    }
};
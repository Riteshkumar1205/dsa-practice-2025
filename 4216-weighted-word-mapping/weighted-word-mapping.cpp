class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        
        for (const string& word : words) {
            long long word_weight = 0;
                        for (char c : word) {
                word_weight += weights[c - 'a'];
            }
            
            int remainder = word_weight % 26;
            
            char mapped_char = 'z' - remainder;
            
            result += mapped_char;
        }
        
        return result;
    }
};
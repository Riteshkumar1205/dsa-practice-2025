class Solution {
public:
    string freqAlphabets(string s) {
        string res;
        int i = s.size() - 1;
        
        while(i >= 0) {
            if(s[i] == '#') {
                int num = (s[i-2]-'0')*10 + (s[i-1]-'0');
                res += (char)('a' + num - 1);
                i -= 3; 
            } else {
                   res += (char)('a' + (s[i]-'0') - 1);
                i--;
            }
        }
        
        reverse(res.begin(), res.end()); 
        return res;
    }
};

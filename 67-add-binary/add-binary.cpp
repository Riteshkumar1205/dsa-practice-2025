#include <stack>
class Solution {
public:
    string addBinary(string a, string b) {
        stack<int> s1, s2;
        
        // Push digits into stacks
        for(char c : a) s1.push(c - '0');
        for(char c : b) s2.push(c - '0');
        
        int carry = 0;
        string result = "";
        
        // Process stacks
        while(!s1.empty() || !s2.empty() || carry) {
            int sum = carry;
            
            if(!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            
            if(!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            
            result = char((sum % 2) + '0') + result;
            carry = sum / 2;
        }
        
        return result;
    }
};

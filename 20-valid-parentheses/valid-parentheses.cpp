class Solution {
public:
    bool isValid(string s) {
        stack<char> S;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            // Opening bracket
            if (ch == '(' || ch == '{' || ch == '[') {
                S.push(ch);
            } 
            else {  // Closing bracket
                if (S.empty()) 
                    return false;

                char top = S.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {
                    S.pop();
                } 
                else {
                    return false;
                }
            }
        }

        return S.empty();
    }
};

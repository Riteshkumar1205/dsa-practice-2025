class Solution {
public:
    int calculate(string s) {
        long currentNum = 0;
        char op = '+'; 
        stack<long> st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                currentNum = currentNum * 10 + (c - '0');
            }
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                if (op == '+') {
                    st.push(currentNum);
                } else if (op == '-') {
                    st.push(-currentNum);
                } else if (op == '*') {
                    long top = st.top(); st.pop();
                    st.push(top * currentNum);
                } else if (op == '/') {
                    long top = st.top(); st.pop();
                    st.push(top / currentNum);  
                }

                op = c;
                currentNum = 0;
            }
        }

        long result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};

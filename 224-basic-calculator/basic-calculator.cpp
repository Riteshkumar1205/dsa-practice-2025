class Solution {
public:
    int calculate(string s) {
        long result = 0;
        long num = 0;
        int sign = 1;
        stack<long> st;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            }
            else if (c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            }
            else if (c == '(') {

                st.push(result);
                st.push(sign);
 
                result = 0;
                sign = 1;
            }
            else if (c == ')') {
                result += sign * num;
                num = 0;

                int prevSign = st.top(); st.pop();
                long prevResult = st.top(); st.pop();

                result = prevResult + prevSign * result;
            }
        }

        return result + sign * num;
    }
};

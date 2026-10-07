#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left_rem = 0, right_rem = 0;

        for (char ch : s) {
            if (ch == '(') {
                left_rem++;
            } else if (ch == ')') {
                if (left_rem > 0) {
                    left_rem--;
                } else {
                    right_rem++;
                }
            }
        }

        unordered_set<string> valid_strings;
        string current = "";
        dfs(0, 0, left_rem, right_rem, s, current, valid_strings);
        return vector<string>(valid_strings.begin(), valid_strings.end());
    }

private:
    void dfs(int index, int balance, int left_rem, int right_rem,
             const string& s, string& current, unordered_set<string>& result) {
        if (index == s.size()) {
            if (left_rem == 0 && right_rem == 0 && balance == 0) {
                result.insert(current);
            }
            return;
        }

        char ch = s[index];

        if (ch == '(' && left_rem > 0) {
            dfs(index + 1, balance, left_rem - 1, right_rem, s, current, result);
        } else if (ch == ')' && right_rem > 0) {
            dfs(index + 1, balance, left_rem, right_rem - 1, s, current, result);
        }

        current.push_back(ch);
        if (ch != '(' && ch != ')') {
            dfs(index + 1, balance, left_rem, right_rem, s, current, result);
        } else if (ch == '(') {
            dfs(index + 1, balance + 1, left_rem, right_rem, s, current, result);
        } else if (ch == ')' && balance > 0) {
            dfs(index + 1, balance - 1, left_rem, right_rem, s, current, result);
        }
        current.pop_back(); 
    }
};
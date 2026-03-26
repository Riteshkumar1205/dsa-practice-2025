#include<iostream>
#include<stack>
using namespace std;

class Solution {
    public:
     bool isValid(string sol) {
        stack<char> S;

        for(int i = 0; i < sol.length(); i++ ){
            char ch = sol[i];

            if(ch == '(' || ch == '{' || ch == '[') {
                S.push(ch);
            } 
            else {
                return false;
            }
        }
        return S.empty();
     }
};

int main() {

    Solution sol;

    string testCases[] = {
        "({[]})",   // valid (but your logic will return false)
        "()",       // valid
        "()[]{}",   // valid
        "(]",       // invalid
        "([)]",     // invalid
        "(((",      // invalid
        ")))",      // invalid
        "",         // valid
        "{[()]}",   // valid
        "{[(])}",   // invalid
        "abc",      // invalid
        "[",        // invalid
        "]"         // invalid
    };

    int n = sizeof(testCases)/sizeof(testCases[0]);

    for(int i = 0; i < n; i++) {
        cout << "Input: \"" << testCases[i] << "\" -> "
             << sol.isValid(testCases[i]) << endl;
    }

    return 0;
}

#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string s){
    stack<char> st;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            st.push('(');
        }
        else if(s[i] == ')'){
            if(st.empty()) return false; 
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    string s = "(())";
    cout << isBalanced(s) << endl; // prints 0 (false)
    return 0;
}

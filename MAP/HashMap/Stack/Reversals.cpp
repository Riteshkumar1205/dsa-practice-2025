#include<iostream>
#include<stack>
using namespace std;

int main() {
    string str = "Aspire India";

    stack<char> S;

    for(int i = 0; i < str.length(); i++){
        S.push(str[i]);
    }
    string ans = "";
    while(!S.empty()) {
        char ch = S.top();
        ans.push_back(ch);
        S.pop();
    }
    cout << " Reeversed String are:" << ans << endl;
    return 0;
}
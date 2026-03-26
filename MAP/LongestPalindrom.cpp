#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string LongestPalindrome(string S) {
        int n = S.size();
        int maxLength = 1, start = 0;

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && S[left] == S[right]) {
                if (right - left + 1 > maxLength) {
                    maxLength = right - left + 1;
                    start = left;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            expandAroundCenter(i, i);     
            expandAroundCenter(i, i + 1); 
        }

        return S.substr(start, maxLength);
    }
};

int main() {
    string s;
    cin >> s;   

    Solution obj;
    cout << obj.LongestPalindrome(s);

    return 0;
}

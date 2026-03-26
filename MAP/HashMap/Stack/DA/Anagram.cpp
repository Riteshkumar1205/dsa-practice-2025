/*
#include <iostream>
#include <vector>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length())
        return false;

    vector<int> freq(26, 0);

    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0)
            return false;
    }

    return true;
}

int main() {
    string s, t;
    cin >> s >> t;

    if (isAnagram(s, t))
        cout << "true";
    else
        cout << "false";

    return 0;
}
    */

    #include<iostream>
    using namespace std;

    class Solution {
        public:

        int countSubString(string s) {
            int n = s.length();
            int count = 0;


            for(int center = 0; center < n; center++) {
                //odd length 
                int left = center, right = center;
                while(left >= 0 && right < n && s[left] == s[right]) {
                    count++;
                    left--;
                    right++;
                }
                int left = center, right = center + 1;
                while(left >= 0 && right < n && s[left] == s[right]) {
                    count++;
                    left--;
                    right++;
                }
            }
            return count;
        }
    };
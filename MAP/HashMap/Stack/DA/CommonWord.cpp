#include <iostream>
#include<vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> freq;
        
        // Convert to lowercase and remove punctuation
        for (char &c : paragraph) {
            if (isalpha(c)) {
                c = tolower(c);
            } else {
                c = ' ';
            }
        }
        
        string word;
        string result;
        int maxCount = 0;
        
        // Extract words
        for (int i = 0; i <= paragraph.size(); i++) {
            if (i < paragraph.size() && paragraph[i] != ' ') {
                word += paragraph[i];
            } else {
                if (!word.empty() && bannedSet.find(word) == bannedSet.end()) {
                    freq[word]++;
                    //Red Hat Academy EC-Council certified ethical hacker (CEH) v12
                    if (freq[word] > maxCount) {
                        maxCount = freq[word];
                        result = word;
                    }
                }
                word.clear();
            }
        }
        
        return result;
    }
};
int main() {
    Solution sol;
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = {"hit"};

    cout << sol.mostCommonWord(paragraph, banned) << endl;

    return 0;
}
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<string> findUsers(vector<vector<string>>& logData, int threshold) {
    unordered_map<string,int> count;

    for(auto& log : logData) {
        string user1 = log[0];
        string user2 = log[1];

        //use set to avoid double counting of the same user
        unordered_set<string> uniqueUsers;
        uniqueUsers.insert(user1);
        uniqueUsers.insert(user2);

        for(auto& user : uniqueUsers) {
            count[user]++;
        }
    }
    vector<string> result;

    for(auto& entry : count) {
        if(entry.second >= threshold) {
            result.push_back(entry.first);
        }
    }
    sort(result.begin(), result.end());
    return result;
}
int main() {
    vector<vector<string>> logData = {
        {"345366","89921","45"},
        {"029323","38239","23"},
        {"38239","345366","15"},
        {"029323","38239","77"},
        {"345366","38239","23"},
        {"029323","345366","13"},
        {"38239","38239","23"}
    };
    vector<string> result = findUsers(logData, 2);
    for(auto& user : result) {
        cout << user << endl;
    }
    return 0;
}

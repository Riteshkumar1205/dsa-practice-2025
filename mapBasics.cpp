#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string, int> m;
    pair<string, int>p1;
    p1.first = "Ritesh";
    p1.second = 20;
    pair<string, int>p2;
    p2.first = "Rahul";
    p2.second = 22;

    m.insert(p1);
    m.insert(p2);

    for(pair<string, int> p : m) {
        cout << p.first << "  " << p.second << endl;
    }
}
#include<iostream>
#include<unordered_set>
using namespace std;

int main() {
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4); 
    s.insert(5);
    s.insert(3);

    s.erase(2);
    cout << s.size() << endl;

     int target = 3;
     if(s.find(target) != s.end()) {
        cout << "Exists" << endl;
     }
     else {
        cout << "Does not exist" << endl;
     }

    for (int x : s) {
        cout << x << " ";
    }
}
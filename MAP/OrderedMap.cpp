#include<iostream>
#include<set>
#include<map>
using namespace std;

int main() {
    /*set<int>s;
    s.insert(5);
    s.insert(3);

    for(int ele : s) {
        cout << ele << " ";
    */
   map<string,int>m;
   m["Raghav"] = 85;
   m["Aman"] = 40;
   m["Shubham"]=45;

   for(auto x : m) {
    cout << x.first << " ";
    cout << x.second << " " ;
   }
    
        
}
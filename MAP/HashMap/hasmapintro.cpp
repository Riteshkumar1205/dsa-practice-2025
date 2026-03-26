#include<iostream>
#include<unordered_map>
#include<string>
#include<map>
using namespace std;

int main(){
  map<string, int> m;
    
    // insertion

    pair<string, int> p1 = make_pair("Ritesh Kumar", 200);
    m.insert(p1);

    pair<string, int> p2("Rahul Kumar", 300);
    m.insert(p2);

    m["Rohit Kumar"] = 500;

  // search
 cout << m["Rohit Kumar"] << endl;
 cout << m.at("Rohit Kumar") << endl;

 cout << m["Rahul Kumar"] << endl;

 // erase

 m.erase("Rahul Kumar");
  cout << m.size() << endl;

  // iterator 

  map<string, int> :: iterator it = m.begin();

  while(it != m.end()) {
    cout << it->first << " " << it -> second << endl;
    it++;
  }

  return 0;
}
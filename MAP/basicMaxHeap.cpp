#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pq;
    pq.push(44);
    pq.push(46);
    pq.push(24);
    pq.push(-4);

    cout<<pq.top()<<endl;
   pq.pop();
    cout << pq.top() << endl;
}
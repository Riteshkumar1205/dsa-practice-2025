#include<iostream>
using namespace std;

//function prototyping
void A(int n);
void B(int n);




int main() {
    int a = 20;
    A(a);
    return 0;
}

void A(int n) {
    if(n > 0){
        cout << n << " ";
        B(n-1);
    }
}
 void B(int n){
    if(n > 1) {
        cout << n << " ";
        A(n/2);
    }
 }